/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:30:34 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/03/06 14:11:59 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() 
{
    //Test 1 : Test de la création d'un tableau d'animaux
    std::cout << "=== Creating array of animals ===" << std::endl;
    Animal* animals[4];
    
    // Remplir le tableau avec des chiens et des chats
    for (int i = 0; i < 4; i++) 
    {
        if (i < 2)
            animals[i] = new Dog();  // Les deux premiers sont des chiens
        else
            animals[i] = new Cat();  // Les deux suivants sont des chats
        std::cout << "---" << std::endl;
    }

    // Test 2 : Teste la copie profonde des objets
    std::cout << "\n=== Testing deep copy ===" << std::endl;
    Dog originalDog;  // Crée un chien original
    originalDog.setIdea(0, "I want to catch a ball!");  // Définit une idée
    
    Dog copyDog = originalDog;  // Utilise le constructeur de copie
    std::cout << "Original dog's idea: " << originalDog.getIdea(0) << std::endl;
    std::cout << "Copy dog's idea: " << copyDog.getIdea(0) << std::endl;
    
    // Modifie l'idée dans la copie pour démontrer la copie profonde
    copyDog.setIdea(0, "I want to sleep!");
    std::cout << "After modification:" << std::endl;
    std::cout << "Original dog's idea: " << originalDog.getIdea(0) << std::endl;
    std::cout << "Copy dog's idea: " << copyDog.getIdea(0) << std::endl;

    // Test 3 : Test la libération de la mémoire
    std::cout << "\n=== Cleaning up array ===" << std::endl;
    for (int i = 0; i < 4; i++) 
    {
        delete animals[i];  // Appelle les destructeurs appropriés
        std::cout << "---" << std::endl;
    }
    
    // Test 4 : Teste les fonctionnalites de Brain
    std::cout << "\n=== Testing Brain functionality ===" << std::endl;
    Dog* einstein = new Dog();

    // Test des idees et des indices
    einstein->setIdea(0, "I think, therefore I am");
    einstein->setIdea(50, "E = mc²");
    einstein->setIdea(99, "Last valid idea");

    // Affichage des idees
    std::cout << "Idea 0: " << einstein->getIdea(0) << std::endl;
    std::cout << "Idea 50: " << einstein->getIdea(50) << std::endl;
    std::cout << "Idea 99: " << einstein->getIdea(99) << std::endl;

    // Test des limites
    einstein->setIdea(100, "This should not be stored");
    std::cout << "Idea 100 (invalid): " << einstein->getIdea(100) << std::endl;

    einstein->setIdea(-1, "This shouldn't be stored either");
    std::cout << "Idea -1 (invalid): " << einstein->getIdea(-1) << std::endl;

    // Test 5 : Teste les modifications d'idee
    std::cout << "\n=== Testing idea modifications ===" << std::endl;
    std::cout << "Idea 50 before modification: " << einstein->getIdea(50) << std::endl;
    einstein->setIdea(50, "E = ...?");
    std::cout << "Idea 50 after modification: " << einstein->getIdea(50) << std::endl;

    // Test 6 : Test explicite de l'opérateur d'affectation avec commentaires détaillés
    std::cout << "\n=== Testing assignment operator (explicit) ===" << std::endl;

    // ÉTAPE 1 : Création de deux chats avec des identités distinctes
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

    // ÉTAPE 4 : Appliquer l'opérateur d'affectation - secondCat doit recevoir une COPIE des données de firstCat
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

    // Test 7 : Test des destructeurs
    std::cout << "\n=== Test destructors ===" << std::endl;
    delete einstein;

    // Fin du programme
    std::cout << "\n=== End of main ===" << std::endl;
    return 0;
}