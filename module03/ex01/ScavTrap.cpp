/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 01:16:44 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/23 22:27:09 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructeur par défaut - initialise avec des valeurs standard 
ScavTrap::ScavTrap() : ClapTrap(), _guardMode(false)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

// Constructeur avec nom - permet de créer un ScavTrap personnalisé
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name), _guardMode(false)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " constructor called" << std::endl;
}

// Constructeur de copie - crée une copie identique d'un autre ScavTrap
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;
    *this = other;
}

// Destructeur - libère les ressources et affiche un message
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " destructor called" << std::endl;
}

// Opérateur d'affectation - permet d'assigner les valeurs d'un ScavTrap à un autre
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        _guardMode = other._guardMode;
    }
    return *this;
}

// Attaque une cible spécifiée, consomme 1 point d'énergie
// Ne fonctionne pas si ScavTrap n'a plus d'énergie ou est mort
void ScavTrap::attack(const std::string& target)
{
    if (_energyPoints == 0)
    {
        std::cout << "ScavTrap " << _name << " has no energy points left to attack!" << std::endl;
        return;
    }
    if (_hitPoints == 0)
    {
        std::cout << "ScavTrap " << _name << " is dead and cannot attack!" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << _name << " aggressively attacks " << target 
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints--;
}

// Active ou désactive le mode gardien de porte
// Ne fonctionne pas si ScavTrap est mort
void ScavTrap::guardGate()
{
    if (_hitPoints == 0)
    {
        std::cout << "ScavTrap " << _name << " is dead and cannot enter Gate keeper mode!" << std::endl;
        return;
    }
    _guardMode = !_guardMode;
    if (_guardMode)
        std::cout << "ScavTrap " << _name << " has entered Gate keeper mode!" << std::endl;
    else
        std::cout << "ScavTrap " << _name << " has exited Gate keeper mode!" << std::endl;
}