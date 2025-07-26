/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:35:29 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/25 18:43:19 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongUnknown") 
{
    // Initialise un animal incorrect avec un type par défaut "WrongUnknown"
    std::cout << "❌ WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) 
{
    // Crée une copie exacte d'un animal incorrect existant
    std::cout << "❌ WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() 
{
    // Destructeur NON virtuel - problématique pour les classes dérivées
    std::cout << "❌ WrongAnimal destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) 
{
    // Assigne les attributs d'un animal incorrect à un autre
    std::cout << "❌ WrongAnimal assignment operator called" << std::endl;
    if (this != &other)
        type = other.type;
    return *this;
}

void WrongAnimal::makeSound() const 
{
    // Son générique pour la classe WrongAnimal
    // Cette méthode n'étant pas virtuelle, elle sera appelée même pour les objets dérivés
    std::cout << "❌ * Wrong silence... *" << std::endl;
}

std::string WrongAnimal::getType() const 
{
    // Renvoie le type de l'animal incorrect
    return type;
}