/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 03:13:04 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/03/03 13:17:19 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Constructeur par défaut - initialise avec des valeurs standard
DiamondTrap::DiamondTrap() : 
    ClapTrap("Default_clap_name"),
    ScavTrap(),
    FragTrap(),
    _name("Default")
{
    _hitPoints = FragTrap::getDefaultHitPoints();
    _energyPoints = ScavTrap::getDefaultEnergyPoints();
    _attackDamage = FragTrap::getDefaultAttackDamage();
    std::cout << "DiamondTrap Default constructor called" << std::endl;
}

// Constructeur avec nom - permet de créer un DiamondTrap personnalisé
DiamondTrap::DiamondTrap(const std::string& name) : 
    ClapTrap(name + "_clap_name"),
    ScavTrap(),
    FragTrap(),
    _name(name)
{
    _hitPoints = FragTrap::getDefaultHitPoints();
    _energyPoints = ScavTrap::getDefaultEnergyPoints();
    _attackDamage = FragTrap::getDefaultAttackDamage();
    std::cout << "DiamondTrap " << _name << " constructor called" << std::endl;
}
// Constructeur de copie - crée une copie identique d'un autre DiamondTrap
DiamondTrap::DiamondTrap(const DiamondTrap& other) :
    ClapTrap(other),
    ScavTrap(other),
    FragTrap(other),
    _name(other._name)
{
    std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

// Destructeur - libère les ressources et affiche un message
DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << _name << " destructor called" << std::endl;
}

// Opérateur d'affectation - copie les attributs d'un autre DiamondTrap
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        _name = other._name;
    }
    return *this;
}

// Affiche l'identité du DiamondTrap et de son ClapTrap parent
void DiamondTrap::whoAmI(void)
{
    std::cout << "DiamondTrap name is " << _name 
              << " and ClapTrap name is " << ClapTrap::_name << std::endl;
}