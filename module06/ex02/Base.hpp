#ifndef BASE_HPP
# define BASE_HPP

class Base
{
public:
    // Destructeur virtuel pour permettre une destruction propre à travers un pointeur de base
    // Élément essentiel pour le polymorphisme et la libération correcte des ressources
    virtual ~Base();
};

#endif