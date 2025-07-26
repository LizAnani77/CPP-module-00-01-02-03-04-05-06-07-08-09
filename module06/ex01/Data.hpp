#ifndef DATA_HPP
# define DATA_HPP

# include <string>

// Structure de données simple avec quelques membres pour les tests
// Utilisée pour démontrer le processus de sérialisation/désérialisation
struct Data
{
    int         id;        // Identifiant numérique
    std::string name;      // Chaîne de caractères représentant un nom
    double      value;     // Valeur numérique à virgule flottante
    
    // Constructeur par défaut
    // Initialise les membres avec des valeurs simples
    Data();
    
    // Constructeur avec paramètres
    // Permet l'initialisation avec des valeurs spécifiques
    Data(int _id, const std::string &_name, double _value);
    
    // Méthode pour afficher les données
    // Facilite la visualisation de l'état de l'objet pour les tests
    void display() const;
};

#endif