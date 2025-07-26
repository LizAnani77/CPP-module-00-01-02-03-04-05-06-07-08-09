#include "Array.hpp"         // Notre classe template Array
#include <iostream>          // Pour std::cout, std::endl
#include <string>            // Pour std::string
#include <cstdlib>           // Pour rand, srand
#include <ctime>             // Pour time


// #include <iostream>
// #include <Array.hpp>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

// #define MAX_VAL 750                               // Définit une constante pour la taille des tableaux (750 éléments)
// int main(int, char**)                             
// {
//     Array<int> numbers(MAX_VAL);                  // Crée un Array<int> de 750 éléments (utilise le constructeur avec taille)
//     int* mirror = new int[MAX_VAL];               // Crée un tableau C standard de 750 entiers pour comparaison
//     srand(time(NULL));                            // Initialise le générateur de nombres aléatoires avec l'heure actuelle
//     for (int i = 0; i < MAX_VAL; i++)             // Boucle sur tous les éléments des tableaux
//     {
//         const int value = rand();                 // Génère une valeur aléatoire
//         numbers[i] = value;                       // Assigne cette valeur à l'élément i de l'Array (teste l'opérateur [])
//         mirror[i] = value;                        // Assigne la même valeur au tableau miroir
//     }
//     //SCOPE                                       // Début d'un bloc de portée pour tester les constructeurs/destructeurs
//     {
//         Array<int> tmp = numbers;                 // Crée une copie de numbers (teste l'opérateur d'affectation)
//         Array<int> test(tmp);                     // Crée un Array à partir de tmp (teste le constructeur de copie)
//     }                                             // Fin du bloc - tmp et test sont détruits ici (teste le destructeur)
    
//     for (int i = 0; i < MAX_VAL; i++)             // Boucle pour vérifier l'intégrité des données
//     {
//         if (mirror[i] != numbers[i])              // Vérifie que la valeur dans numbers correspond à celle dans mirror
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;  // Affiche un message d'erreur en cas d'incohérence
//             return 1;                             // Quitte le programme avec un code d'erreur
//         }
//     }
    
//     try                                           // Début d'un bloc try pour tester la gestion des exceptions
//     {
//         numbers[-2] = 0;                          // Tente d'accéder à un index négatif (invalide)
//     }
//     catch(const std::exception& e)                // Capture l'exception lancée
//     {
//         std::cerr << e.what() << '\n';            // Affiche le message d'erreur de l'exception
//     }
    
//     try                                           // Début d'un autre bloc try
//     {
//         numbers[MAX_VAL] = 0;                     // Tente d'accéder à un index hors limites (MAX_VAL)
//     }
//     catch(const std::exception& e)                // Capture l'exception lancée
//     {
//         std::cerr << e.what() << '\n';            // Affiche le message d'erreur
//     }

//     for (int i = 0; i < MAX_VAL; i++)             // Boucle sur tous les éléments du tableau numbers
//     {
//         numbers[i] = rand();                      // Change chaque valeur par une nouvelle valeur aléatoire
//     }
    
//     delete [] mirror;                             // Libère la mémoire allouée pour le tableau miroir
//     return 0;                                     // Termine le programme avec un code de succès
// }





// // Affiche un séparateur visuel pour améliorer la lisibilité de la sortie
// void printSeparator(const std::string &title)
// {
//     std::cout << "\n";                                                      // Ligne vide pour l'espacement
//     std::cout << "===============================================" << std::endl;   // Ligne supérieure
//     std::cout << title << std::endl;                                        // Titre du séparateur
//     std::cout << "===============================================" << std::endl;   // Ligne inférieure
//     std::cout << "\n";                                                      // Ligne vide pour l'espacement
// }

// int main()
// {
//     std::cout << "===============================================" << std::endl;
//     std::cout << "============== ARRAY CLASS TESTS ==============" << std::endl;
//     std::cout << "===============================================" << std::endl;

//     // Test du constructeur par défaut
//     printSeparator("DEFAULT CONSTRUCTOR TEST");
//     Array<int> emptyArray;      // Crée un tableau vide
//     std::cout << "Empty array size: " << emptyArray.size() << std::endl;  // Affiche la taille (devrait être 0)
    
//     // Test du constructeur avec taille
//     printSeparator("SIZED CONSTRUCTOR TEST");
//     Array<int> intArray(5);     // Crée un tableau de 5 entiers
//     std::cout << "Integer array size: " << intArray.size() << std::endl;  // Affiche la taille (devrait être 5)
    
//     // Affiche les valeurs par défaut
//     std::cout << "Default values: ";
//     for (unsigned int i = 0; i < intArray.size(); i++)
//     {
//         std::cout << intArray[i] << " ";  // Les entiers sont initialisés à 0 par défaut
//     }
//     std::cout << std::endl;
    
//     // Modifie les valeurs
//     std::cout << "Setting values..." << std::endl;
//     for (unsigned int i = 0; i < intArray.size(); i++)
//     {
//         intArray[i] = i * 10;   // Assigne i*10 à chaque élément
//     }
    
//     // Affiche les nouvelles valeurs
//     std::cout << "New values: ";
//     for (unsigned int i = 0; i < intArray.size(); i++)
//     {
//         std::cout << intArray[i] << " ";  // Affiche les nouvelles valeurs
//     }
//     std::cout << std::endl;

//     // Test du constructeur de copie
//     printSeparator("COPY CONSTRUCTOR TEST");
//     Array<int> copiedArray(intArray);  // Crée une copie de intArray
    
//     std::cout << "Original array: ";
//     for (unsigned int i = 0; i < intArray.size(); i++)
//     {
//         std::cout << intArray[i] << " ";  // Affiche les valeurs de l'original
//     }
//     std::cout << std::endl;
    
//     std::cout << "Copied array: ";
//     for (unsigned int i = 0; i < copiedArray.size(); i++)
//     {
//         std::cout << copiedArray[i] << " ";  // Affiche les valeurs de la copie
//     }
//     std::cout << std::endl;
    
//     // Modifie l'original pour montrer que la copie est indépendante
//     std::cout << "Modifying original array..." << std::endl;
//     for (unsigned int i = 0; i < intArray.size(); i++)
//     {
//         intArray[i] = i * 5;  // Change les valeurs dans l'original
//     }
    
//     std::cout << "Original array after modification: ";
//     for (unsigned int i = 0; i < intArray.size(); i++)
//     {
//         std::cout << intArray[i] << " ";  // Affiche les nouvelles valeurs de l'original
//     }
//     std::cout << std::endl;
    
//     std::cout << "Copied array (should be unchanged): ";
//     for (unsigned int i = 0; i < copiedArray.size(); i++)
//     {
//         std::cout << copiedArray[i] << " ";  // La copie ne devrait pas être affectée
//     }
//     std::cout << std::endl;

//     // Test de l'opérateur d'affectation
//     printSeparator("ASSIGNMENT OPERATOR TEST");
//     Array<int> assignedArray;         // Crée un tableau vide
//     assignedArray = intArray;         // Utilise l'opérateur d'affectation
    
//     std::cout << "Original array: ";
//     for (unsigned int i = 0; i < intArray.size(); i++)
//     {
//         std::cout << intArray[i] << " ";  // Affiche les valeurs de l'original
//     }
//     std::cout << std::endl;
    
//     std::cout << "Assigned array: ";
//     for (unsigned int i = 0; i < assignedArray.size(); i++)
//     {
//         std::cout << assignedArray[i] << " ";  // Affiche les valeurs du tableau assigné
//     }
//     std::cout << std::endl;
    
//     // Modifie l'original pour montrer que la copie est indépendante
//     std::cout << "Modifying original array..." << std::endl;
//     for (unsigned int i = 0; i < intArray.size(); i++)
//     {
//         intArray[i] = i * 3;  // Change les valeurs dans l'original
//     }
    
//     std::cout << "Original array after modification: ";
//     for (unsigned int i = 0; i < intArray.size(); i++)
//     {
//         std::cout << intArray[i] << " ";  // Affiche les nouvelles valeurs de l'original
//     }
//     std::cout << std::endl;
    
//     std::cout << "Assigned array (should be unchanged): ";
//     for (unsigned int i = 0; i < assignedArray.size(); i++)
//     {
//         std::cout << assignedArray[i] << " ";  // Le tableau assigné ne devrait pas être affecté
//     }
//     std::cout << std::endl;

//     // Test avec d'autres types de données
//     printSeparator("DIFFERENT TYPES TEST");
    
//     // Test avec des strings
//     Array<std::string> stringArray(3);  // Crée un tableau de 3 strings
//     stringArray[0] = "Hello";
//     stringArray[1] = "World";
//     stringArray[2] = "42";
    
//     std::cout << "String array: ";
//     for (unsigned int i = 0; i < stringArray.size(); i++)
//     {
//         std::cout << stringArray[i] << " ";  // Affiche les strings
//     }
//     std::cout << std::endl;
    
//     // Test avec des flottants
//     Array<float> floatArray(4);  // Crée un tableau de 4 flottants
//     for (unsigned int i = 0; i < floatArray.size(); i++)
//     {
//         floatArray[i] = i * 1.5f;  // Assigne i*1.5 à chaque élément
//     }
    
//     std::cout << "Float array: ";
//     for (unsigned int i = 0; i < floatArray.size(); i++)
//     {
//         std::cout << floatArray[i] << " ";  // Affiche les flottants
//     }
//     std::cout << std::endl;

//     // Test des exceptions
//     printSeparator("EXCEPTION TESTS");
    
//     try 
//     {
//         std::cout << "Trying to access emptyArray[0]..." << std::endl;
//         std::cout << emptyArray[0] << std::endl;  // Devrait lancer une exception
//     } 
//     catch (std::exception &e) 
//     {
//         std::cout << "Exception caught: " << e.what() << std::endl;  // Affiche le message d'erreur
//     }
    
//     try 
//     {
//         std::cout << "Trying to access intArray[5] (out of bounds)..." << std::endl;
//         std::cout << intArray[5] << std::endl;  // Devrait lancer une exception
//     } 
//     catch (std::exception &e) 
//     {
//         std::cout << "Exception caught: " << e.what() << std::endl;  // Affiche le message d'erreur
//     }

//     // Test avec un tableau plus grand et des valeurs aléatoires
//     printSeparator("RANDOM VALUES TEST");
//     srand(time(NULL));  // Initialise le générateur de nombres aléatoires
    
//     Array<int> randomArray(10);  // Crée un tableau de 10 entiers
//     for (unsigned int i = 0; i < randomArray.size(); i++)
//     {
//         randomArray[i] = rand() % 100;  // Assigne une valeur aléatoire entre 0 et 99
//     }
    
//     std::cout << "Random array: ";
//     for (unsigned int i = 0; i < randomArray.size(); i++)
//     {
//         std::cout << randomArray[i] << " ";  // Affiche les valeurs aléatoires
//     }
//     std::cout << std::endl;

//     // Test plus détaillé des exceptions pour les accès hors limites
//     printSeparator("DETAILED EXCEPTION TEST");

//     // Créer un tableau de taille 3
//     Array<int> testArray(3);
//     testArray[0] = 10;
//     testArray[1] = 20;
//     testArray[2] = 30;

//     std::cout << "Created array of size 3 with values: ";
//     for (unsigned int i = 0; i < testArray.size(); i++)
//     {
//         std::cout << testArray[i] << " ";
//     }
//     std::cout << std::endl;

//     // Test d'accès à des indices valides
//     try 
//     {
//         std::cout << "Accessing valid index 0: " << testArray[0] << std::endl;
//         std::cout << "Accessing valid index 2: " << testArray[2] << std::endl;
//     } 
//     catch (std::exception &e) 
//     {
//         std::cout << "Unexpected exception: " << e.what() << std::endl;
//     }

//     // Test d'accès à différents indices invalides
//     try 
//     {
//         std::cout << "Trying to access index 3 (just beyond array bounds)..." << std::endl;
//         std::cout << testArray[3] << std::endl;  // Premier index invalide
//     } 
//     catch (std::exception &e) 
//     {
//         std::cout << "Exception caught (as expected): " << e.what() << std::endl;
//     }

//     try 
//     {
//         std::cout << "Trying to access index 100 (far beyond array bounds)..." << std::endl;
//         std::cout << testArray[100] << std::endl;  // Index très loin des limites
//     } 
//     catch (std::exception &e) 
//     {
//         std::cout << "Exception caught (as expected): " << e.what() << std::endl;
//     }

//     try 
//     {
//         // Test avec un tableau vide, syntaxe qui appelle le constructeur par defaut 
//         Array<int> emptyTestArray;
//         std::cout << "Trying to access index 0 of an empty array..." << std::endl;
//         std::cout << emptyTestArray[0] << std::endl;  // Toute tentative d'accès devrait échouer
//     } 
//     catch (std::exception &e) 
//     {
//         std::cout << "Exception caught (as expected): " << e.what() << std::endl;
//     }

//     // Test de modification via un index hors limites
//     try 
//     {
//         std::cout << "Trying to modify element at index 5..." << std::endl;
//         testArray[5] = 500;  // Tente de modifier un élément hors limites
//     } 
//     catch (std::exception &e) 
//     {
//         std::cout << "Exception caught (as expected): " << e.what() << std::endl;
//     }

//     // Test pour comprendre l'initialisation par défaut (mentionné dans l'astuce de l'exercice)
//     printSeparator("DEFAULT INITIALIZATION TIP TEST");
        
//     // Allouer un entier avec initialisation par défaut
//     int * a = new int();
//     std::cout << "Value of *a after 'int * a = new int();': " << *a << std::endl;
        
//     // Modifier la valeur pour montrer qu'elle a bien été initialisée
//     *a = 42;
//     std::cout << "Value after modification: " << *a << std::endl;
        
//     // IMPORTANT: Libérer la mémoire pour éviter les fuites
//     delete a;
//     std::cout << "Memory has been properly freed" << std::endl;

//         std::cout << "\n===============================================" << std::endl;
//         std::cout << "============= TESTS COMPLETED =================" << std::endl;
//         std::cout << "===============================================" << std::endl;

//         return 0;
//     }