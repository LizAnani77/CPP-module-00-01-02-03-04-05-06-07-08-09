/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 01:47:49 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/27 12:08:08 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FragTrap.hpp"

// Constructeur par défaut - initialise avec des valeurs standard
FragTrap::FragTrap() : ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap Default constructor called" << std::endl;
}

// Constructeur avec nom - permet de créer un FragTrap personnalisé
FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " constructor called" << std::endl;
}

// Constructeur de copie - crée une copie identique d'un autre FragTrap
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap Copy constructor called" << std::endl;
    *this = other;
}

// Destructeur virtuel - libère les ressources et affiche un message
FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << _name << " destructor called" << std::endl;
}

// Opérateur d'affectation - permet d'assigner les valeurs d'un FragTrap à un autre
FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return *this;
}

// Demande un high five à tout le monde de manière enthousiaste
// Ne fonctionne pas si le FragTrap est mort
void FragTrap::highFivesGuys(void)
{
    if (_hitPoints == 0)
    {
        std::cout << "FragTrap " << _name << " is too dead to request high fives!" << std::endl;
        return;
    }
    std::cout << "FragTrap " << _name << " enthusiastically requests high fives from everyone!" << std::endl;
}