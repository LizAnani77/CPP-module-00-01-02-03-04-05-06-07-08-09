/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 01:34:10 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/17 11:12:48 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string initialType) : type(initialType) {}
// Constructeur par défaut
// Initialise le type de l'arme via la liste d'initialisation

const std::string& Weapon::getType() const
// Fonction : getType
// Retourne le type d'arme actuel
{
    return type;
    // Retourne une référence constante vers le type de l'arme
    // Évite la copie des données en mémoire
}

void Weapon::setType(std::string newType)
{
    type = newType;
    // Modifie le type de l'arme
}