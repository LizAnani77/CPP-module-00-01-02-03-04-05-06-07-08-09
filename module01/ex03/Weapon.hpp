/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 01:33:36 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/17 11:20:56 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
// Classe : Weapon
// Rôle : Représente une arme avec un type modifiable
{
private:
    std::string type;
    // Attribut stockant le type de l'arme

public:
    Weapon(std::string initialType);
    // Constructeur : Initialise une arme avec un type spécifique
    // Paramètres : initialType : Le type initial de l'arme
    const std::string& getType() const;
    // Fonction : getType
    // Récupère le type de l'arme
    // Retourne une référence constante vers le type de l'arme
    void setType(std::string newType);
    // Fonction : setType
    // Modifie le type de l'arme
    // Paramètres : newType : Le nouveau type à assigner à l'arme
};

#endif

 // Note : Le const après la fonction garantit qu'elle ne modifie pas l'objet