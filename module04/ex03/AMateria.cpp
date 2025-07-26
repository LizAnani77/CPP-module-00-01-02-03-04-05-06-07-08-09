/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:31:36 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/25 19:19:47 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

// Constructeur avec type - initialise le type de materia
AMateria::AMateria(std::string const & type) : type(type) 
{
    std::cout << "🔮 AMateria constructor called for type: " << type << std::endl;
}

// Destructeur - libère les ressources et affiche un message
AMateria::~AMateria() 
{
    std::cout << "🔮 AMateria destructor called for type: " << type << std::endl;
}

// Constructeur de copie - duplique une materia existante
AMateria::AMateria(const AMateria& other) : type(other.type) 
{
    std::cout << "🔮 AMateria copy constructor called" << std::endl;
}

// Opérateur d'affectation - copie le type d'une materia à une autre
AMateria& AMateria::operator=(const AMateria& other) 
{
    std::cout << "🔮 AMateria assignment operator called" << std::endl;
    if (this != &other)
        type = other.type;
    return *this;
}

// Getter pour le type de la materia
std::string const & AMateria::getType() const 
{
    return type;
}

// Action par défaut lors de l'utilisation d'une materia
void AMateria::use(ICharacter& target) 
{
    std::cout << "* Uses materia on " << target.getName() << " *" << std::endl;
}