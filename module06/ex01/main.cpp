#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>
#include <iomanip> // Pour std::hex et std::dec

// Affiche un séparateur visuel pour améliorer la lisibilité de la sortie
// Permet de distinguer clairement les différentes parties des tests
void printSeparator(const std::string &title)
{
    std::cout << "\n";
    std::cout << "===============================================" << std::endl;
    std::cout << title << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "\n";
}

// Fonction pour tester la sérialisation et désérialisation
// Démontre le processus complet avec vérifications
void testSerialization()
{
    printSeparator("SERIALIZATION AND DESERIALIZATION TEST");
    
    // Création d'un objet Data pour les tests
    // Utilise différents types de données pour valider la préservation complète
    Data original(42, "Hello World", 3.14159);
    
    // Affichage des informations de l'objet original
    std::cout << "Original object:" << std::endl;
    original.display();
    std::cout << "Original object address: " << &original;
    std::cout << " (hex: 0x" << std::hex << reinterpret_cast<uintptr_t>(&original) << std::dec << ")" << std::endl;
    
    // Sérialisation de l'objet
    // Conversion du pointeur en valeur numérique via reinterpret_cast
    uintptr_t serialized = Serializer::serialize(&original);
    std::cout << "\nSerialized value (uintptr_t): " << serialized;
    std::cout << " (hex: 0x" << std::hex << serialized << std::dec << ")" << std::endl;
    
    // Désérialisation de l'objet
    // Reconversion de la valeur numérique en pointeur
    Data *deserialized = Serializer::deserialize(serialized);
    
    // Vérification que l'objet désérialisé est identique à l'original
    std::cout << "\nDeserialized object:" << std::endl;
    deserialized->display();
    std::cout << "Deserialized object address: " << deserialized;
    std::cout << " (hex: 0x" << std::hex << reinterpret_cast<uintptr_t>(deserialized) << std::dec << ")" << std::endl;
    
    // Vérification de l'égalité des adresses
    // Confirme que le pointeur original et désérialisé pointent vers le même objet
    std::cout << "\nAddress verification:" << std::endl;
    std::cout << "Original address == Deserialized address: ";
    std::cout << ((&original == deserialized) ? "YES" : "NO") << std::endl;
    
    // Modification de l'objet original et vérification que l'objet désérialisé est affecté
    // Démontre que les deux pointeurs référencent le même objet en mémoire
    std::cout << "\nModifying the original object:" << std::endl;
    original.id = 99;
    original.name = "Modified Data";
    original.value = 2.71828;
    
    std::cout << "Original object after modification:" << std::endl;
    original.display();
    
    std::cout << "Deserialized object after original modification:" << std::endl;
    deserialized->display();
    
    // Test supplémentaire pour vérifier l'égalité des données
    std::cout << "\nData equality verification:" << std::endl;
    std::cout << "ID match: " << (original.id == deserialized->id ? "YES" : "NO") << std::endl;
    std::cout << "Name match: " << (original.name == deserialized->name ? "YES" : "NO") << std::endl;
    std::cout << "Value match: " << (original.value == deserialized->value ? "YES" : "NO") << std::endl;
}

// Fonction principale
// Point d'entrée du programme qui exécute les tests
int main()
{
    std::cout << "===============================================" << std::endl;
    std::cout << "========== SERIALIZATION TESTS ================" << std::endl;
    std::cout << "===============================================" << std::endl;
    
    // Exécution des tests
    testSerialization();
    
    std::cout << "\n===============================================" << std::endl;
    std::cout << "============= TESTS COMPLETED =================" << std::endl;
    std::cout << "===============================================" << std::endl;
    
    return 0;
}