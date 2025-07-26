/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 01:46:45 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/23 22:33:10 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
    // Constructeur par défaut - initialise avec des valeurs standard
    FragTrap();
    
    // Constructeur avec nom - permet de créer un FragTrap personnalisé
    FragTrap(const std::string& name);
    
    // Constructeur de copie - crée une copie identique d'un autre FragTrap
    FragTrap(const FragTrap& other);
    
    // Destructeur virtuel - libère les ressources et affiche un message
    virtual ~FragTrap();

    // Opérateur d'affectation - permet d'assigner les valeurs d'un FragTrap à un autre
    FragTrap& operator=(const FragTrap& other);

    // Demande un high five à tout le monde de manière enthousiaste
    // Ne fonctionne pas si le FragTrap est mort
    void highFivesGuys(void);
};

#endif