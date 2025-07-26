/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:24:08 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/17 10:09:18 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name)
// Fonction : newZombie
// Crée dynamiquement un nouveau zombie et retourne son pointeur
// Paramètres : name : Le nom à donner au zombie
{
    return new Zombie(name);
}