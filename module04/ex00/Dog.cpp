/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:18:15 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/25 18:42:26 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() 
{
    // Initialise un animal de type "Dog"
    type = "Dog";
    std::cout << "🐕 Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) 
{
    // Crée une copie exacte d'un Dog existant
    std::cout << "🐕 Dog copy constructor called" << std::endl;
}

Dog::~Dog() 
{
    // Libère les ressources spécifiques au Dog
    std::cout << "🐕 Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) 
{
    // Assigne les attributs d'un Dog à un autre
    std::cout << "🐕 Dog assignment operator called" << std::endl;
    Animal::operator=(other);
    return *this;
}

void Dog::makeSound() const 
{
    // Produit un son spécifique au chien (aboiement)
    // Remplace la méthode makeSound de la classe Animal
    std::cout << "🐕 Woof! Woof!" << std::endl;
}