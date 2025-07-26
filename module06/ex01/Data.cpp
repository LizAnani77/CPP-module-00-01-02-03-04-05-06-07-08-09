#include "Data.hpp"
#include <iostream>

// Constructeur par défaut
// Initialise avec des valeurs par défaut pour faciliter les tests
Data::Data() : id(0), name("default"), value(0.0)
{
    // Pas de message pour éviter de polluer la sortie
}

// Constructeur avec paramètres
// Permet de créer des objets avec des valeurs spécifiques
Data::Data(int _id, const std::string &_name, double _value)
    : id(_id), name(_name), value(_value)
{
    // Pas de message pour éviter de polluer la sortie
}

// Méthode pour afficher les données
// Affiche toutes les données membres dans un format lisible
void Data::display() const
{
    std::cout << "Data: { ";
    std::cout << "id: " << id << ", ";
    std::cout << "name: \"" << name << "\", ";
    std::cout << "value: " << value;
    std::cout << " }" << std::endl;
}