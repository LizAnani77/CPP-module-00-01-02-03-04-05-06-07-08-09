/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 01:15:05 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/03/03 13:20:08 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

// Ajout du mot-clé 'virtual' pour l'héritage en diamant
class ScavTrap : virtual public ClapTrap
{
public:
    // Constructeur par défaut - initialise avec des valeurs standard
    ScavTrap();
    
    // Constructeur avec nom - permet de créer un ScavTrap personnalisé
    ScavTrap(const std::string& name);
    
    // Constructeur de copie - crée une copie identique d'un autre ScavTrap
    ScavTrap(const ScavTrap& other);
    
    // Destructeur virtuel - libère les ressources et affiche un message
    virtual ~ScavTrap();

    // Opérateur d'affectation - permet d'assigner les valeurs d'un ScavTrap à un autre
    ScavTrap& operator=(const ScavTrap& other);

    // Fonction d'attaque redéfinie avec un message personnalisé pour ScavTrap
    void attack(const std::string& target);
    
   // Renvoie la valeur par défaut des points d'énergie pour cette classe
    static unsigned int getDefaultEnergyPoints() { return 50; }
    
    // Active ou désactive le mode garde, fonction spécifique au ScavTrap
    void guardGate();

private:
    bool _guardMode;    // État du mode garde (activé/désactivé)
};

#endif