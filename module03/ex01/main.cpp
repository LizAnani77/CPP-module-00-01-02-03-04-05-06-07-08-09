/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 01:24:20 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/03/03 14:12:12 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "\n========== TESTS DU SCAVTRAP : HÉRITAGE ==========" << std::endl;
    
    // PARTIE 1: Test ordre construction/destruction
    std::cout << "\n----- Test ordre construction/destruction -----" << std::endl;
    std::cout << "Création d'un ScavTrap:" << std::endl;
    std::cout << "(Note: On verra d'abord le message du constructeur ClapTrap puis ScavTrap - démontrant l'ordre de construction)" << std::endl;
    ScavTrap scav("Robot");
    
    // PARTIE 2: Tester les fonctionnalités héritées et nouvelles
    std::cout << "\n----- Test des fonctionnalités de base -----" << std::endl;
    
    std::cout << "Test des méthodes héritées et spécifiques:" << std::endl;
    std::cout << "(Note: La méthode attack a été redéfinie, donc affichera 'ScavTrap')" << std::endl;
    scav.attack("Enemy");
    
    std::cout << "\n(Note: takeDamage est héritée de ClapTrap sans redéfinition. Le préfixe 'ClapTrap' est normal et démontre l'héritage)" << std::endl;
    scav.takeDamage(30);
    
    std::cout << "\n(Note: beRepaired est aussi héritée de ClapTrap. Le préfixe 'ClapTrap' est également normal et démontre l'héritage)" << std::endl;
    scav.beRepaired(20);
    
    std::cout << "\n(Note: guardGate est une méthode spécifique à ScavTrap, donc affichera 'ScavTrap')" << std::endl;
    scav.guardGate();
    
    // // PARTIE 3: Test gestion de l'énergie
    // std::cout << "\n----- Test de la gestion d'énergie -----" << std::endl;
    
    // std::cout << "Test d'attaque et de réparation:" << std::endl;
    // scav.attack("Target");
    // scav.beRepaired(5);

    // PARTIE 3: Test gestion de l'énergie
    std::cout << "\n----- Test de la gestion d'énergie -----" << std::endl;

    std::cout << "Test d'épuisement d'énergie:" << std::endl;
    ScavTrap energyScav("EnergyTester");

    // ScavTrap a 50 points d'énergie, donc on fait 25 cycles
    for (int i = 0; i < 25; ++i)
    {
        std::cout << "\nItération " << i + 1 << ":" << std::endl;
        energyScav.attack("Target");
        energyScav.beRepaired(1);
    }
    std::cout << "\nTentative d'action après épuisement d'énergie:" << std::endl;
    energyScav.attack("Cible");  // Devrait échouer
    energyScav.guardGate();      // Intéressant de vérifier si guardGate fonctionne sans énergie
    
    // PARTIE 4: Test dégâts et mort
    std::cout << "\n----- Test des dégâts et de la mort -----" << std::endl;
    
    std::cout << "Création d'un second ScavTrap pour tester la mort:" << std::endl;
    ScavTrap scav2("Defender");
    
    std::cout << "\nTest de fonctionnalité après dégâts importants:" << std::endl;
    std::cout << "(Note: Même après avoir pris des dégâts, un ScavTrap peut toujours utiliser ses fonctionnalités spécifiques)" << std::endl;
    scav2.takeDamage(95);
    scav2.guardGate();
    
    std::cout << "\nTest de fonctionnalité après destruction:" << std::endl;
    std::cout << "(Note: Quand les points de vie atteignent 0, l'objet est considéré comme mort et ne peut plus utiliser aucune fonction)" << std::endl;
    scav2.takeDamage(10);
    scav2.guardGate();
    scav2.attack("Enemy");
    
    // PARTIE 5: Test de l'opérateur d'affectation pour ScavTrap
    std::cout << "\n----- Test de l'opérateur d'affectation -----" << std::endl;

    // Créer deux ScavTraps distincts
    ScavTrap original("Original");
    ScavTrap copie("Copie");
    std::cout << "États initiaux:" << std::endl;
    std::cout << "- Premier robot: " << original.getName() << std::endl;
    std::cout << "- Second robot: " << copie.getName() << std::endl;

    // Modifier l'état du ScavTrap original
    std::cout << "\nModification du premier robot (Original):" << std::endl;
    original.attack("Ennemi");  // Consomme 1 énergie
    original.takeDamage(30);    // Réduit les points de vie
    original.guardGate();       // Active le mode Gate keeper

    // Effectuer l'affectation
    std::cout << "\nAFFECTATION: copie = original (le second robot devient une copie du premier)" << std::endl;
    copie = original;

    std::cout << "\nAprès affectation, les deux robots ont le MÊME NOM:" << std::endl;
    std::cout << "- Premier robot: " << original.getName() << std::endl;
    std::cout << "- Second robot: " << copie.getName() << " (a pris le nom 'Original')" << std::endl;

    // Pour mieux comprendre ce qui se passe
    std::cout << "\nActions après affectation:" << std::endl;
    std::cout << "1) Le premier robot (Original initial) attaque et passe en mode gardien:" << std::endl;
    original.attack("Cible-A");
    original.guardGate();

    std::cout << "\n2) Le second robot (Copie renommé en Original) attaque et passe en mode gardien:" << std::endl;
    copie.attack("Cible-B");
    copie.guardGate();
    
    // PARTIE 6: Fin des tests
    std::cout << "\n========== FIN DES TESTS : SCAVTRAP ==========" << std::endl;
    std::cout << "(Note: À la destruction, les messages apparaîtront dans l'ordre inverse: ScavTrap puis ClapTrap)" << std::endl;
    
    return 0;
}