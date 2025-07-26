#include "Serializer.hpp"

// Constructeur par défaut - utilisé uniquement en interne
// La classe ne devant pas être instanciée, il est privé et vide
Serializer::Serializer()
{
    // Vide - ne pas afficher de message car la classe n'est jamais instanciée
}

// Constructeur de copie - utilisé uniquement en interne
// Même raison que pour le constructeur par défaut
Serializer::Serializer(const Serializer &src)
{
    // Vide - éviter les warnings du compilateur
    (void)src;
}

// Opérateur d'affectation - utilisé uniquement en interne
// Même raison que pour les constructeurs
Serializer &Serializer::operator=(const Serializer &rhs)
{
    // Vide - éviter les warnings du compilateur
    (void)rhs;
    return *this;
}

// Destructeur
// Il n'y a rien à libérer car la classe est statique et non instanciable
Serializer::~Serializer()
{
    // Vide - ne pas afficher de message car la classe n'est jamais instanciée
}

// Sérialisation - convertit un pointeur de Data en uintptr_t
// Utilise reinterpret_cast pour réinterpréter les bits du pointeur en entier
uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

// Désérialisation - convertit un uintptr_t en pointeur de Data
// Utilise reinterpret_cast pour réinterpréter les bits de l'entier en pointeur
Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}