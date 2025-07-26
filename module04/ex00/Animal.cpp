/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:11:53 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/25 18:41:54 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Unknown") 
{
    // Initialise un animal avec un type par défaut "Unknown"
    std::cout << "🐾 Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) 
{
    // Crée une copie exacte d'un animal existant
    std::cout << "🐾 Animal copy constructor called" << std::endl;
}

Animal::~Animal() 
{
    // Destructeur virtuel pour garantir l'appel correct des destructeurs des classes dérivées
    std::cout << "🐾 Animal destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) 
{
    // Assigne les attributs d'un animal à un autre si ce n'est pas le même objet
    std::cout << "🐾 Animal assignment operator called" << std::endl;
    if (this != &other)
        type = other.type;
    return *this;
}

void Animal::makeSound() const 
{
    // Son générique (silence) pour la classe de base Animal
    std::cout << "🔊 * Silence... *" << std::endl;
}

std::string Animal::getType() const 
{
    // Renvoie le type de l'animal
    return type;
}