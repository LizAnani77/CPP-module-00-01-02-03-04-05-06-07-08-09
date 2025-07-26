#include "Base.hpp"
#include <iostream>

// Destructeur virtuel de Base
// Affiche un message pour tracer l'ordre de destruction des objets
Base::~Base()
{
    std::cout << "Base destructor called" << std::endl;
}