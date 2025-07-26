#include "BitcoinExchange.hpp"  // Inclut notre classe BitcoinExchange
#include <iostream>             // Pour std::cout, std::cerr

int main(int argc, char **argv)
{
    if (argc != 2)              // Vérifie si le nombre d'arguments est correct
    {
        std::cerr << "Error: could not open file." << std::endl;  // Affiche une erreur
        return 1;               // Retourne une erreur
    }
    
    try                         // Bloc try pour capturer les exceptions
    {
        BitcoinExchange exchange("data.csv");     // Crée un objet BitcoinExchange avec le fichier de données
        exchange.processInputFile(argv[1]);       // Traite le fichier d'entrée fourni en argument
    }
    catch (const std::exception& e)               // Capture les exceptions
    {
        std::cerr << e.what() << std::endl;       // Affiche le message d'erreur
        return 1;                                 // Retourne une erreur
    }
    
    return 0;                                     // Retourne un succès
}