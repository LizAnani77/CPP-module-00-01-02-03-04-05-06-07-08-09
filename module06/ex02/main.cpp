#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>    
#include <sstream>

// Affiche un séparateur visuel pour améliorer la lisibilité de la sortie
void printSeparator(const std::string &title)
{
    std::cout << "\n";
    std::cout << "===============================================" << std::endl;
    std::cout << title << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "\n";
}

// Génère aléatoirement un objet A, B ou C et le retourne en tant que pointeur Base
// Illustre la création polymorphique d'objets masqués derrière un type de base
Base *generate(void)
{
    // Génère un nombre aléatoire entre 0 et 2
    int choice = rand() % 3;
    
    std::cout << "Generating random object... ";
    
    // Crée et retourne un objet en fonction du nombre aléatoire
    switch (choice)
    {
        case 0:
            std::cout << "Created type A" << std::endl;
            return new A();
        case 1:
            std::cout << "Created type B" << std::endl;
            return new B();
        case 2:
            std::cout << "Created type C" << std::endl;
            return new C();
        default:
            // Ne devrait jamais arriver
            std::cout << "ERROR: Invalid random number" << std::endl;
            return NULL;
    }
}

// Identifie le type réel de l'objet pointé par p en utilisant un pointeur
// Utilise dynamic_cast pour la vérification sécurisée du type à l'exécution
void identify(Base *p)
{
    // Utilise dynamic_cast pour tenter de convertir le pointeur vers chaque type
    // Si la conversion réussit, le type correspondant est affiché
    
    if (dynamic_cast<A *>(p) != NULL)
        std::cout << "Identified type: A" << std::endl;
    else if (dynamic_cast<B *>(p) != NULL)
        std::cout << "Identified type: B" << std::endl;
    else if (dynamic_cast<C *>(p) != NULL)
        std::cout << "Identified type: C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

// Identifie le type réel de l'objet référencé par p en utilisant une référence
// L'utilisation de pointeurs est interdite dans cette fonction
void identify(Base &p)
{
    try
    {
        // Essaie de convertir en type A
        (void)dynamic_cast<A &>(p);
        std::cout << "Identified type: A" << std::endl;
        return;
    }
    catch (...) {} // Capture n'importe quelle exception sans spécifier son type
    
    try
    {
        // Essaie de convertir en type B
        (void)dynamic_cast<B &>(p);
        std::cout << "Identified type: B" << std::endl;
        return;
    }
    catch (...) {}
    
    try
    {
        // Essaie de convertir en type C
        (void)dynamic_cast<C &>(p);
        std::cout << "Identified type: C" << std::endl;
        return;
    }
    catch (...) {}
    
    // Si aucune conversion n'a réussi
    std::cout << "Unknown type" << std::endl;
}

// Fonction principale
int main()
{
    // Initialise le générateur de nombres aléatoires
    srand(static_cast<unsigned int>(time(NULL)));
    
    std::cout << "===============================================" << std::endl;
    std::cout << "========= TYPE IDENTIFICATION TEST ============" << std::endl;
    std::cout << "===============================================" << std::endl;
    
    // Test avec plusieurs objets générés aléatoirement
    for (int i = 0; i < 5; ++i)
    {
        // Conversion manuelle d'entier en chaîne au lieu d'utiliser std::to_string
        std::ostringstream ss;
        ss << "TEST #" << (i + 1);
        printSeparator(ss.str());
        
        // Génère un objet aléatoire
        Base *randomObj = generate();
        
        // Identification par pointeur
        std::cout << "Identification using pointer: ";
        identify(randomObj);
        
        // Identification par référence
        std::cout << "Identification using reference: ";
        identify(*randomObj);
        
        // Libération de la mémoire
        delete randomObj;
    }
    
    std::cout << "\n===============================================" << std::endl;
    std::cout << "============= TESTS COMPLETED =================" << std::endl;
    std::cout << "===============================================" << std::endl;
    
    return 0;
}