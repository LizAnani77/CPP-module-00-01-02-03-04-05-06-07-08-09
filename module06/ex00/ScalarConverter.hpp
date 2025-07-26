#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>   // Pour les flux d'entrée/sortie
# include <string>     // Pour la manipulation des chaînes de caractères
# include <cstdlib>    // Pour les fonctions atoi, atof
# include <limits>     // Pour accéder aux limites numériques (numeric_limits)
# include <cmath>      // Pour les fonctions isnan, isinf
# include <iomanip>    // Pour les manipulateurs de flux (fixed, setprecision)

class ScalarConverter
{
private:
    // Type d'entrée détecté - Énumération des types de littéraux reconnus
    enum Type
    {
        CHAR,       // Caractère (ex: 'c', 'a')
        INT,        // Entier (ex: 0, -42, 42)
        FLOAT,      // Nombre à virgule flottante simple précision (ex: 0.0f, -4.2f)
        DOUBLE,     // Nombre à virgule flottante double précision (ex: 0.0, -4.2)
        PSEUDO_LIT, // Littéral spécial (ex: nan, inf, -inf)
        ERROR       // Entrée non reconnue
    };

    // Constructeur par défaut - privé pour empêcher l'instanciation
    // Cette classe est conçue comme une classe utilitaire statique
    ScalarConverter();
    
    // Constructeur de copie - privé pour empêcher l'instanciation
    ScalarConverter(const ScalarConverter &src);
    
    // Opérateur d'affectation - privé pour empêcher l'instanciation
    ScalarConverter &operator=(const ScalarConverter &rhs);
    
    // Méthodes utilitaires privées pour la détection et conversion
    // Analyse la chaîne et détermine son type selon l'énumération Type
    static Type detectType(const std::string &str);
    
    // Vérifie si la chaîne représente un caractère (un seul caractère ou entre guillemets simples)
    static bool isChar(const std::string &str);
    
    // Vérifie si la chaîne représente un entier (série de chiffres avec éventuel signe)
    static bool isInt(const std::string &str);
    
    // Vérifie si la chaîne représente un float (nombre avec point décimal et 'f' à la fin)
    static bool isFloat(const std::string &str);
    
    // Vérifie si la chaîne représente un double (nombre avec point décimal sans 'f')
    static bool isDouble(const std::string &str);
    
    // Vérifie si la chaîne est un littéral spécial (nan, inf, -inf, etc.)
    static bool isPseudoLiteral(const std::string &str);

public:
    // Destructeur
    ~ScalarConverter();
    
    // Méthode statique publique pour la conversion
    // Convertit la chaîne donnée vers char, int, float et double et affiche les résultats
    static void convert(const std::string &str);
    
    // Classes d'exception pour la gestion d'erreurs
    class ConversionImpossibleException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class NonDisplayableException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

#endif