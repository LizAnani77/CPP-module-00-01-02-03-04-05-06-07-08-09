/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 00:22:41 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/03/03 13:55:22 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "\n========== TESTS DE BASE : ClapTrap ==========" << std::endl;
    
    // PARTIE 1: Test des constructeurs
    std::cout << "\n----- Test des constructeurs -----" << std::endl;
    std::cout << "Création des ClapTraps:" << std::endl;
    
    ClapTrap robot1("Robot1");                    // Constructeur avec nom
    std::cout << "\nConstructeur par défaut:" << std::endl;
    ClapTrap basic;                               // Constructeur par défaut
    std::cout << "\nConstructeur de copie:" << std::endl;
    ClapTrap copy(robot1);                        // Constructeur de copie
    
    // PARTIE 2: Test des fonctionnalités de base
    std::cout << "\n----- Test des fonctionnalités de base -----" << std::endl;
    
    std::cout << "Test d'attaque, de dégâts et de réparation:" << std::endl;
    robot1.attack("Ennemi");
    robot1.takeDamage(5);
    robot1.beRepaired(2);
    
    // PARTIE 3: Test limite d'énergie
    std::cout << "\n----- Test de l'épuisement d'énergie -----" << std::endl;
    
    std::cout << "Test d'attaques et de réparations successives:" << std::endl;
    ClapTrap energetic("Energetic");
    
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "\nItération " << i + 1 << ":" << std::endl;
        energetic.attack("Target");
        energetic.beRepaired(1);
    }
    std::cout << "\nTentative d'attaque après épuisement d'énergie:" << std::endl;
    energetic.attack("Cible");  // Devrait échouer en raison de l'absence de points d'énergie
    
    // PARTIE 4: Test mort du robot
    std::cout << "\n----- Test de la destruction du robot -----" << std::endl;
    
    std::cout << "Création d'un ClapTrap pour tester la mort:" << std::endl;
    ClapTrap fragile("Fragile");
    
    std::cout << "\nTest de fonctionnalité après dégâts partiels:" << std::endl;
    fragile.takeDamage(5);
    fragile.attack("Target");
    fragile.beRepaired(2);
    
    std::cout << "\nTest de fonctionnalité après destruction:" << std::endl;
    std::cout << "(Note: Quand les points de vie atteignent 0, le robot est considéré comme mort et ne peut plus agir)" << std::endl;
    fragile.takeDamage(10);
    fragile.attack("Enemy");
    fragile.beRepaired(5);
    
    // PARTIE 5: Test de l'opérateur d'affectation
    std::cout << "\n----- Test de l'opérateur d'affectation -----" << std::endl;
    
    // Créer deux ClapTraps distincts
    ClapTrap original("Original");
    ClapTrap copie("Copie");

    std::cout << "États initiaux:" << std::endl;
    std::cout << "- Premier robot: " << original.getName() << std::endl;
    std::cout << "- Second robot: " << copie.getName() << std::endl;

    // Modifier l'état du ClapTrap original
    std::cout << "\nModification du premier robot (Original):" << std::endl;
    original.attack("Ennemi");  // Consomme 1 énergie (9 restants)
    original.takeDamage(3);     // Réduit les points de vie à 7

    // Effectuer l'affectation
    std::cout << "\nAFFECTATION: copie = original (le second robot devient une copie du premier)" << std::endl;
    copie = original;

    std::cout << "\nAprès affectation, les deux robots ont le MÊME NOM:" << std::endl;
    std::cout << "- Premier robot: " << original.getName() << std::endl;
    std::cout << "- Second robot: " << copie.getName() << " (a pris le nom 'Original')" << std::endl;

    // Pour mieux comprendre ce qui se passe
    std::cout << "\nAttaques après affectation:" << std::endl;
    std::cout << "1) Le premier robot (Original initial) attaque:" << std::endl;
    original.attack("Cible-A");

    std::cout << "\n2) Le second robot (Copie renommé en Original) attaque:" << std::endl;
    copie.attack("Cible-B");
    
    // PARTIE 6: Fin des tests
    std::cout << "\n========== FIN DES TESTS : ClapTrap ==========" << std::endl;
    
    return 0;
}