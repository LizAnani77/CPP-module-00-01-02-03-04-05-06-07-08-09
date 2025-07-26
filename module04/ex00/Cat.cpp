/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:19:59 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/25 18:42:04 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() 
{
    // Initialise un animal de type "Cat"
    type = "Cat";
    std::cout << "🐱 Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) 
{
    // Crée une copie exacte d'un Cat existant
    std::cout << "🐱 Cat copy constructor called" << std::endl;
}

Cat::~Cat() 
{
    // Libère les ressources spécifiques au Cat
    std::cout << "🐱 Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) 
{
    // Assigne les attributs d'un Cat à un autre
    std::cout << "🐱 Cat assignment operator called" << std::endl;
    Animal::operator=(other);
    return *this;
}

void Cat::makeSound() const 
{
    // Produit un son spécifique au chat (miaulement)
    // Remplace la méthode makeSound de la classe Animal
    std::cout << "🐱 Meow! Meow!" << std::endl;
}