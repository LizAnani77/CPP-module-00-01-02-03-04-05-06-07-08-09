/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 01:36:04 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/17 10:59:18 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {}
// Constructeur
// Initialise un humain avec son nom et son arme
// Paramètres :
//   - name : Le nom de l'humain
//   - weapon : Référence vers l'arme de l'humain

void HumanA::attack() const
// Fonction : attack
// Affiche une attaque avec l'arme actuelle
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}