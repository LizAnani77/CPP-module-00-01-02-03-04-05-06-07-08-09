/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:21:36 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/17 10:06:42 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string _name) : name(_name){}
// Constructeur
// Initialise un nouveau zombie avec le nom fourni
// Paramètres : _name : Le nom à attribuer au zombie

Zombie::~Zombie(void)
// Destructeur
// Affiche un message indiquant la destruction du zombie
{
    std::cout << this->name << " is destroyed" << std::endl;
}

void Zombie::announce(void)
// Fonction : announce
// Fait prononcer au zombie sa phrase caractéristique
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}