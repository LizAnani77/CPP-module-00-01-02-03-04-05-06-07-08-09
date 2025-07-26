/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 00:18:03 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/23 22:30:48 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

class ClapTrap
{
protected:
    std::string     _name;        // Identifiant unique du ClapTrap
    unsigned int    _hitPoints;    // Points de vie, représente la santé restante
    unsigned int    _energyPoints; // Points d'énergie, nécessaires pour attaquer et se guérir
    unsigned int    _attackDamage; // Dégâts infligés lors d'une attaque

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

    // Attaque une cible spécifiée, consomme 1 point d'énergie
    // Ne fonctionne pas si ClapTrap n'a plus d'énergie ou est mort
    virtual void attack(const std::string& target);
    
    // Réduit les points de vie en fonction des dégâts reçus
    // Si les points de vie tombent à 0, le ClapTrap est considéré comme mort
    void takeDamage(unsigned int amount);
    
    // Guérit le ClapTrap en restaurant des points de vie, consomme 1 point d'énergie
    // Ne fonctionne pas si ClapTrap n'a plus d'énergie ou est mort
    void beRepaired(unsigned int amount);

    // Getters - permettent d'accéder aux attributs protégés sans les modifier
    std::string getName() const;       // Renvoie le nom du ClapTrap
    unsigned int getHitPoints() const;  // Renvoie les points de vie actuels
    unsigned int getEnergyPoints() const; // Renvoie les points d'énergie actuels
    unsigned int getAttackDamage() const; // Renvoie la valeur des dégâts d'attaque
};

#endif