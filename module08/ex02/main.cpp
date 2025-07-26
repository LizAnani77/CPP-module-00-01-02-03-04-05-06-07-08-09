#include "MutantStack.hpp"  // Notre classe MutantStack
#include <iostream>         // Pour cout, endl
#include <list>             // Pour comparer avec std::list
#include <vector>           // Pour des tests supplémentaires

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
    std::cout << "======== MUTANTSTACK TESTS ===================" << std::endl;
    std::cout << "===============================================" << std::endl;

    // Test de MutantStack (exemple du sujet)
    printSeparator("MUTANTSTACK TEST (SUBJECT EXAMPLE)");
    MutantStack<int> mstack;       // Crée une MutantStack vide d'entiers
    
    mstack.push(5);                // Ajoute l'entier 5 au sommet
    mstack.push(17);               // Ajoute l'entier 17 au sommet
    
    // Affiche l'élément au sommet (devrait être 17)
    std::cout << "Top element: " << mstack.top() << std::endl;
    
    mstack.pop();                  // Retire l'élément du sommet (17)
    
    // Affiche la taille après le pop (devrait être 1)
    std::cout << "Stack size after pop: " << mstack.size() << std::endl;
    
    mstack.push(3);                // Ajoute l'entier 3 au sommet
    mstack.push(5);                // Ajoute l'entier 5 au sommet
    mstack.push(737);              // Ajoute l'entier 737 au sommet
    mstack.push(0);                // Ajoute l'entier 0 au sommet
    
    // Obtient un itérateur au début de la pile
    MutantStack<int>::iterator it = mstack.begin();
    // Obtient un itérateur à la fin de la pile
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;                          // Avance l'itérateur d'une position
    --it;                          // Recule l'itérateur d'une position
    
    // Parcourt tous les éléments de la pile
    std::cout << "Elements in MutantStack: " << std::endl;
    while (it != ite)
    {
        std::cout << *it << " ";   // Affiche l'élément courant
        ++it;                      // Avance l'itérateur
    }
    std::cout << std::endl;
    
    // Crée une pile standard à partir de la MutantStack
    std::stack<int> s(mstack);
    // Affiche la taille de la pile standard
    std::cout << "Standard stack size (copied from MutantStack): " << s.size() << std::endl;

    // Test avec std::list pour comparer le comportement
    printSeparator("EQUIVALENT TEST WITH STD::LIST");
    std::list<int> lst;            // Crée une liste vide d'entiers
    
    lst.push_back(5);              // Ajoute l'entier 5 à la fin
    lst.push_back(17);             // Ajoute l'entier 17 à la fin
    
    // Affiche l'élément à la fin (devrait être 17)
    std::cout << "Back element: " << lst.back() << std::endl;
    
    lst.pop_back();                // Retire l'élément de la fin (17)
    
    // Affiche la taille après le pop_back (devrait être 1)
    std::cout << "List size after pop: " << lst.size() << std::endl;
    
    lst.push_back(3);              // Ajoute l'entier 3 à la fin
    lst.push_back(5);              // Ajoute l'entier 5 à la fin
    lst.push_back(737);            // Ajoute l'entier 737 à la fin
    lst.push_back(0);              // Ajoute l'entier 0 à la fin
    
    // Obtient un itérateur au début de la liste
    std::list<int>::iterator lst_it = lst.begin();
    // Obtient un itérateur à la fin de la liste
    std::list<int>::iterator lst_ite = lst.end();
    
    ++lst_it;                      // Avance l'itérateur d'une position
    --lst_it;                      // Recule l'itérateur d'une position
    
    // Parcourt tous les éléments de la liste
    std::cout << "Elements in List: " << std::endl;
    while (lst_it != lst_ite)
    {
        std::cout << *lst_it << " ";  // Affiche l'élément courant
        ++lst_it;                     // Avance l'itérateur
    }
    std::cout << std::endl;

    // Test des itérateurs additionnels
    printSeparator("ADDITIONAL ITERATORS TEST");
    MutantStack<int> testStack;    // Crée une MutantStack vide d'entiers
    
    // Remplit la pile avec les entiers 0 à 4
    for (int i = 0; i < 5; ++i)
        testStack.push(i);
    
    // Parcourt la pile en ordre croissant (de bas en haut)
    std::cout << "Forward iteration: ";
    for (MutantStack<int>::iterator it = testStack.begin(); it != testStack.end(); ++it)
        std::cout << *it << " ";   // Affiche chaque élément
    std::cout << std::endl;
    
    // Parcourt la pile en ordre décroissant (de haut en bas)
    std::cout << "Reverse iteration: ";
    for (MutantStack<int>::reverse_iterator rit = testStack.rbegin(); rit != testStack.rend(); ++rit)
        std::cout << *rit << " ";  // Affiche chaque élément
    std::cout << std::endl;

	// Test avec un autre type de données (strings)
	printSeparator("STRING TYPE TEST");
	MutantStack<std::string> stringStack;  // Crée une MutantStack vide de strings
	stringStack.push("Hello");            // Ajoute "Hello" au sommet
	stringStack.push("World");            // Ajoute "World" au sommet
	stringStack.push("C++");              // Ajoute "C++" au sommet
	stringStack.push("42");               // Ajoute "42" au sommet

	// Affiche l'élément au sommet (devrait être "42")
	std::cout << "Top string: " << stringStack.top() << std::endl;

	// Parcourt tous les strings dans la pile
	std::cout << "All strings: ";
	for (MutantStack<std::string>::iterator it = stringStack.begin(); it != stringStack.end(); ++it)
		std::cout << *it << " ";   // Affiche chaque string
	std::cout << std::endl;

	// Test avec un container sous-jacent différent (vector au lieu de deque)
	printSeparator("CUSTOM UNDERLYING CONTAINER TEST");
	MutantStack<int, std::vector<int> > vstack;  // Utilise vector comme container sous-jacent

	// Remplit la pile avec quelques entiers
	for (int i = 0; i < 5; ++i)
		vstack.push(i * 10);

	// Affiche tous les éléments
	std::cout << "Elements with vector container: ";
	for (MutantStack<int, std::vector<int> >::iterator it = vstack.begin(); it != vstack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	// Pied de page indiquant la fin des tests
	std::cout << "\n===============================================" << std::endl;
	std::cout << "============= TESTS COMPLETED =================" << std::endl;
	std::cout << "===============================================" << std::endl;

	return 0;  // Retourne 0 pour indiquer une exécution réussie
	}