#include "easyfind.hpp"
#include <iostream>            // Pour cout, endl
#include <vector>              // Container vector
#include <list>                // Container list
#include <deque>               // Container deque

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
    std::cout << "=========== EASYFIND TESTS ===================" << std::endl;
    std::cout << "===============================================" << std::endl;
    
    // Test avec un vector (container séquentiel avec accès aléatoire)
    printSeparator("TEST WITH VECTOR");
    std::vector<int> vec;          // Déclare un vector vide
    vec.push_back(10);             // Ajoute l'élément 10 à la fin
    vec.push_back(20);             // Ajoute l'élément 20 à la fin
    vec.push_back(30);             // Ajoute l'élément 30 à la fin
    vec.push_back(40);             // Ajoute l'élément 40 à la fin
    vec.push_back(50);             // Ajoute l'élément 50 à la fin
    
    // Test de recherche d'une valeur existante (30)
    try 
    {
        // Appel de easyfind pour trouver 30 dans le vector
        std::vector<int>::iterator it = easyfind(vec, 30);
        // Affiche la valeur trouvée (déréférencement de l'itérateur)
        std::cout << "Value found: " << *it << std::endl;
    } 
    catch (std::exception &e) 
    {
        // Capture et affiche l'exception si la valeur n'est pas trouvée
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test de recherche d'une valeur inexistante (60)
    try 
    {
        // Appel de easyfind pour trouver 60 dans le vector (devrait échouer)
        std::vector<int>::iterator it = easyfind(vec, 60);
        std::cout << "Value found: " << *it << std::endl;
    } 
    catch (std::exception &e) 
    {
        // Capture et affiche l'exception attendue
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test avec une list (container séquentiel doublement chaîné)
    printSeparator("TEST WITH LIST");
    std::list<int> lst;            // Déclare une liste vide
    lst.push_back(15);             // Ajoute l'élément 15 à la fin
    lst.push_back(25);             // Ajoute l'élément 25 à la fin
    lst.push_back(35);             // Ajoute l'élément 35 à la fin
    lst.push_back(45);             // Ajoute l'élément 45 à la fin
    lst.push_back(55);             // Ajoute l'élément 55 à la fin
    
    // Test de recherche d'une valeur existante (35)
    try 
    {
        // Appel de easyfind pour trouver 35 dans la liste
        std::list<int>::iterator it = easyfind(lst, 35);
        std::cout << "Value found: " << *it << std::endl;
    } catch (std::exception &e) {
        // Capture et affiche l'exception si la valeur n'est pas trouvée
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test de recherche d'une valeur inexistante (65)
    try
    {
        // Appel de easyfind pour trouver 65 dans la liste (devrait échouer)
        std::list<int>::iterator it = easyfind(lst, 65);
        std::cout << "Value found: " << *it << std::endl;
    } 
    catch (std::exception &e)
    {
        // Capture et affiche l'exception attendue
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test avec un deque (double-ended queue, permet insert/delete aux deux extrémités)
    printSeparator("TEST WITH DEQUE");
    std::deque<int> dq;            // Déclare un deque vide
    dq.push_back(5);               // Ajoute l'élément 5 à la fin
    dq.push_back(15);              // Ajoute l'élément 15 à la fin
    dq.push_back(25);              // Ajoute l'élément 25 à la fin
    dq.push_back(35);              // Ajoute l'élément 35 à la fin
    dq.push_back(45);              // Ajoute l'élément 45 à la fin
    
    // Test de recherche d'une valeur existante (25)
    try 
    {
        // Appel de easyfind pour trouver 25 dans le deque
        std::deque<int>::iterator it = easyfind(dq, 25);
        std::cout << "Value found: " << *it << std::endl;
    } 
    catch (std::exception &e) 
    {
        // Capture et affiche l'exception si la valeur n'est pas trouvée
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test de recherche d'une valeur inexistante (75)
    try 
    {
        // Appel de easyfind pour trouver 75 dans le deque (devrait échouer)
        std::deque<int>::iterator it = easyfind(dq, 75);
        std::cout << "Value found: " << *it << std::endl;
    } 
    catch (std::exception &e) 
    {
        // Capture et affiche l'exception attendue
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Pied de page indiquant la fin des tests
    std::cout << "\n===============================================" << std::endl;
    std::cout << "============= TESTS COMPLETED =================" << std::endl;
    std::cout << "===============================================" << std::endl;

    return 0;  // Retourne 0 pour indiquer une exécution réussie
}