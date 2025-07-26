#include "Span.hpp"
#include <iostream>         // Pour cout, endl
#include <ctime>            // Pour time()
#include <cstdlib>          // Pour srand(), rand()
#include <list>             // Pour tester addRange avec std::list

// Affiche un séparateur visuel pour améliorer la lisibilité de la sortie
void printSeparator(const std::string &title)
{
    std::cout << "\n";
    std::cout << "===============================================" << std::endl;
    std::cout << title << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "\n";
}

int main()
{
    std::cout << "===============================================" << std::endl;
    std::cout << "=========== SPAN TESTS =======================" << std::endl;
    std::cout << "===============================================" << std::endl;

    // Test basique du sujet
    printSeparator("BASIC TEST (SUBJECT EXAMPLE)");
    Span sp = Span(5);            // Crée un Span pouvant contenir 5 entiers
    
    sp.addNumber(6);              // Ajoute l'entier 6
    sp.addNumber(3);              // Ajoute l'entier 3
    sp.addNumber(17);             // Ajoute l'entier 17
    sp.addNumber(9);              // Ajoute l'entier 9
    sp.addNumber(11);             // Ajoute l'entier 11
    
    // Calcule et affiche le plus petit écart (devrait être 2, entre 9 et 11)
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    // Calcule et affiche le plus grand écart (devrait être 14, entre 3 et 17)
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    // Test avec un grand nombre d'éléments (10000)
    printSeparator("LARGE TEST (10000 NUMBERS)");
    Span largeSpan = Span(10000);  // Crée un Span pouvant contenir 10000 entiers
    
    srand(time(NULL));             // Initialise le générateur de nombres aléatoires
    for (int i = 0; i < 10000; ++i)
        largeSpan.addNumber(rand() % 100000);  // Ajoute 10000 nombres aléatoires entre 0 et 99999
    
    // Calcule et affiche le plus petit écart
    std::cout << "Shortest span: " << largeSpan.shortestSpan() << std::endl;
    // Calcule et affiche le plus grand écart
    std::cout << "Longest span: " << largeSpan.longestSpan() << std::endl;

    // Test avec addRange
    printSeparator("ADD RANGE TEST");
    std::list<int> numbersList;    // Crée une liste d'entiers
    for (int i = 0; i < 100; ++i)
        numbersList.push_back(i * 10);  // Remplit la liste avec des multiples de 10 (0, 10, 20, ...)
    
    Span rangeSpan = Span(100);    // Crée un Span pouvant contenir 100 entiers
    // Ajoute tous les éléments de la liste en une seule fois
    rangeSpan.addRange(numbersList.begin(), numbersList.end());
    
    // Calcule et affiche le plus petit écart (devrait être 10)
    std::cout << "Shortest span: " << rangeSpan.shortestSpan() << std::endl;
    // Calcule et affiche le plus grand écart (devrait être 990)
    std::cout << "Longest span: " << rangeSpan.longestSpan() << std::endl;

    // Test des exceptions
    printSeparator("EXCEPTION TESTS");
    
    // Test d'ajout sur un Span plein
    try 
    {
        Span fullSpan = Span(3);    // Crée un Span avec capacité 3
        fullSpan.addNumber(1);      // Ajoute le premier entier
        fullSpan.addNumber(2);      // Ajoute le deuxième entier
        fullSpan.addNumber(3);      // Ajoute le troisième entier (remplit le Span)
        std::cout << "Added 3 numbers to a Span of size 3" << std::endl;
        fullSpan.addNumber(4);      // Tente d'ajouter un quatrième entier (devrait lancer une exception)
    } 
    catch (std::exception &e) 
    {
        // Capture et affiche l'exception attendue
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    // Test de recherche d'écart avec un seul nombre
    try 
    {
        Span singleSpan = Span(5);   // Crée un Span avec capacité 5
        singleSpan.addNumber(42);    // Ajoute un seul entier
        std::cout << "Added 1 number to Span" << std::endl;
        singleSpan.shortestSpan();   // Tente de calculer le plus petit écart (devrait lancer une exception)
    } 
    catch (std::exception &e) 
    {
        // Capture et affiche l'exception attendue
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    // Test de recherche d'écart avec aucun nombre
    try
    {
        Span emptySpan = Span(5);    // Crée un Span vide avec capacité 5
        std::cout << "Created empty Span" << std::endl;
        emptySpan.longestSpan();     // Tente de calculer le plus grand écart (devrait lancer une exception)
    } 
    catch (std::exception &e) 
    {
        // Capture et affiche l'exception attendue
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Pied de page indiquant la fin des tests
    std::cout << "\n===============================================" << std::endl;
    std::cout << "============= TESTS COMPLETED =================" << std::endl;
    std::cout << "===============================================" << std::endl;

    return 0;  // Retourne 0 pour indiquer une exécution réussie
}