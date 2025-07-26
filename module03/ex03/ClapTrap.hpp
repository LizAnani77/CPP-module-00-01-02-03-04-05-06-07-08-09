/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 00:18:03 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/25 13:07:37 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

// Classe de base pour les robots ClapTrap
class ClapTrap
{
protected:
    std::string     _name;           // Nom du ClapTrap
    unsigned int    _hitPoints;      // Points de vie, représente la santé du ClapTrap
    unsigned int    _energyPoints;   // Points d'énergie pour les actions
    unsigned int    _attackDamage;   // Dégâts infligés lors d'une attaque

public:
    // Constructeur par défaut - initialise avec des valeurs standard
    ClapTrap();
    
    // Constructeur avec nom - permet de créer un ClapTrap personnalisé
    ClapTrap(const std::string& name);
    
    // Constructeur de copie - crée une copie identique d'un autre ClapTrap
    ClapTrap(const ClapTrap& other);
    
    // Destructeur virtuel - libère les ressources et affiche un message
    virtual ~ClapTrap();

    // Opérateur d'affectation - permet d'assigner les valeurs d'un ClapTrap à un autre
    ClapTrap& operator=(const ClapTrap& other);

    // Méthodes principales d'action du ClapTrap
    virtual void attack(const std::string& target);      // Attaque une cible
    void takeDamage(unsigned int amount);                // Reçoit des dégâts
    void beRepaired(unsigned int amount);                // Se répare

    // Getters - permettent d'accéder aux attributs protégés
    std::string getName() const;             // Obtient le nom
    unsigned int getHitPoints() const;       // Obtient les points de vie
    unsigned int getEnergyPoints() const;    // Obtient les points d'énergie
    unsigned int getAttackDamage() const;    // Obtient les dégâts d'attaque
};

#endif