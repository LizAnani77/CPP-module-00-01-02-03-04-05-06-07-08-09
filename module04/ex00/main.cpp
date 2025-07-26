/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:30:34 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/03/06 13:54:18 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() 
{
    // Test 1 : Test des constructeurs
    std::cout << "=== Test constructors ===" << std::endl;
    const Animal* meta = new Animal();  // Animal générique
    const Animal* j = new Dog();        // Dog via pointeur Animal
    const Animal* i = new Cat();        // Cat via pointeur Animal

    // Test 2 : Test des types
    std::cout << "\n=== Test types ===" << std::endl;
    std::cout << "J type: " << j->getType() << std::endl;
    std::cout << "I type: " << i->getType() << std::endl;

    // Test 3 : Test des sons (démontre le polymorphisme)
    std::cout << "\n=== Test sounds ===" << std::endl;
    i->makeSound();      // Son du Chat
    j->makeSound();      // Son du Chien
    meta->makeSound();   // Son Animal générique

    // Test 4 : Test des destructeurs
    std::cout << "\n=== Test destructors ===" << std::endl;
    delete meta;  // Destructeur Animal
    delete j;     // Destructeur Dog puis Animal
    delete i;     // Destructeur Cat puis Animal

    // Test 5 : Test des classes sans polymorphisme
    std::cout << "\n=== Test WrongAnimal ===" << std::endl;
    const WrongAnimal* wrong_meta = new WrongAnimal();  // WrongAnimal générique
    const WrongAnimal* wrong_cat = new WrongCat();      // WrongCat via pointeur WrongAnimal

    // Test 6 : Test des sons (démontre l'absence de polymorphisme)
    std::cout << "\n=== Test WrongAnimal sounds ===" << std::endl;
    wrong_cat->makeSound();   // Son WrongAnimal (pas WrongCat!)
    wrong_meta->makeSound();  // Son WrongAnimal

    // Test 7 : Test des destructeurs
    std::cout << "\n=== Test WrongAnimal destructors ===" << std::endl;
    delete wrong_cat;   // Problème potentiel: seul le destructeur WrongAnimal est appelé
    delete wrong_meta;  // Destructeur WrongAnimal
    
    // Test 8 : Test explicite de l'opérateur d'affectation avec commentaires détaillés
    // Contrairement aux exercices 01 et 02, les classes ici n'ont pas de ressources
    // dynamiques (pas de pointeurs) ni d'attributs modifiables publiquement. 
    // L'affichage des adresses mémoire nous permet de vérifier que les objets
    // restent distincts après l'affectation, confirmant que l'opérateur=
    // crée bien une copie indépendante et n'établit pas de lien entre les objets.
    
    std::cout << "\n=== Testing assignment operator (explicit) ===" << std::endl;
    
    // ÉTAPE 1: Création de deux cats avec des identités distinctes
    std::cout << "ÉTAPE 1: Création de deux cats distincts" << std::endl;
    Cat firstCat;
    Cat secondCat;
    
    // ÉTAPE 2: Définir des attributs différents pour les distinguer
    std::cout << "\nÉTAPE 2: Attribution de types différents (pour démonstration)" << std::endl;
    // Note: Dans cet exercice, on ne peut pas modifier le type directement car il est protected
    // Cette étape est donc symbolique pour montrer le principe
    std::cout << "First Cat type: " << firstCat.getType() << std::endl;
    std::cout << "Second Cat type: " << secondCat.getType() << std::endl;
    
    // ÉTAPE 3: Vérifier l'état initial des objets
    std::cout << "\nÉTAPE 3: Vérification de l'état initial" << std::endl;
    std::cout << "First Cat: "; firstCat.makeSound();
    std::cout << "Second Cat: "; secondCat.makeSound();
    
    // ÉTAPE 4: Appliquer l'opérateur d'affectation
    std::cout << "\nÉTAPE 4: Application de l'opérateur d'affectation (secondCat = firstCat)" << std::endl;
    secondCat = firstCat;  // Cette ligne devrait appeler l'opérateur d'affectation
    
    // ÉTAPE 5: Vérifier que l'affectation a conservé les comportements
    std::cout << "\nÉTAPE 5: Vérification après affectation" << std::endl;
    std::cout << "First Cat: "; firstCat.makeSound();
    std::cout << "Second Cat: "; secondCat.makeSound();
    
    // ÉTAPE 6: Vérifier que les objets restent distincts
    std::cout << "\nÉTAPE 6: Vérification de l'indépendance des objets" << std::endl;
    std::cout << "Adresse de firstCat: " << &firstCat << std::endl;
    std::cout << "Adresse de secondCat: " << &secondCat << std::endl;
    
    // CONCLUSION DU TEST
    std::cout << "\nCONCLUSION:" << std::endl;
    std::cout << "Si les adresses sont différentes mais les comportements identiques," << std::endl;
    std::cout << "l'opérateur d'affectation fonctionne correctement." << std::endl;
    
    // Test 9 : Test d'opérateur d'affectation pour WrongCat (pour comparaison)
    std::cout << "\n=== Testing WrongCat assignment operator ===" << std::endl;
    WrongCat firstWrongCat;
    WrongCat secondWrongCat;
    
    std::cout << "Before assignment:" << std::endl;
    std::cout << "First WrongCat: "; firstWrongCat.makeSound();
    std::cout << "Second WrongCat: "; secondWrongCat.makeSound();
    
    secondWrongCat = firstWrongCat;  // Utilise l'opérateur d'affectation
    
    std::cout << "After assignment:" << std::endl;
    std::cout << "First WrongCat: "; firstWrongCat.makeSound();
    std::cout << "Second WrongCat: "; secondWrongCat.makeSound();
    
    // Fin du programme
    std::cout << "\n=== End of main ===" << std::endl;
    return 0;
}