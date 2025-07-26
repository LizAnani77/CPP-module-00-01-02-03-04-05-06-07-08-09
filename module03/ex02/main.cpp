/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 01:51:47 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/03/03 14:12:40 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "\n========== TESTS DU FRAGTRAP : HÉRITAGE ==========" << std::endl;
    
    // PARTIE 1: Test ordre construction/destruction
    std::cout << "\n----- Test ordre construction/destruction -----" << std::endl;
    std::cout << "Création d'un FragTrap:" << std::endl;
    std::cout << "(Note: On verra d'abord le message du constructeur ClapTrap puis FragTrap - démontrant l'ordre de construction)" << std::endl;
    FragTrap frag("Robot");
    
    // PARTIE 2: Tester les fonctionnalités héritées et nouvelles
    std::cout << "\n----- Test des fonctionnalités de base -----" << std::endl;
    
    std::cout << "Test des méthodes héritées et spécifiques:" << std::endl;
    std::cout << "(Note: attack() est héritée de ClapTrap sans redéfinition dans FragTrap. Le préfixe 'ClapTrap' est normal et démontre l'héritage)" << std::endl;
    frag.attack("Enemy");
    
    std::cout << "\n(Note: takeDamage est héritée de ClapTrap sans redéfinition. Le préfixe 'ClapTrap' est normal et démontre l'héritage)" << std::endl;
    frag.takeDamage(30);
    
    std::cout << "\n(Note: beRepaired est aussi héritée de ClapTrap. Le préfixe 'ClapTrap' est également normal et démontre l'héritage)" << std::endl;
    frag.beRepaired(20);
    
    std::cout << "\n(Note: highFivesGuys est une méthode spécifique à FragTrap)" << std::endl;
    frag.highFivesGuys();
    
  // PARTIE 3: Test de la gestion d'énergie
    std::cout << "\n----- Test de la gestion d'énergie -----" << std::endl;

    std::cout << "Test d'épuisement d'énergie:" << std::endl;
    FragTrap energyFrag("EnergyTester");

    // FragTrap a 100 points d'énergie, donc on fait 50 cycles
    for (int i = 0; i < 50; ++i)
    {
        // Pour ne pas surcharger la sortie, on affiche seulement tous les 10 cycles
        if (i % 10 == 0)
            std::cout << "\nItération " << i + 1 << " à " << i + 10 << ":" << std::endl;
        
        energyFrag.attack("Target");
        energyFrag.beRepaired(1);
    }
    std::cout << "\nTentative d'action après épuisement d'énergie:" << std::endl;
    energyFrag.attack("Cible");  // Devrait échouer en raison de l'absence de points d'énergie
    energyFrag.highFivesGuys();  // Intéressant de vérifier si highFivesGuys fonctionne sans énergie
    
    // PARTIE 4: Test dégâts et mort
    std::cout << "\n----- Test des dégâts et de la mort -----" << std::endl;
    
    std::cout << "Création d'un second FragTrap pour tester la mort:" << std::endl;
    FragTrap frag2("Challenger");
    
    std::cout << "\nTest de fonctionnalité après dégâts importants:" << std::endl;
    std::cout << "(Note: Même après avoir pris des dégâts, un FragTrap peut toujours utiliser ses fonctionnalités spécifiques)" << std::endl;
    frag2.takeDamage(95);
    frag2.highFivesGuys();
    
    std::cout << "\nTest de fonctionnalité après destruction:" << std::endl;
    std::cout << "(Note: Quand les points de vie atteignent 0, l'objet est considéré comme mort et ne peut plus utiliser aucune fonction)" << std::endl;
    frag2.takeDamage(10);
    frag2.highFivesGuys();
    frag2.attack("Enemy");
    
    // PARTIE 5: Test de l'opérateur d'affectation
    std::cout << "\n----- Test de l'opérateur d'affectation -----" << std::endl;

    // Créer deux FragTraps distincts
    FragTrap original("Original");
    FragTrap copie("Copie");
    std::cout << "États initiaux:" << std::endl;
    std::cout << "- Premier robot: " << original.getName() << std::endl;
    std::cout << "- Second robot: " << copie.getName() << std::endl;

    // Modifier l'état du FragTrap original
    std::cout << "\nModification du premier robot (Original):" << std::endl;
    original.attack("Ennemi");  // Consomme 1 énergie
    original.takeDamage(30);    // Réduit les points de vie
    original.highFivesGuys();   // Utilise la capacité spéciale de FragTrap

    // Effectuer l'affectation
    std::cout << "\nAFFECTATION: copie = original (le second robot devient une copie du premier)" << std::endl;
    copie = original;

    std::cout << "\nAprès affectation, les deux robots ont le MÊME NOM:" << std::endl;
    std::cout << "- Premier robot: " << original.getName() << std::endl;
    std::cout << "- Second robot: " << copie.getName() << " (a pris le nom 'Original')" << std::endl;

    // Pour mieux comprendre ce qui se passe
    std::cout << "\nActions après affectation:" << std::endl;
    std::cout << "1) Le premier robot (Original initial) attaque et demande un high five:" << std::endl;
    original.attack("Cible-A");
    original.highFivesGuys();

    std::cout << "\n2) Le second robot (Copie renommé en Original) attaque et demande un high five:" << std::endl;
    copie.attack("Cible-B");
    copie.highFivesGuys();
        
    // PARTIE 6: Fin des tests
    std::cout << "\n========== FIN DES TESTS : FRAGTRAP ==========" << std::endl;
    std::cout << "(Note: À la destruction, les messages apparaîtront dans l'ordre inverse: FragTrap puis ClapTrap)" << std::endl;
    
    return 0;
}