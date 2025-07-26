/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:18:15 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/25 19:03:24 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructeur par défaut - crée un cerveau
Dog::Dog() : Animal() 
{
    type = "Dog";
    brain = new Brain();
    std::cout << "🐕 Dog constructor called" << std::endl;
}

// Constructeur de copie - effectue une copie profonde
Dog::Dog(const Dog& other) : Animal(other) 
{
    std::cout << "🐕 Dog copy constructor called" << std::endl;
    brain = new Brain(*other.brain);
}

// Destructeur - libère le cerveau
Dog::~Dog() 
{
    delete brain;
    std::cout << "🐕 Dog destructor called" << std::endl;
}

// Opérateur d'affectation - copie profonde
Dog& Dog::operator=(const Dog& other) 
{
    std::cout << "🐕 Dog assignment operator called" << std::endl;
    if (this != &other) 
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

// Remplace la méthode de la classe de base
void Dog::makeSound() const 
{
    std::cout << "🐕 Woof! Woof!" << std::endl;
}

// Définit une idée dans le cerveau
void Dog::setIdea(int index, const std::string& idea) 
{
    brain->setIdea(index, idea);
}

// Récupère une idée du cerveau
std::string Dog::getIdea(int index) const 
{
    return brain->getIdea(index);
}