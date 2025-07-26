/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:54:24 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/17 10:20:10 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie::Zombie() : name("") {}
// Constructeur par défaut
// Initialise un zombie avec un nom vide

Zombie::Zombie(std::string _name) : name(_name) {}
// Constructeur avec paramètre
// Initialise un zombie avec le nom fourni
// Paramètres : _name : Le nom à attribuer au zombie

Zombie::~Zombie()
// Destructeur
// Affiche un message indiquant la destruction du zombie
{
    std::cout << this->name << " is destroyed" << std::endl;
}

void Zombie::setName(std::string _name)
// Fonction : setName
// Modifie le nom du zombie
// Paramètres : _name : Le nouveau nom à attribuer au zombie
{
    this->name = _name;
}

void Zombie::announce()
// Fonction : announce
// Fait prononcer au zombie sa phrase caractéristique
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}