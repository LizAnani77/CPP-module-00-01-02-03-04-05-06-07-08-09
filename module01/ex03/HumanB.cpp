/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 01:38:17 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/17 11:08:43 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}
// Constructeur
// Initialise un humain désarmé
// Paramètres :
//   - name : Le nom de l'humain (copié)
// Note : weapon est initialisé à NULL car l'humain commence sans arme

void HumanB::setWeapon(Weapon& weapon)
// Fonction : setWeapon
// Équipe l'humain avec une nouvelle arme
{
    this->weapon = &weapon;
    // Stocke l'adresse de l'arme fournie
}

void HumanB::attack() const
// Fonction : attack
// Fait attaquer l'humain s'il possède une arme
{
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " has no weapon to attack with" << std::endl;
}