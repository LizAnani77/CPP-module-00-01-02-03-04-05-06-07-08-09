#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include "Data.hpp"

class Serializer
{
private:
    // Constructeur par défaut - privé pour empêcher l'instanciation
    // Cette classe est conçue comme classe utilitaire statique uniquement
    Serializer();
    
    // Constructeur de copie - privé pour empêcher l'instanciation
    // Conforme à la forme canonique orthodoxe
    Serializer(const Serializer &src);
    
    // Opérateur d'affectation - privé pour empêcher l'instanciation
    // Conforme à la forme canonique orthodoxe
    Serializer &operator=(const Serializer &rhs);

public:
    // Destructeur
    // Requis par la forme canonique orthodoxe
    ~Serializer();
    
    // Méthodes statiques pour la sérialisation et désérialisation
    // Convertit un pointeur Data en valeur numérique uintptr_t via reinterpret_cast
    static uintptr_t serialize(Data* ptr);
    // Convertit une valeur numérique uintptr_t en pointeur Data via reinterpret_cast
    static Data* deserialize(uintptr_t raw);
};

#endif