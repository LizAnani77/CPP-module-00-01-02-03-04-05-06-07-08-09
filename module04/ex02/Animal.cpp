/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 21:42:03 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/03/04 14:20:42 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Constructeur par défaut - initialise avec "AAnimal"
Animal::Animal() : type("AAnimal") 
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

// Getter pour obtenir le type de l'animal
std::string Animal::getType() const 
{
    return type;
}