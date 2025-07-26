/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:28:40 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/25 19:17:08 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>

class AMateria;

class ICharacter 
{
public:
    // Destructeur virtuel - nécessaire pour une interface
    virtual ~ICharacter() {}
    
    // Getter pour le nom du personnage
    virtual std::string const & getName() const = 0;
    
    // Équipe le personnage avec une materia dans un slot libre
    virtual void equip(AMateria* m) = 0;
    
    // Retire une materia d'un slot spécifique sans la détruire
    virtual void unequip(int idx) = 0;
    
    // Utilise la materia d'un slot spécifique sur une cible
    virtual void use(int idx, ICharacter& target) = 0;
};

#endif