/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 01:46:45 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/03/03 13:14:06 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

// Ajout du mot-clé 'virtual' pour l'héritage en diamant
class FragTrap : virtual public ClapTrap
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
    
    // Renvoie la valeur par défaut des points de vie pour cette classe
    static unsigned int getDefaultHitPoints() { return 100; }

    // Renvoie la valeur par défaut des points de dégâts d'attaque pour cette classe
    static unsigned int getDefaultAttackDamage() { return 30; }

    // Demande un high five à tout le monde de manière enthousiaste
    // Ne fonctionne pas si le FragTrap est mort
    void highFivesGuys(void);
};

#endif