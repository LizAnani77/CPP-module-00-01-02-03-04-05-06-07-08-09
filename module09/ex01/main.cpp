#include "RPN.hpp"         // Inclut notre classe RPN
#include <iostream>        // Pour std::cout, std::cerr

int main(int argc, char **argv)
{
    if (argc != 2)         // Vérifie si le nombre d'arguments est correct
    {
        std::cerr << "Usage: " << argv[0] << " \"expression\"" << std::endl;  // Affiche l'usage
        return 1;          // Retourne une erreur
    }
    
    RPN calculator;        // Crée un objet RPN
    
    try                    // Bloc try pour capturer les exceptions
    {
        int result = calculator.evaluate(argv[1]);  // Évalue l'expression RPN
        std::cout << result << std::endl;           // Affiche le résultat
    }
    catch (const std::exception& e)                 // Capture les exceptions
    {
        std::cerr << e.what() << std::endl;         // Affiche le message d'erreur
        return 1;                                   // Retourne une erreur
    }
    
    return 0;                                       // Retourne un succès
}