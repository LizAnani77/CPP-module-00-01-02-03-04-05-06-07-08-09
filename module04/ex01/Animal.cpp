/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 21:42:03 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/25 19:02:17 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Constructeur par défaut - initialise avec "Unknown"
Animal::Animal() : type("Unknown") 
{
    std::cout << "🐾 Animal default constructor called" << std::endl;
}

// Constructeur de copie - duplique un Animal existant
Animal::Animal(const Animal& other) : type(other.type) 
{
    std::cout << "🐾 Animal copy constructor called" << std::endl;
}

// Destructeur - libère les ressources et affiche un message
Animal::~Animal() 
{
    std::cout << "🐾 Animal destructor called" << std::endl;
}

// Opérateur d'affectation - copie les attributs
Animal& Animal::operator=(const Animal& other) 
{
    std::cout << "🐾 Animal assignment operator called" << std::endl;
    if (this != &other)
        type = other.type;
    return *this;
}

// Méthode virtuelle pour émettre un son spécifique à l'animal
void Animal::makeSound() const 
{
    std::cout << "🔊 * Silence... *" << std::endl;
}

// Accesseur pour obtenir le type de l'animal
std::string Animal::getType() const 
{
    return type;
}