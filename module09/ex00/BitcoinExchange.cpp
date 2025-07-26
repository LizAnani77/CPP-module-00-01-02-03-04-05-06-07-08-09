#include "BitcoinExchange.hpp"

// Constructeur par défaut - initialise la base de données vide
BitcoinExchange::BitcoinExchange()
{
    // La map _database est initialisée par défaut
}

// Constructeur avec fichier - charge la base de données depuis le fichier CSV
BitcoinExchange::BitcoinExchange(const std::string& filename)
{
    std::ifstream file(filename.c_str());           // Ouvre le fichier CSV
    if (!file.is_open())                            // Vérifie si le fichier est ouvert
        throw FileOpenError();                      // Lance une exception si le fichier n'est pas ouvert
    
    std::string line;                               // Stocke chaque ligne lue
    std::getline(file, line);                       // Ignorer la première ligne (en-tête)
    
    while (std::getline(file, line))                // Parcourt chaque ligne du fichier
    {
        std::stringstream ss(line);                 // Crée un stream pour parser la ligne
        std::string date;                           // Stocke la date
        std::string value;                          // Stocke la valeur
        
        if (std::getline(ss, date, ',') && std::getline(ss, value)) // Extrait la date et la valeur
        {
            // Supprime les espaces de la date et de la valeur
            date.erase(remove_if(date.begin(), date.end(), isspace), date.end());
            value.erase(remove_if(value.begin(), value.end(), isspace), value.end());
            
            if (isValidDate(date))                     // Vérifie si la date est valide
            {
                float rate = std::atof(value.c_str()); // Convertit la valeur en float
                _database[date] = rate;                // Ajoute la paire date-taux à la map
            }
        }
    }
    
    file.close();                                      // Ferme le fichier
}

// Constructeur de copie - crée une copie de l'objet source
BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
{
    *this = src;                                       // Utilise l'opérateur d'affectation
}

// Destructeur - nettoie les ressources
BitcoinExchange::~BitcoinExchange()
{
    // Pas de mémoire dynamique à libérer
}

// Opérateur d'affectation - copie les données de l'objet source
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
    if (this != &rhs)                             // Vérifie l'auto-assignation
    {
        _database = rhs._database;                // Copie la map de données
    }
    return *this;                                 // Retourne une référence sur this
}

// Vérifie si la date est valide (format YYYY-MM-DD)
bool BitcoinExchange::isValidDate(const std::string& date) const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') // Vérifie le format de base
        return false;
    
    for (size_t i = 0; i < date.length(); ++i)    // Vérifie chaque caractère
    {
        if (i == 4 || i == 7)                     // Ignore les tirets
            continue;
        if (!isdigit(date[i]))                    // Vérifie que les autres caractères sont des chiffres
            return false;
    }
    
    int year = std::atoi(date.substr(0, 4).c_str());    // Extrait l'année
    int month = std::atoi(date.substr(5, 2).c_str());   // Extrait le mois
    int day = std::atoi(date.substr(8, 2).c_str());     // Extrait le jour
    
    if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31) // Vérifie les plages
        return false;
    
    // Vérifie les mois de 30 jours
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;
    
    // Vérifie février et les années bissextiles
    if (month == 2)
    {
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (isLeapYear ? 29 : 28))
            return false;
    }
    
    return true;                                  // Retourne vrai si tous les tests sont passés
}

// Vérifie si la valeur est valide (entre 0 et 1000)
bool BitcoinExchange::isValidValue(const float value) const
{
    return (value >= 0 && value <= 1000);         // Retourne vrai si la valeur est dans la plage
}

// Trouve la date précédente la plus proche dans la base de données
std::string BitcoinExchange::findClosestDate(const std::string& date) const
{
    std::map<std::string, float>::const_iterator it = _database.lower_bound(date); // Cherche la date ou la suivante
    
    // Si la date exacte est trouvée
    if (it != _database.end() && it->first == date)
        return it->first;                         // Retourne la date exacte trouvée
    
    // Si aucune date n'est trouvée ou si la date est avant la première date de la base
    if (it == _database.begin() || it == _database.end())
    {
        if (it == _database.end() && !_database.empty())
            return (--it)->first;                 // Retourne la dernière date si date > toutes les dates
        if (it == _database.begin() && date < it->first)
            return "";                            // Pas de date antérieure trouvée
        return it->first;                         // Retourne la première date
    } 
    // Sinon, retourne la date précédente
    --it;                                         // Recule l'itérateur pour avoir la date précédente
    return it->first;                             // Retourne cette date
}

// Traite le fichier d'entrée contenant les requêtes
void BitcoinExchange::processInputFile(const std::string& filename)
{
    std::ifstream file(filename.c_str());         // Ouvre le fichier d'entrée
    if (!file.is_open())                          // Vérifie si le fichier est ouvert
        throw FileOpenError();                    // Lance une exception si le fichier n'est pas ouvert
    
    std::string line;                             // Stocke chaque ligne lue
    std::getline(file, line);                     // Ignorer la première ligne (en-tête)
    
    while (std::getline(file, line))              // Parcourt chaque ligne du fichier
    {
        // Rechercher d'abord un pipe
        size_t separatorPos = line.find('|');     // Cherche la position du séparateur '|'
        
        // Si pas de pipe, essayer avec une virgule
        if (separatorPos == std::string::npos) 
        {  // Si le pipe n'est pas trouvé
            separatorPos = line.find(',');        // Cherche la position d'une virgule
            
            // Si ni pipe ni virgule, erreur
            if (separatorPos == std::string::npos) 
            {  
                // Si aucun séparateur n'est trouvé
                std::cout << "Error: bad input => " << line << std::endl;  // Affiche une erreur
                continue;                         // Passe à la ligne suivante
            }
        }
        
        std::string dateStr = line.substr(0, separatorPos);      // Extrait la partie date
        std::string valueStr = line.substr(separatorPos + 1);    // Extrait la partie valeur
        
        // Supprime les espaces de la date et de la valeur
        dateStr.erase(remove_if(dateStr.begin(), dateStr.end(), isspace), dateStr.end());     // Supprime les espaces de la date
        valueStr.erase(remove_if(valueStr.begin(), valueStr.end(), isspace), valueStr.end()); // Supprime les espaces de la valeur
        
        // Vérifie la validité de la date
        if (!isValidDate(dateStr))                // Si la date n'est pas valide
        {
            std::cout << "Error: bad input => " << dateStr << std::endl;  // Affiche une erreur
            continue;                             // Passe à la ligne suivante
        }
        
        // Vérifie la validité de la valeur
        float value;                              // Stocke la valeur convertie
        try
        {
            value = std::atof(valueStr.c_str());  // Convertit la chaîne en float
        }
        catch (const std::exception& e)           // Capture les exceptions
        {
            std::cout << "Error: bad input => " << valueStr << std::endl;  // Affiche une erreur
            continue;                             // Passe à la ligne suivante
        }
        
        if (value < 0)                            // Vérifie si la valeur est négative
        {
            std::cout << "Error: not a positive number." << std::endl;  // Affiche une erreur
            continue;                             // Passe à la ligne suivante
        }
        
        if (value > 1000)                         // Vérifie si la valeur est trop grande
        {
            std::cout << "Error: too large a number." << std::endl;  // Affiche une erreur
            continue;                             // Passe à la ligne suivante
        }
        
        // Obtient le taux de change pour cette date
        float exchangeRate = getRate(dateStr);    // Récupère le taux de change
        
        // Affiche le résultat
        std::cout << dateStr << " => " << value << " = " << (value * exchangeRate) << std::endl;  // Affiche le résultat du calcul
    }
    
    file.close();                                 // Ferme le fichier
}

// Obtient le taux de change pour une date donnée
float BitcoinExchange::getRate(const std::string& date) const
{
    // Si la date existe dans la base de données
    std::map<std::string, float>::const_iterator it = _database.find(date); // Cherche la date exacte
    if (it != _database.end())                     // Si trouvée
        return it->second;                         // Retourne le taux correspondant
    
    // Sinon, trouve la date la plus proche
    std::string closestDate = findClosestDate(date); // Trouve la date la plus proche
    if (closestDate.empty())                         // Si aucune date proche n'est trouvée
        return 0.0f;                                 // Retourne 0 comme taux par défaut
    
    return _database.at(closestDate);                // Retourne le taux pour la date la plus proche
}