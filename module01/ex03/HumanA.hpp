/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 01:35:17 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/17 10:59:56 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA
// Classe : HumanA
// Représente un humain qui est toujours armé (utilise une référence vers une arme) 
{
private:
    std::string name;
    // Nom de l'humain
    Weapon& weapon;
    // Référence vers l'arme (toujours valide, une référence ne peut pas être "nulle" contrairement à un pointeur)

public:
    HumanA(std::string name, Weapon& weapon);
    // Constructeur : Crée un humain avec nom et arme obligatoire
    // Paramètres :
    //   name : Le nom de l'humain
    //   weapon : Référence vers son arme (obligatoire)
    void attack() const;
    // Fonction : attack
    // Rôle : Fait attaquer l'humain avec son arme
    // Note : const car ne modifie pas l'état de l'objet
};

#endif