/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:35:20 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/25 19:20:52 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

// Constructeur par défaut - initialise une materia de soin
Cure::Cure() : AMateria("cure") 
{
    std::cout << "💊 Cure constructor called" << std::endl;
}

// Destructeur - libère les ressources spécifiques
Cure::~Cure() 
{
    std::cout << "💊 Cure destructor called" << std::endl;
}

// Constructeur de copie - duplique une materia de soin
Cure::Cure(const Cure& other) : AMateria(other) 
{
    std::cout << "💊 Cure copy constructor called" << std::endl;
}

// Opérateur d'affectation - copie les attributs d'une materia de soin
Cure& Cure::operator=(const Cure& other) 
{
    std::cout << "💊 Cure assignment operator called" << std::endl;
    AMateria::operator=(other);
    return *this;
}

// Crée une nouvelle instance de materia de soin
AMateria* Cure::clone() const 
{
    return new Cure(*this);
}

// Action spécifique lors de l'utilisation d'une materia de soin
void Cure::use(ICharacter& target) 
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}