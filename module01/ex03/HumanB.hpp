/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 01:36:58 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/17 11:01:26 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB
// Classe : HumanB
// Représente un humain qui peut être armé ou non
{
private:
    std::string name;
    // Nom de l'humain
    Weapon* weapon;
    // Pointeur vers l'arme (peut être NULL et l'humain désarmé)

public:
    HumanB(std::string name);
    // Constructeur : Crée un humain avec un nom, sans arme
    // Paramètres : name : Le nom de l'humain
    void setWeapon(Weapon& weapon);
    // Fonction : setWeapon
    // Équipe l'humain avec une arme
    // Paramètres : weapon : Référence vers l'arme à équiper
    void attack() const;
    // Fonction : attack
    // Fait attaquer l'humain (s'il a une arme)
};

#endif