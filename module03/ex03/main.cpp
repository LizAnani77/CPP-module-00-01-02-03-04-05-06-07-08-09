/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 03:10:41 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/03/03 14:16:52 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "\n========== TESTS DU DIAMONDTRAP : HÉRITAGE EN DIAMANT ==========" << std::endl;
    
    // PARTIE 1: Test ordre construction/destruction
    std::cout << "\n----- Test ordre construction/destruction -----" << std::endl;
    std::cout << "Création d'un DiamondTrap:" << std::endl;
    std::cout << "(Note: On verra d'abord le message des constructeurs ClapTrap, puis ScavTrap et FragTrap, et enfin DiamondTrap)" << std::endl;
    DiamondTrap diamond("Sparkle");
    
    // PARTIE 2: Vérification des attributs hérités
    std::cout << "\n----- Vérification des attributs hérités -----" << std::endl;
    
    std::cout << "(Note: DiamondTrap hérite des points de vie de FragTrap)" << std::endl;
    std::cout << "Points de vie: " << diamond.getHitPoints() << " HP (attendu: 100)" << std::endl;
    
    std::cout << "(Note: DiamondTrap hérite des points d'énergie de ScavTrap)" << std::endl;
    std::cout << "Points d'énergie: " << diamond.getEnergyPoints() << " EP (attendu: 50)" << std::endl;
    
    std::cout << "(Note: DiamondTrap hérite des dégâts d'attaque de FragTrap)" << std::endl;
    std::cout << "Dégâts d'attaque: " << diamond.getAttackDamage() << " dmg (attendu: 30)" << std::endl;
    
    // PARTIE 3: Comparaison avec les classes parentes
    std::cout << "\n----- Comparaison avec les classes parentes -----" << std::endl;
    
    ClapTrap clap("Basic");
    ScavTrap scav("Guardian");
    FragTrap frag("Fighter");
        
    std::cout << "ClapTrap  : " << clap.getHitPoints() << " HP, " 
                << clap.getEnergyPoints() << " EP, " 
                << clap.getAttackDamage() << " dmg" << std::endl;
        
    std::cout << "ScavTrap  : " << scav.getHitPoints() << " HP, " 
                << scav.getEnergyPoints() << " EP, " 
                << scav.getAttackDamage() << " dmg" << std::endl;
        
    std::cout << "FragTrap  : " << frag.getHitPoints() << " HP, " 
                << frag.getEnergyPoints() << " EP, " 
                << frag.getAttackDamage() << " dmg" << std::endl;
        
    std::cout << "DiamondTrap: " << diamond.getHitPoints() << " HP, " 
                << diamond.getEnergyPoints() << " EP, " 
                << diamond.getAttackDamage() << " dmg" << std::endl;
        
    std::cout << "\nDémonstration des messages d'attaque pour chaque type:" << std::endl;
    std::cout << "(Note: Observez la différence dans les préfixes des messages)" << std::endl;
    clap.attack("target1");    // Message avec préfixe 'ClapTrap'
    scav.attack("target2");    // Message avec préfixe 'ScavTrap'
    frag.attack("target3");    // Message avec préfixe 'ClapTrap' (car FragTrap n'a pas redéfini attack())
    diamond.attack("target4"); // Message avec préfixe 'ScavTrap' (car DiamondTrap utilise attack() de ScavTrap)
        
    // PARTIE 4: Test de la fonctionnalité spécifique à DiamondTrap
    std::cout << "\n----- Test de la fonction whoAmI spécifique à DiamondTrap -----" << std::endl;
    std::cout << "(Note: whoAmI doit afficher à la fois le nom du DiamondTrap et le nom du ClapTrap)" << std::endl;
    diamond.whoAmI();
    
    // PARTIE 5: Test des méthodes héritées
    std::cout << "\n----- Test des méthodes héritées -----" << std::endl;
    
    std::cout << "(Note: attack() est héritée de ScavTrap, donc affichera 'ScavTrap' dans le message)" << std::endl;
    diamond.attack("Enemy");
    
    std::cout << "\n(Note: takeDamage() est héritée de ClapTrap sans redéfinition. Le préfixe 'ClapTrap' est normal et démontre l'héritage)" << std::endl;
    diamond.takeDamage(30);
    
    std::cout << "\n(Note: beRepaired() est aussi héritée de ClapTrap sans redéfinition. Le préfixe 'ClapTrap' est également normal)" << std::endl;
    diamond.beRepaired(20);
    
    std::cout << "\n(Note: guardGate() est héritée de ScavTrap, donc affichera 'ScavTrap' dans le message)" << std::endl;
    diamond.guardGate();
    
    std::cout << "\n(Note: highFivesGuys() est héritée de FragTrap, donc affichera 'FragTrap' dans le message)" << std::endl;
    diamond.highFivesGuys();
    
    // PARTIE 6: Test de la gestion d'énergie et de dégâts
    std::cout << "\n----- Test de la gestion d'énergie et de dégâts -----" << std::endl;

    DiamondTrap energyTester("EnergyTester");

    std::cout << "Test d'épuisement d'énergie:" << std::endl;
    // DiamondTrap a 50 points d'énergie (hérités de ScavTrap), donc on fait 25 cycles
    for (int i = 0; i < 25; ++i)
    {
        // Pour ne pas surcharger la sortie, on affiche seulement tous les 5 cycles
        if (i % 5 == 0)
            std::cout << "\nItération " << i + 1 << " à " << i + 5 << ":" << std::endl;
        
        energyTester.attack("Target");
        energyTester.beRepaired(1);
    }
    std::cout << "\nTentative d'action après épuisement d'énergie:" << std::endl;
    energyTester.attack("Cible");     // Devrait échouer en raison de l'absence de points d'énergie
    energyTester.beRepaired(5);       // Devrait échouer en raison de l'absence de points d'énergie
    energyTester.guardGate();         // Intéressant de vérifier si fonctionne sans énergie
    energyTester.highFivesGuys();     // Intéressant de vérifier si fonctionne sans énergie
    energyTester.whoAmI();            // Intéressant de vérifier si fonctionne sans énergie
    
    // PARTIE 7: Test dégâts et mort
    std::cout << "\n----- Test des dégâts et de la mort -----" << std::endl;
    
    DiamondTrap damageTest("Victim");
    
    std::cout << "\nTest de fonctionnalité après dégâts partiels:" << std::endl;
    std::cout << "(Note: Même après avoir pris des dégâts, un DiamondTrap peut toujours utiliser ses fonctionnalités)" << std::endl;
    damageTest.takeDamage(50);
    damageTest.attack("Enemy");
    damageTest.guardGate();
    damageTest.highFivesGuys();
    
    std::cout << "\nTest de fonctionnalité après destruction:" << std::endl;
    std::cout << "(Note: Quand les points de vie atteignent 0, l'objet est considéré comme mort et ne peut plus utiliser aucune fonction)" << std::endl;
    damageTest.takeDamage(60);          // Devrait être fatal (50 + 60 > 100)
    damageTest.attack("Enemy");         // Ne devrait pas fonctionner
    damageTest.beRepaired(30);          // Ne devrait pas fonctionner
    damageTest.guardGate();             // Ne devrait pas fonctionner
    damageTest.highFivesGuys();         // Ne devrait pas fonctionner
    damageTest.whoAmI();                // Ne devrait pas fonctionner
    
    // PARTIE 8: Test de l'opérateur d'affectation pour DiamondTrap
    std::cout << "\n----- Test de l'opérateur d'affectation -----" << std::endl;

    // Créer deux DiamondTraps distincts
    DiamondTrap original("Original");
    DiamondTrap copie("Copie");
    std::cout << "États initiaux:" << std::endl;
    std::cout << "- Premier robot: " << original.getName() << std::endl;
    std::cout << "- Second robot: " << copie.getName() << std::endl;

    // Modifier l'état du DiamondTrap original
    std::cout << "\nModification du premier robot (Original):" << std::endl;
    original.attack("Ennemi");  // Consomme 1 énergie
    original.takeDamage(30);    // Réduit les points de vie
    original.guardGate();       // Active le mode Gate keeper
    original.highFivesGuys();   // Demande un high five

    // Effectuer l'affectation
    std::cout << "\nAFFECTATION: copie = original (le second robot devient une copie du premier)" << std::endl;
    copie = original;

    std::cout << "\nAprès affectation, les deux robots ont le MÊME NOM:" << std::endl;
    std::cout << "- Premier robot: " << original.getName() << std::endl;
    std::cout << "- Second robot: " << copie.getName() << " (a pris le nom 'Original')" << std::endl;

    // Pour mieux comprendre ce qui se passe
    std::cout << "\nActions après affectation:" << std::endl;
    std::cout << "1) Le premier robot (Original initial) utilise whoAmI et ses capacités spéciales:" << std::endl;
    original.whoAmI();
    original.guardGate();
    original.highFivesGuys();

    std::cout << "\n2) Le second robot (Copie renommé en Original) utilise whoAmI et ses capacités spéciales:" << std::endl;
    copie.whoAmI();
    copie.guardGate();
    copie.highFivesGuys();
    
    // PARTIE 9: Fin des tests - Ordre de destruction
    std::cout << "\n========== FIN DES TESTS : DIAMONDTRAP ==========" << std::endl;
    std::cout << "(Note: À la destruction, les messages apparaîtront dans l'ordre inverse: DiamondTrap, FragTrap, ScavTrap, puis ClapTrap)" << std::endl;
    
    return 0;
}