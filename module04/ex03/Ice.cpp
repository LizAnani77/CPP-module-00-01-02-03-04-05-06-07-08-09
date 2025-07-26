/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:33:34 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/25 19:20:18 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

// Constructeur par défaut - initialise une materia de glace
Ice::Ice() : AMateria("ice") 
{
    std::cout << "❄️ Ice constructor called" << std::endl;
}

// Destructeur - libère les ressources spécifiques
Ice::~Ice() 
{
    std::cout << "❄️ Ice destructor called" << std::endl;
}

// Constructeur de copie - duplique une materia de glace
Ice::Ice(const Ice& other) : AMateria(other) 
{
    std::cout << "❄️ Ice copy constructor called" << std::endl;
}

// Opérateur d'affectation - copie les attributs d'une materia de glace
Ice& Ice::operator=(const Ice& other) 
{
    std::cout << "❄️ Ice assignment operator called" << std::endl;
    AMateria::operator=(other);
    return *this;
}

// Crée une nouvelle instance de materia de glace
AMateria* Ice::clone() const 
{
    return new Ice(*this);
}

// Action spécifique lors de l'utilisation d'une materia de glace
void Ice::use(ICharacter& target) 
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}