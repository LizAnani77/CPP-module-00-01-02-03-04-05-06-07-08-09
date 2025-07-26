#include "whatever.hpp"    // Nos fonctions template swap, min, max
#include <iostream>        // Pour std::cout, std::endl
#include <string>          // Pour std::string

// Affiche un séparateur visuel pour améliorer la lisibilité de la sortie
void printSeparator(const std::string &title)
{
    std::cout << "\n";                                                      // Ligne vide pour l'espacement
    std::cout << "===============================================" << std::endl;   // Ligne supérieure
    std::cout << title << std::endl;                                        // Titre du séparateur
    std::cout << "===============================================" << std::endl;   // Ligne inférieure
    std::cout << "\n";                                                      // Ligne vide pour l'espacement
}

int main(void)
{
    std::cout << "===============================================" << std::endl;
    std::cout << "========== TEMPLATE FUNCTIONS TESTS ===========" << std::endl;
    std::cout << "===============================================" << std::endl;

    // Test avec des entiers (int)
    printSeparator("INTEGER TESTS");
    int a = 2;                  // Initialise a avec la valeur 2
    int b = 3;                  // Initialise b avec la valeur 3
    
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);               // Appel de notre fonction template swap avec des entiers
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
    
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;    // Affiche le minimum entre a et b
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;    // Affiche le maximum entre a et b

    // Test avec des chaînes de caractères (string)
    printSeparator("STRING TESTS");
    std::string c = "chaine1";     // Initialise c avec la valeur "chaine1"
    std::string d = "chaine2";     // Initialise d avec la valeur "chaine2"
    
    std::cout << "Before swap: c = " << c << ", d = " << d << std::endl;
    ::swap(c, d);                  // Appel de notre fonction template swap avec des strings
    std::cout << "After swap: c = " << c << ", d = " << d << std::endl;
    
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;    // Affiche le minimum entre c et d
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;    // Affiche le maximum entre c et d

    // Test avec des flottants (float)
    printSeparator("FLOAT TESTS");
    float e = 42.42f;              // Initialise e avec la valeur 42.42
    float f = 21.21f;              // Initialise f avec la valeur 21.21
    
    std::cout << "Before swap: e = " << e << ", f = " << f << std::endl;
    ::swap(e, f);                  // Appel de notre fonction template swap avec des flottants
    std::cout << "After swap: e = " << e << ", f = " << f << std::endl;
    
    std::cout << "min(e, f) = " << ::min(e, f) << std::endl;    // Affiche le minimum entre e et f
    std::cout << "max(e, f) = " << ::max(e, f) << std::endl;    // Affiche le maximum entre e et f

    // Test avec des valeurs égales
    printSeparator("EQUAL VALUES TESTS");
    int g = 42;                    // Initialise g avec la valeur 42
    int h = 42;                    // Initialise h avec la valeur 42 (égale à g)
    
    std::cout << "Values: g = " << g << ", h = " << h << std::endl;
    std::cout << "min(g, h) = " << ::min(g, h) << " (should be second arg)" << std::endl;
    std::cout << "max(g, h) = " << ::max(g, h) << " (should be second arg)" << std::endl;
    
    // Vérification de l'adresse retournée (pour confirmer que c'est bien le second argument)
    std::cout << "Address of g: " << &g << std::endl;
    std::cout << "Address of h: " << &h << std::endl;
    std::cout << "Address of min(g, h): " << &(::min(g, h)) << std::endl;
    std::cout << "Address of max(g, h): " << &(::max(g, h)) << std::endl;

    std::cout << "\n===============================================" << std::endl;
    std::cout << "============= TESTS COMPLETED =================" << std::endl;
    std::cout << "===============================================" << std::endl;

    return 0;
}