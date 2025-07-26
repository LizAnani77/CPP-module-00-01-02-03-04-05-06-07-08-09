#include "ScalarConverter.hpp"
#include <iostream>

// Affiche un séparateur visuel pour améliorer la lisibilité de la sortie
// Permet de distinguer clairement différentes sections des tests
void printSeparator(const std::string &title)
{
    std::cout << "\n";
    std::cout << "===============================================" << std::endl;
    std::cout << title << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "\n";
}

// Teste la conversion avec différents types de valeurs
// Utilise des cas de test variés pour valider toutes les fonctionnalités du ScalarConverter
void testConversions()
{
    // Test de conversion pour un caractère
    // Vérifie que le convertisseur peut correctement traiter un caractère
    printSeparator("TEST WITH A CHARACTER");
    std::cout << "----- Converting character 'c' -----" << std::endl;
    ScalarConverter::convert("c");

    // Test de conversion pour un entier
    // Vérifie que le convertisseur peut correctement traiter un entier positif
    printSeparator("TEST WITH AN INTEGER");
    std::cout << "----- Converting integer 42 -----" << std::endl;
    ScalarConverter::convert("42");

    // Test de conversion pour un entier négatif
    // Vérifie que le convertisseur peut correctement traiter un entier négatif
    std::cout << "\n----- Converting negative integer -42 -----" << std::endl;
    ScalarConverter::convert("-42");

    // Test de conversion pour un float
    // Vérifie que le convertisseur peut correctement traiter un float positif
    printSeparator("TEST WITH A FLOAT");
    std::cout << "----- Converting float 42.0f -----" << std::endl;
    ScalarConverter::convert("42.0f");

    // Test de conversion pour un float négatif
    // Vérifie que le convertisseur peut correctement traiter un float négatif
    std::cout << "\n----- Converting negative float -42.5f -----" << std::endl;
    ScalarConverter::convert("-42.5f");

    // Test de conversion pour un double
    // Vérifie que le convertisseur peut correctement traiter un double positif
    printSeparator("TEST WITH A DOUBLE");
    std::cout << "----- Converting double 42.5 -----" << std::endl;
    ScalarConverter::convert("42.5");

    // Test de conversion pour un double négatif
    // Vérifie que le convertisseur peut correctement traiter un double négatif
    std::cout << "\n----- Converting negative double -42.75 -----" << std::endl;
    ScalarConverter::convert("-42.75");

    // Test avec des valeurs spéciales
    // Vérifie que le convertisseur peut gérer correctement les valeurs spéciales comme NaN et Inf
    printSeparator("TEST WITH SPECIAL VALUES");
    std::cout << "----- Converting nanf -----" << std::endl;
    ScalarConverter::convert("nanf");

    std::cout << "\n----- Converting +inff -----" << std::endl;
    ScalarConverter::convert("+inff");

    std::cout << "\n----- Converting -inff -----" << std::endl;
    ScalarConverter::convert("-inff");

    std::cout << "\n----- Converting nan -----" << std::endl;
    ScalarConverter::convert("nan");

    std::cout << "\n----- Converting +inf -----" << std::endl;
    ScalarConverter::convert("+inf");

    std::cout << "\n----- Converting -inf -----" << std::endl;
    ScalarConverter::convert("-inf");

    // Test avec des valeurs limites
    // Vérifie les cas particuliers comme zéro et caractères non affichables
    printSeparator("TEST WITH EDGE CASES");
    std::cout << "----- Converting 0 -----" << std::endl;
    ScalarConverter::convert("0");

    std::cout << "\n----- Converting non-displayable character (ASCII 0) -----" << std::endl;
    ScalarConverter::convert("\0");

    // Test avec une entrée invalide
    // Vérifie que le convertisseur gère correctement les entrées qui ne correspondent à aucun type
    printSeparator("TEST WITH INVALID INPUT");
    std::cout << "----- Converting invalid string -----" << std::endl;
    ScalarConverter::convert("bonjour");
}

// Fonction principale
// Point d'entrée du programme qui permet soit de tester avec un argument fourni,
// soit d'exécuter une série de tests prédéfinis
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <value_to_convert>" << std::endl;
        std::cout << "Running built-in tests..." << std::endl;
        testConversions();
    }
    else
    {
        // Si un argument est fourni, convertir uniquement cet argument
        ScalarConverter::convert(argv[1]);
    }

    return 0;
}