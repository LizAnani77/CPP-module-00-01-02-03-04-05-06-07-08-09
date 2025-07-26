/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 01:15:05 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/23 22:26:33 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
    bool _guardMode;    // État du mode gardien, activé ou désactivé

public:
    // Constructeur par défaut - initialise avec des valeurs standard
    ScavTrap();
    
    // Constructeur avec nom - permet de créer un ScavTrap personnalisé
    ScavTrap(const std::string& name);
    
    // Constructeur de copie - crée une copie identique d'un autre ScavTrap
    ScavTrap(const ScavTrap& other);
    
    // Destructeur - libère les ressources et affiche un message
    virtual ~ScavTrap();

    // Opérateur d'affectation - permet d'assigner les valeurs d'un ScavTrap à un autre
    ScavTrap& operator=(const ScavTrap& other);

    // Attaque une cible spécifiée, consomme 1 point d'énergie
    // Ne fonctionne pas si ScavTrap n'a plus d'énergie ou est mort
    void attack(const std::string& target);
    
    // Active ou désactive le mode gardien de porte
    // Ne fonctionne pas si ScavTrap est mort
    void guardGate();
};

#endif