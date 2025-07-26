#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>     // Pour cout, cerr
# include <fstream>      // Pour ifstream
# include <sstream>      // Pour stringstream
# include <string>       // Pour string
# include <map>          // Pour map
# include <cstdlib>      // Pour atof
# include <algorithm>    // Pour remove_if
# include <cctype>       // Pour isdigit, isspace

// Classe pour gérer les taux de change du Bitcoin
class BitcoinExchange
{
private:
    std::map<std::string, float> _database;    // Map stockant les paires date -> taux de change
    
    // Méthodes privées pour vérifier et manipuler les données
    bool isValidDate(const std::string& date) const;             // Vérifie si la date est valide
    bool isValidValue(const float value) const;                  // Vérifie si la valeur est valide
    std::string findClosestDate(const std::string& date) const;  // Trouve la date la plus proche
    
public:
    // Constructeurs et destructeur (forme canonique de Coplien)
    BitcoinExchange();                            // Constructeur par défaut
    BitcoinExchange(const std::string& filename); // Constructeur avec nom du fichier
    BitcoinExchange(const BitcoinExchange& src);  // Constructeur de copie
    ~BitcoinExchange();                           // Destructeur
    
    // Opérateur d'affectation (forme canonique de Coplien)
    BitcoinExchange& operator=(const BitcoinExchange& rhs);
    
    // Méthodes publiques pour traiter les fichiers et obtenir les taux
    void processInputFile(const std::string& filename);  // Traite le fichier d'entrée
    float getRate(const std::string& date) const;        // Obtient le taux pour une date
    
    // Classes d'exceptions pour la gestion des erreurs
    class FileOpenError : public std::exception 
    {   // Exception pour erreur d'ouverture de fichier
        public:
            virtual const char* what() const throw() 
            {
                return "Error: could not open file.";
            }
    };
    
    class InvalidDateError : public std::exception 
    {   // Exception pour date invalide
        public:
            virtual const char* what() const throw() 
            {
                return "Error: bad input => ";
            }
    };
    
    class NegativeValueError : public std::exception 
    {   // Exception pour valeur négative
        public:
            virtual const char* what() const throw() 
            {
                return "Error: not a positive number.";
            }
    };
    
    class TooLargeValueError : public std::exception 
    {   // Exception pour valeur trop grande
        public:
            virtual const char* what() const throw() 
            {
                return "Error: too large a number.";
            }
    };
};

#endif