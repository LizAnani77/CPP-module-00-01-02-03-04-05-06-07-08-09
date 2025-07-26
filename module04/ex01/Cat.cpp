/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:19:59 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/25 19:02:55 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructeur par défaut - crée un cerveau
Cat::Cat() : Animal() 
{
    type = "Cat";
    brain = new Brain();
    std::cout << "🐱 Cat constructor called" << std::endl;
}

// Constructeur de copie - effectue une copie profonde
Cat::Cat(const Cat& other) : Animal(other) 
{
    std::cout << "🐱 Cat copy constructor called" << std::endl;
    brain = new Brain(*other.brain);
}

// Destructeur - libère le cerveau
Cat::~Cat() 
{
    delete brain;
    std::cout << "🐱 Cat destructor called" << std::endl;
}

// Opérateur d'affectation - copie profonde
Cat& Cat::operator=(const Cat& other) 
{
    std::cout << "🐱 Cat assignment operator called" << std::endl;
    if (this != &other) 
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

// Remplace la méthode de la classe de base
void Cat::makeSound() const 
{
    std::cout << "🐱 Meow! Meow!" << std::endl;
}

// Définit une idée dans le cerveau
void Cat::setIdea(int index, const std::string& idea) 
{
    brain->setIdea(index, idea);
}

// Récupère une idée du cerveau
std::string Cat::getIdea(int index) const 
{
    return brain->getIdea(index);
}