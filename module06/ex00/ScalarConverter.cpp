#include "ScalarConverter.hpp"

// Constructeur par défaut - utilisé uniquement en interne
// La classe ne devant pas être instanciée, le constructeur est privé et vide
ScalarConverter::ScalarConverter()
{
    // Vide - ne pas afficher de message car la classe n'est jamais instanciée
}

// Constructeur de copie - utilisé uniquement en interne
// Même raison que pour le constructeur par défaut
ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
    // Vide - éviter les warnings du compilateur
    (void)src;
}

// Opérateur d'affectation - utilisé uniquement en interne
// Même raison que pour les constructeurs
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
    // Vide - éviter les warnings du compilateur
    (void)rhs;
    return *this;
}

// Destructeur
// Il n'y a rien à libérer car la classe est statique et non instanciable
ScalarConverter::~ScalarConverter()
{
    // Vide - ne pas afficher de message car la classe n'est jamais instanciée
}

// Message d'erreur pour l'exception ConversionImpossibleException
// Retourne le message indiquant que la conversion est impossible
const char *ScalarConverter::ConversionImpossibleException::what() const throw()
{
    return "impossible";
}

// Message d'erreur pour l'exception NonDisplayableException
// Retourne le message indiquant que le caractère n'est pas affichable
const char *ScalarConverter::NonDisplayableException::what() const throw()
{
    return "Non displayable";
}

// Détecte le type de la chaîne d'entrée
// Analyse la chaîne et détermine son type en utilisant des méthodes spécialisées
ScalarConverter::Type ScalarConverter::detectType(const std::string &str)
{
    if (isChar(str))
        return CHAR;
    else if (isInt(str))
        return INT;
    else if (isFloat(str))
        return FLOAT;
    else if (isDouble(str))
        return DOUBLE;
    else if (isPseudoLiteral(str))
        return PSEUDO_LIT;
    else
        return ERROR;
} 

// Vérifie si la chaîne est un caractère
// Un caractère est soit un caractère unique, soit un caractère entre guillemets simples
bool ScalarConverter::isChar(const std::string &str)
{
    return (str.length() == 1 && !isdigit(str[0])) ||
           (str.length() == 3 && str[0] == '\'' && str[2] == '\'');
}

// Vérifie si la chaîne est un entier
// Un entier est une séquence de chiffres avec un signe optionnel
bool ScalarConverter::isInt(const std::string &str)
{
    std::string::size_type i = 0;
    
    if (str[i] == '+' || str[i] == '-')
        i++;
    
    while (i < str.length() && isdigit(str[i]))
        i++;
        
    return i == str.length() && i > 0;
}

// Vérifie si la chaîne est un float
// Un float est un nombre à virgule flottante avec un 'f' à la fin, ou un littéral spécial float
bool ScalarConverter::isFloat(const std::string &str)
{
    // Vérifie d'abord les cas spéciaux: littéraux flottants
    if (str == "nanf" || str == "+inff" || str == "-inff")
        return true;
    
    std::string::size_type i = 0;
    // Variable qui indique si on a déjà rencontré un point décimal
    bool point = false; 
    
    // Vérifie si le premier caractère est un signe + ou -
    if (str[i] == '+' || str[i] == '-')
        i++;
    
    // Parcours de la chaîne caractère par caractère
    while (i < str.length())
    {
        // Si on trouve un point décimal
        if (str[i] == '.') 
        {
            // Si on a déjà trouvé un point auparavant
            if (point)
                // Alors ce n'est pas un float valide (deux points)
                return false;
            // Sinon, marquer qu'on a trouvé un point
            point = true;  
        }
         // Si on trouve un 'f' à la fin
        else if (str[i] == 'f' && i == str.length() - 1)
            // C'est un float uniquement si on a aussi vu un point
            return point;
        // Si le caractère n'est ni un chiffre, ni '.' ni 'f'
        else if (!isdigit(str[i]))
             // Alors ce n'est pas un float valide
            return false;
        i++;
    }   
    // Si on arrive ici, ça signifie qu'on n'a pas trouvé de 'f' à la fin
    return false;
}

// Vérifie si la chaîne est un double
// Un double est un nombre à virgule flottante sans 'f' à la fin, ou un littéral spécial double
bool ScalarConverter::isDouble(const std::string &str)
{
    // Vérifie d'abord les cas spéciaux: littéraux flottants
    if (str == "nan" || str == "+inf" || str == "-inf")
        return true;
    
    std::string::size_type i = 0;
    // Variable qui indique si on a déjà rencontré un point décimal
    bool point = false;
    
    // Vérifie si le premier caractère est un signe + ou -
    if (str[i] == '+' || str[i] == '-')
        i++;
    
    // Parcours de la chaîne caractère par caractère
    while (i < str.length())
    {
        // Si on trouve un point décimal
        if (str[i] == '.')
        {
            // Si on a déjà trouvé un point auparavant
            if (point)
                // Alors ce n'est pas un double valide (deux points)
                return false;
            // Sinon, marquer qu'on a trouvé un point
            point = true;
        }
        // Si le caractère n'est ni un chiffre
        else if (!isdigit(str[i]))
            return false;
        i++;
    }
    
    return point;
}

// Vérifie si la chaîne est un littéral pseudo
// Les littéraux pseudo sont des valeurs spéciales comme nan, inf, etc.
bool ScalarConverter::isPseudoLiteral(const std::string &str)
{
    return (str == "nan" || str == "+inf" || str == "-inf" ||
            str == "nanf" || str == "+inff" || str == "-inff");
}

// Méthode principale de conversion
// Convertit la chaîne d'entrée en char, int, float et double et affiche les résultats
void ScalarConverter::convert(const std::string &str)
{
    Type type = detectType(str);
    char c;
    int i;
    float f;
    double d;
    
    // Extraction de la valeur en fonction du type détecté
    try
    {
        switch (type)
        {
            case CHAR:
                if (str.length() == 1)
                    c = str[0];
                else
                    // Si entre guillemets simples
                    c = str[1]; 
                i = static_cast<int>(c);
                f = static_cast<float>(c);
                d = static_cast<double>(c);
                break;
                
            case INT:
                i = std::atoi(str.c_str());
                c = static_cast<char>(i);
                f = static_cast<float>(i);
                d = static_cast<double>(i);
                break;
                
            case FLOAT:
                f = std::atof(str.c_str());
                c = static_cast<char>(f);
                i = static_cast<int>(f);
                d = static_cast<double>(f);
                break;
            // Cas des nombres à virgule flottante double et des pseudo-littéraux (nan, inf)
            // On utilise atof pour convertir la chaîne en double, puis on effectue les conversions
            // vers les autres types scalaires avec static_cast (ces conversions peuvent échouer pour NaN/inf)   
            case DOUBLE:
            case PSEUDO_LIT:
                d = std::atof(str.c_str());
                c = static_cast<char>(d);
                i = static_cast<int>(d);
                f = static_cast<float>(d);
                break;
                
            default:
                throw ConversionImpossibleException();
        }
        
        // Affichage des conversions
        // Conversion en char
        std::cout << "char: ";
        if (std::isnan(d) || std::isinf(d) || i < 0 || i > 127)
            std::cout << "impossible" << std::endl;
        else if (!std::isprint(c))
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "'" << c << "'" << std::endl;
        
        // Conversion en int
        std::cout << "int: ";
        if (std::isnan(d) || std::isinf(d) || d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
            std::cout << "impossible" << std::endl;
        else
            std::cout << i << std::endl;
        
        // Conversion en float avec précision fixe
        std::cout << "float: ";
        if (std::isnan(f))
            std::cout << "nanf" << std::endl;
        else if (std::isinf(f) && f > 0)
            std::cout << "+inff" << std::endl;
        else if (std::isinf(f) && f < 0)
            std::cout << "-inff" << std::endl;
        else
            std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        
        // Conversion en double avec précision fixe
        std::cout << "double: ";
        if (std::isnan(d))
            std::cout << "nan" << std::endl;
        else if (std::isinf(d) && d > 0)
            std::cout << "+inf" << std::endl;
        else if (std::isinf(d) && d < 0)
            std::cout << "-inf" << std::endl;
        else
            std::cout << std::fixed << std::setprecision(1) << d << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}