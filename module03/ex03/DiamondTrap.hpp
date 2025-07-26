/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 03:11:49 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/03/03 13:40:38 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

// Classe héritant de ScavTrap et FragTrap (héritage en diamant)
class DiamondTrap : public ScavTrap, public FragTrap
{
public:
    // Constructeur par défaut - initialise avec des valeurs standard
    DiamondTrap();
    
    // Constructeur avec nom - permet de créer un DiamondTrap personnalisé
    DiamondTrap(const std::string& name);
    
    // Constructeur de copie - crée une copie identique d'un autre DiamondTrap
    DiamondTrap(const DiamondTrap& other);
    
    // Destructeur virtuel - libère les ressources et affiche un message
    virtual ~DiamondTrap();

    // Opérateur d'affectation - permet d'assigner les valeurs d'un DiamondTrap à un autre
    DiamondTrap& operator=(const DiamondTrap& other);

    // Affiche l'identité du DiamondTrap et de son ClapTrap parent
    void whoAmI(void);

private:
    std::string _name;    // Nom spécifique au DiamondTrap, distinct du nom ClapTrap
};

#endif