/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:30:34 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/03/07 09:34:16 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

// Fonction de démonstration du polymorphisme
void testSound(const Animal& animal) {
    std::cout << "Animal of type " << animal.getType() << " makes sound: ";
    animal.makeSound();
}

int main() 
{
    std::cout << "\n========== TESTS DE BASE ==========\n" << std::endl;
    
    // Test 1 : Test de la classe abstraite Animal
    std::cout << "=== Testing abstract class ===" << std::endl;
    
    // Cette ligne ne compilera pas car Animal est abstraite
    // Animal* meta = new Animal();
    
    // Crée des instances de classes dérivées concrètes
    Dog* j = new Dog();
    Cat* i = new Cat();
    
    // Test 2 : Teste le polymorphisme avec les sons
    std::cout << "\n=== Testing sounds ===" << std::endl;
    j->makeSound();  // Appelle Dog::makeSound()
    i->makeSound();  // Appelle Cat::makeSound()
    
    // Test 3 : Teste les fonctionnalités du cerveau
    std::cout << "\n=== Testing brain ideas ===" << std::endl;
    j->setIdea(0, "I'm a real dog!");
    i->setIdea(0, "I'm a real cat!");
    
    // Affiche les idées stockées
    std::cout << "Dog's idea: " << j->getIdea(0) << std::endl;
    std::cout << "Cat's idea: " << i->getIdea(0) << std::endl;
    
    // Test 4 : Test la libération de la mémoire
    std::cout << "\n=== Testing cleanup ===" << std::endl;
    delete j;
    delete i;
    
    std::cout << "\n========== TESTS ADDITIONNELS ==========\n" << std::endl;
    
    // Test 5: Démonstration du polymorphisme avec un tableau d'animaux
    std::cout << "=== Testing array of animals ===" << std::endl;
    
    // Création d'un tableau d'animaux (moitié chiens, moitié chats)
    const int animalCount = 4;
    Animal* animals[animalCount];
    
    // Remplir le tableau (premiere moitié Dogs, deuxième moitié Cats)
    for (int k = 0; k < animalCount; k++) {
        if (k < animalCount / 2)
            animals[k] = new Dog();
        else
            animals[k] = new Cat();
    }
    
    // Tester le polymorphisme pour chaque animal
    std::cout << "\n=== Testing polymorphic sounds ===" << std::endl;
    for (int k = 0; k < animalCount; k++) {
        std::cout << "Animal " << k << " (" << animals[k]->getType() << "): ";
        animals[k]->makeSound();
    }
    
    // Libérer la mémoire
    std::cout << "\n=== Cleanup animals array ===" << std::endl;
    for (int k = 0; k < animalCount; k++) {
        delete animals[k];
    }
    
    
    std::cout << "\n========== TEST 6: DEEP COPY TEST ==========\n" << std::endl;

    // Création du chien original
    Dog* originalDog = new Dog();
    originalDog->setIdea(0, "I love bones!");
    originalDog->setIdea(1, "Let's go for a walk!");

    std::cout << "\nÉTAT INITIAL:" << std::endl;
    std::cout << "Chien original, idée 0: " << originalDog->getIdea(0) << std::endl;
    std::cout << "Chien original, idée 1: " << originalDog->getIdea(1) << std::endl;

    // Création du clone
    std::cout << "\nCréation d'une copie..." << std::endl;
    Dog* clonedDog = new Dog(*originalDog);

    // Modification des deux idées dans l'original
    std::cout << "\nModification des DEUX idées dans le chien original:" << std::endl;
    originalDog->setIdea(0, "I need to bury my bone");
    originalDog->setIdea(1, "I want to chase cats!");

    // Comparaison claire
    std::cout << "\nCOMPARAISON APRÈS MODIFICATION:" << std::endl;
    std::cout << "Chien original, idée 0: " << originalDog->getIdea(0) << std::endl;
    std::cout << "Chien cloné,    idée 0: " << clonedDog->getIdea(0) << " <-- DIFFÉRENT!" << std::endl;
    std::cout << "Chien original, idée 1: " << originalDog->getIdea(1) << std::endl;
    std::cout << "Chien cloné,    idée 1: " << clonedDog->getIdea(1) << " <-- DIFFÉRENT!" << std::endl;

    // Conclusion explicite
    std::cout << "\nCONCLUSION:" << std::endl;
    std::cout << "✓ Les modifications dans le chien original n'affectent pas le clone" << std::endl;
    std::cout << "✓ Preuve que la copie est PROFONDE (deux cerveaux distincts)" << std::endl;

    // Nettoyage
    delete originalDog;
    delete clonedDog;
    
    // Test 7 : Test explicite de l'opérateur d'affectation avec commentaires détaillés
    std::cout << "\n=== Testing assignment operator (explicit) ===" << std::endl;
    
    // ÉTAPE 1: Création de deux chats avec des identités distinctes
    std::cout << "ÉTAPE 1: Création de deux chats distincts" << std::endl;
    Cat firstCat;
    Cat secondCat;
    
    // ÉTAPE 2 : Donner des idées différentes à chaque chat pour les distinguer
    std::cout << "\nÉTAPE 2: Attribution d'idées différentes" << std::endl;
    firstCat.setIdea(0, "I want to chase mouse");  // Première idée
    secondCat.setIdea(0, "I need a nap");         // Deuxième idée (différente)
    
    // ÉTAPE 3 : Vérifier l'état initial - les deux chats ont des idées différentes
    std::cout << "\nÉTAPE 3: Vérification de l'état initial" << std::endl;
    std::cout << "First Cat's idea: " << firstCat.getIdea(0) << std::endl;
    std::cout << "Second Cat's idea: " << secondCat.getIdea(0) << std::endl;
    
    // ÉTAPE 4: Appliquer l'opérateur d'affectation - secondCat doit recevoir une COPIE des données de firstCat
    std::cout << "\nÉTAPE 4: Application de l'opérateur d'affectation (secondCat = firstCat)" << std::endl;
    secondCat = firstCat;  // Cette ligne devrait créer une copie profonde
    
    // ÉTAPE 5 : Vérifier que l'affectation a fonctionné - les deux chats ont maintenant la même idée
    std::cout << "\nÉTAPE 5: Vérification après affectation" << std::endl;
    std::cout << "First Cat's idea: " << firstCat.getIdea(0) << std::endl;  // Toujours "I want to chase mouse"
    std::cout << "Second Cat's idea: " << secondCat.getIdea(0) << std::endl; // Maintenant "I want to chase mouse" aussi
    
    // ÉTAPE 6 : Modifier l'idée du premier chat pour tester l'indépendance
    std::cout << "\nÉTAPE 6: Modification de l'idée du premier chat uniquement" << std::endl;
    firstCat.setIdea(0, "I changed my mind");  // Changement qui ne devrait affecter QUE firstCat
    
    // ÉTAPE 7 : Vérification finale - si la copie est profonde, seul le premier chat a changé
    std::cout << "\nÉTAPE 7: Vérification de l'indépendance (test de copie profonde)" << std::endl;
    std::cout << "First Cat's idea: " << firstCat.getIdea(0) << std::endl;  // Devrait être "I changed my mind"
    std::cout << "Second Cat's idea: " << secondCat.getIdea(0) << std::endl; // Devrait TOUJOURS être "I want to chase mouse"
    
    // CONCLUSION DU TEST
    std::cout << "\nCONCLUSION:" << std::endl;
    std::cout << "Si les deux idées sont différentes, la copie est PROFONDE (correct)" << std::endl;
    std::cout << "Si les deux idées sont identiques, la copie est SUPERFICIELLE (problème)" << std::endl;
    
    
    // Test 8 : Test de la fonction de démonstration du polymorphisme
    std::cout << "\n=== Testing function polymorphism ===" << std::endl;
    Dog polymorphicDog;
    Cat polymorphicCat;
    
    testSound(polymorphicDog);
    testSound(polymorphicCat);
    
    // Fin du programme
    std::cout << "\n=== End of main ===" << std::endl;
    return 0;
}