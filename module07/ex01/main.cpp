#include "iter.hpp"       // Notre fonction template iter
#include <iostream>       // Pour std::cout, std::endl
#include <string>         // Pour std::string

// Affiche un séparateur visuel pour améliorer la lisibilité de la sortie
void printSeparator(const std::string &title)
{
    std::cout << "\n";                                                      // Ligne vide pour l'espacement
    std::cout << "===============================================" << std::endl;   // Ligne supérieure
    std::cout << title << std::endl;                                        // Titre du séparateur
    std::cout << "===============================================" << std::endl;   // Ligne inférieure
    std::cout << "\n";                                                      // Ligne vide pour l'espacement
}

// Fonction pour afficher un élément de type int
void printInt(int n)
{
    std::cout << n << " ";       // Affiche l'entier suivi d'un espace
}

// Fonction pour afficher un élément de type float
void printFloat(float f)
{
    std::cout << f << " ";       // Affiche le flottant suivi d'un espace
}

// Fonction pour afficher un élément de type string
void printString(const std::string &s)
{
    std::cout << s << " ";       // Affiche la chaîne suivie d'un espace
}

// Fonction template qui double la valeur de l'élément
template <typename T>
void doubleValue(T &value)
{
    value *= 2;                 // Multiplie la valeur par 2
}

// Fonction template qui affiche n'importe quel type (si compatible avec <<)
template <typename T>
void printElement(const T &element)
{
    std::cout << element << " ";  // Affiche l'élément suivi d'un espace
}

int main()
{
    std::cout << "===============================================" << std::endl;
    std::cout << "============== ITER FUNCTION TESTS ============" << std::endl;
    std::cout << "===============================================" << std::endl;

    // Test avec un tableau d'entiers
    printSeparator("INTEGER ARRAY TEST");
    int intArray[] = {1, 2, 3, 4, 5};    // Initialise un tableau d'entiers
    size_t intLength = 5;                // Taille du tableau
    
    std::cout << "Original integers: ";
    ::iter(intArray, intLength, printInt);  // Affiche tous les entiers
    std::cout << std::endl;
    
    ::iter(intArray, intLength, doubleValue<int>);  // Double chaque entier
    
    std::cout << "After doubling: ";
    ::iter(intArray, intLength, printInt);  // Affiche les entiers après modification
    std::cout << std::endl;

    // Test avec un tableau de flottants
    printSeparator("FLOAT ARRAY TEST");
    float floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};  // Initialise un tableau de flottants
    size_t floatLength = 5;                              // Taille du tableau
    
    std::cout << "Original floats: ";
    ::iter(floatArray, floatLength, printFloat);  // Affiche tous les flottants
    std::cout << std::endl;
    
    ::iter(floatArray, floatLength, doubleValue<float>);  // Double chaque flottant
    
    std::cout << "After doubling: ";
    ::iter(floatArray, floatLength, printFloat);  // Affiche les flottants après modification
    std::cout << std::endl;

    // Test avec un tableau de chaînes
    printSeparator("STRING ARRAY TEST");
    std::string stringArray[] = {"Hello", "World", "42", "is", "cool"};  // Initialise un tableau de chaînes
    size_t stringLength = 5;                                            // Taille du tableau
    
    std::cout << "Strings: ";
    ::iter(stringArray, stringLength, printString);  // Affiche toutes les chaînes
    std::cout << std::endl;

    // Test avec une fonction template en tant que 3ème paramètre
    printSeparator("TEMPLATE FUNCTION PARAMETER TEST");
    std::cout << "Using template function with integers: ";
    ::iter(intArray, intLength, printElement<int>);  // Utilise printElement pour afficher les entiers
    std::cout << std::endl;
    
    std::cout << "Using template function with floats: ";
    ::iter(floatArray, floatLength, printElement<float>);  // Utilise printElement pour afficher les flottants
    std::cout << std::endl;
    
    std::cout << "Using template function with strings: ";
    ::iter(stringArray, stringLength, printElement<std::string>);  // Utilise printElement pour afficher les chaînes
    std::cout << std::endl;

    std::cout << "\n===============================================" << std::endl;
    std::cout << "============= TESTS COMPLETED =================" << std::endl;
    std::cout << "===============================================" << std::endl;

    return 0;
}