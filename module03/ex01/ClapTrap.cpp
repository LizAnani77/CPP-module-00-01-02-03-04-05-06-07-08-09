/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 00:19:09 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/23 22:29:49 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructeur par défaut - initialise avec des valeurs standard 
ClapTrap::ClapTrap() : 
    _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

// Constructeur avec nom - permet de créer un ClapTrap personnalisé
ClapTrap::ClapTrap(const std::string& name) :
    _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
    std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
}

// Constructeur de copie - crée une copie identique d'un autre ClapTrap  
ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "ClapTrap Copy constructor called" << std::endl; 
    *this = other;
}

// Destructeur virtuel - libère les ressources et affiche un message
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}

// Opérateur d'affectation - permet d'assigner les valeurs d'un ClapTrap à un autre
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints; 
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

// Attaque une cible spécifiée, consomme 1 point d'énergie
// Ne fonctionne pas si ClapTrap n'a plus d'énergie ou est mort
void ClapTrap::attack(const std::string& target)
{
    if (_energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " has no energy points left to attack!" << std::endl;
        return;
    }
    if (_hitPoints == 0) 
    {
        std::cout << "ClapTrap " << _name << " is dead and cannot attack!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " attacks " << target 
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints--;
}

// Réduit les points de vie en fonction des dégâts reçus 
// Si les points de vie tombent à 0, le ClapTrap est considéré comme mort
void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
        return;
    }
    if (_hitPoints <= amount)
    {
        _hitPoints = 0;
        std::cout << "ClapTrap " << _name << " takes " << amount 
                  << " damage and dies!" << std::endl;
    }
    else
    {
        _hitPoints -= amount;
        std::cout << "ClapTrap " << _name << " takes " << amount 
                  << " damage, " << _hitPoints << " HP remaining!" << std::endl;
    }
}

// Guérit le ClapTrap en restaurant des points de vie, consomme 1 point d'énergie
// Ne fonctionne pas si ClapTrap n'a plus d'énergie ou est mort
void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " has no energy points left to heal!" << std::endl;
        return;
    }
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name << " is dead and cannot be healed!" << std::endl;
        return;
    }
    _hitPoints += amount;
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " heals itself for " << amount 
              << " points, now has " << _hitPoints << " HP!" << std::endl;
}

// Getters - permettent d'accéder aux attributs protégés sans les modifier
std::string ClapTrap::getName() const { return _name; }            // Renvoie le nom du ClapTrap
unsigned int ClapTrap::getHitPoints() const { return _hitPoints; } // Renvoie les points de vie actuels
unsigned int ClapTrap::getEnergyPoints() const { return _energyPoints; } // Renvoie les points d'énergie actuels
unsigned int ClapTrap::getAttackDamage() const { return _attackDamage; } // Renvoie la valeur des dégâts d'attaque