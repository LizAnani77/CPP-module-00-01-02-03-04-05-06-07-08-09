/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:45:33 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/03/06 14:49:03 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

int main()
{
    std::cout << "\n========== TESTS DE BASE ==========\n" << std::endl;
    
    // Test 1 : Création d'une source de materias et apprentissage
    std::cout << "=== Creating MateriaSource and Learning Materias ===" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    // Test 2 : Création des personnages
    std::cout << "\n=== Creating Characters ===" << std::endl;
    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");
    
    // Test 3 : Création et équipement des materias
    std::cout << "\n=== Creating and Equipping Materias ===" << std::endl;
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    // Test 4 : Utilisation des materias
    std::cout << "\n=== Using Materias ===" << std::endl;
    me->use(0, *bob);
    me->use(1, *bob);
    
    // Test 5 : Test de la copie profonde
    std::cout << "\n=== Testing Basic Deep Copy ===" << std::endl;

    // Étape 1 : Création du personnage original
    std::cout << "ÉTAPE 1: Création du personnage original avec une materia" << std::endl;
    Character* carlito = new Character("Carlito");
    tmp = src->createMateria("ice");
    carlito->equip(tmp);

    // Démonstration de l'équipement initial
    std::cout << "\nÉTAT INITIAL:" << std::endl;
    std::cout << "Carlito utilise sa materia:" << std::endl;
    carlito->use(0, *bob);

    // Étape 2 : Création d'une copie du personnage
    std::cout << "\nÉTAPE 2: Création d'une copie du personnage" << std::endl;
    Character* carlito_copy = new Character(*carlito);

    // Test des deux personnages pour montrer qu'ils ont les mêmes materias initialement
    std::cout << "\nCOMPARAISON INITIALE:" << std::endl;
    std::cout << "Personnage original utilise sa materia:" << std::endl;
    carlito->use(0, *bob);
    std::cout << "Personnage copié utilise sa materia:" << std::endl;
    carlito_copy->use(0, *bob);

    // Étape 3: Équiper une nouvelle materia au personnage original uniquement
    std::cout << "\nÉTAPE 3: Équipement d'une nouvelle materia au personnage original uniquement" << std::endl;
    tmp = src->createMateria("cure");
    carlito->equip(tmp);

    // Étape 4: Comparaison après modification
    std::cout << "\nCOMPARAISON APRÈS MODIFICATION:" << std::endl;
    std::cout << "Personnage original utilise sa première materia:" << std::endl;
    carlito->use(0, *bob);
    std::cout << "Personnage original utilise sa nouvelle materia:" << std::endl;
    carlito->use(1, *bob);
    std::cout << "Personnage copié utilise sa materia:" << std::endl;
    carlito_copy->use(0, *bob);
    std::cout << "Personnage copié essaie d'utiliser l'emplacement 1 (qui devrait être vide):" << std::endl;
    carlito_copy->use(1, *bob);

    // Conclusion
    std::cout << "\nCONCLUSION:" << std::endl;
    std::cout << "✓ La copie a bien sa propre materia ice (copie profonde)" << std::endl;
    std::cout << "✓ Les modifications du personnage original n'affectent pas la copie" << std::endl;
    std::cout << "✓ Chaque personnage a son propre inventaire de materias" << std::endl;
    
    std::cout << "\n========== TESTS ADDITIONNELS ==========\n" << std::endl;
    
    // Test 6 : Test d'équipement maximum (4 materias)
    std::cout << "=== Testing Max Equipment (4 materias) ===" << std::endl;
    Character* max_char = new Character("MaxEquip");
    
    // Équiper exactement 4 materias
    for (int i = 0; i < 4; i++)
    {
        tmp = src->createMateria(i % 2 == 0 ? "ice" : "cure");
        if (tmp) {
            max_char->equip(tmp);
            std::cout << "Equipped materia " << i << std::endl;
        }
    }
    
    // Essayer d'équiper une 5ème (doit être refusée)
    std::cout << "\n=== Trying to equip 5th materia (should fail) ===" << std::endl;
    tmp = src->createMateria("ice");
    if (tmp) {
        // Sauvegarder le pointeur original
        AMateria* overflow_materia = tmp;
        
        // Tenter l'équipement
        max_char->equip(tmp);
        
        // Tester si la materia a été équipée
        max_char->use(4, *bob); // Devrait ne rien faire si 4 est un index invalide
        
        // Libérer la materia qui n'a pas pu être équipée
        delete overflow_materia;
    }
    
    // Test 7 : Test de création de materias avec type inconnu
    std::cout << "\n=== Testing Unknown Materia Type ===" << std::endl;
    tmp = src->createMateria("unknown");
    if (tmp)
    {
        std::cout << "WARNING: Created unknown materia (unexpected)" << std::endl;
        delete tmp; // Nettoyer si jamais cela se produit
    }
    else
    {
        std::cout << "Failed to create unknown materia (expected behavior)" << std::endl;
    }
    
    // Test 9 : Test d'assignation (opérateur =) 
    std::cout << "\n========== Testing : assignement operator ==========\n" << std::endl; 

    // ÉTAPE 1: Création de deux personnages avec des materias différentes
    std::cout << "ÉTAPE 1: Création de deux personnages distincts" << std::endl; 
    Character* original = new Character("Original"); 
    tmp = src->createMateria("ice"); 
    original->equip(tmp); 
    std::cout << "Le personnage Original est équipé d'une materia de glace" << std::endl; 

    Character* assigned = new Character("WillBeAssigned"); 
    tmp = src->createMateria("cure"); 
    assigned->equip(tmp); 
    std::cout << "Le personnage WillBeAssigned est équipé d'une materia de soin" << std::endl; 

    // ÉTAPE 2: Vérification de l'état initial - les deux personnages ont des materias différentes
    std::cout << "\nÉTAPE 2: Vérification de l'état initial" << std::endl; 
    std::cout << "Personnage Original utilise sa materia:" << std::endl; 
    original->use(0, *bob); 
    std::cout << "Personnage WillBeAssigned utilise sa materia:" << std::endl; 
    assigned->use(0, *bob); 

    // ÉTAPE 3: Application de l'opérateur d'assignation
    std::cout << "\nÉTAPE 3: Application de l'opérateur d'assignation (WillBeAssigned = Original)" << std::endl; 
    *assigned = *original; // Cette ligne devrait créer une copie profonde

    // ÉTAPE 4: Vérification après assignation - les deux personnages devraient avoir la même materia
    std::cout << "\nÉTAPE 4: Vérification après assignation" << std::endl; 
    std::cout << "Personnage Original utilise sa materia:" << std::endl; 
    original->use(0, *bob); 
    std::cout << "Personnage WillBeAssigned utilise sa materia:" << std::endl; 
    assigned->use(0, *bob); 

    // ÉTAPE 5: Au lieu de déséquiper puis réequiper, nous allons simplement équiper une deuxième materia
    std::cout << "\nÉTAPE 5: Équipement d'une nouvelle materia (cure) dans le slot 1 du personnage Original" << std::endl; 
    tmp = src->createMateria("cure"); 
    original->equip(tmp); // Équipe dans le slot 1, sans toucher au slot 0

    // ÉTAPE 6: Vérification finale - si la copie est profonde, seul le personnage original a changé
    std::cout << "\nÉTAPE 6: Vérification de l'indépendance (test de copie profonde)" << std::endl; 
    std::cout << "Personnage Original utilise sa materia originale (slot 0):" << std::endl; 
    original->use(0, *bob); // Toujours ice
    std::cout << "Personnage Original utilise sa nouvelle materia (slot 1):" << std::endl; 
    original->use(1, *bob); // Maintenant cure aussi
    std::cout << "Personnage WillBeAssigned utilise sa materia (slot 0):" << std::endl; 
    assigned->use(0, *bob); // Devrait toujours être ice si la copie est profonde
    std::cout << "Personnage WillBeAssigned essaie d'utiliser le slot 1 (qui devrait être vide):" << std::endl; 
    assigned->use(1, *bob); // Devrait être vide si la copie est profonde

    // CONCLUSION DU TEST
    std::cout << "\nCONCLUSION:" << std::endl; 
    std::cout << "✓ Le personnage Original a maintenant une materia supplémentaire" << std::endl;
    std::cout << "✓ Le personnage WillBeAssigned n'a pas cette deuxième materia" << std::endl;
    std::cout << "✓ Preuve que la copie est PROFONDE et non SUPERFICIELLE" << std::endl;
    
    // Test 10 : Test d'indices invalides
    std::cout << "\n=== Testing Invalid Indices ===" << std::endl;
    std::cout << "Using materia at invalid index (-1): ";
    me->use(-1, *bob);
    std::cout << "Using materia at invalid index (99): ";
    me->use(99, *bob);
    
    // Test 11 : Nettoyage final
    std::cout << "\n=== Final Cleanup ===" << std::endl;
    delete max_char;
    delete original;
    delete assigned;
    delete carlito_copy;
    delete carlito;
    delete bob;
    delete me;
    delete src;
    
    std::cout << "\n=== End of main ===" << std::endl;
    return 0;
}