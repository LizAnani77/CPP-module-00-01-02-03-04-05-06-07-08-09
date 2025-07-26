#include "PmergeMe.hpp"      // Inclut notre classe PmergeMe
#include <iostream>          // Pour std::cout, std::cerr

int main(int argc, char **argv)
{
    if (argc < 2)            // Vérifie s'il y a au moins un argument
    {
        std::cerr << "Usage: " << argv[0] << " [positive integer sequence]" << std::endl;  // Affiche l'usage
        return 1;            // Retourne une erreur
    }
    
    try                      // Bloc try pour capturer les exceptions
    {
        PmergeMe sorter(argv, argc);   // Crée un objet PmergeMe avec les arguments
        sorter.sort();                 // Trie les éléments
        sorter.display(argv, argc);    // Affiche les résultats
    }
    catch (const std::exception& e)    // Capture les exceptions
    {
        std::cerr << e.what() << std::endl;  // Affiche le message d'erreur
        return 1;                            // Retourne une erreur
    }
    
    return 0;                               // Retourne un succès
}