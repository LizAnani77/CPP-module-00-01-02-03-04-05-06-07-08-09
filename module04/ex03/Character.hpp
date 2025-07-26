/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:42:25 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/25 19:18:48 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter 
{
private:
    std::string name;       // Nom du personnage
    AMateria* inventory[4]; // Inventaire de materias (4 emplacements max)
    int count;              // Nombre de materias équipées

public:
    // Constructeur avec nom - initialise un personnage avec un nom spécifique
    Character(std::string const & name);
    
    // Destructeur virtuel - libère les materias équipées
    virtual ~Character();
    
    // Constructeur de copie - effectue une copie profonde de l'inventaire
    Character(const Character& other);
    
    // Opérateur d'affectation - copie profonde des attributs
    Character& operator=(const Character& other);

    // Implémente le getter pour obtenir le nom du personnage
    virtual std::string const & getName() const;
    
    // Implémente l'équipement d'une materia dans l'inventaire
    virtual void equip(AMateria* m);
    
    // Implémente le retrait d'une materia de l'inventaire
    virtual void unequip(int idx);
    
    // Implémente l'utilisation d'une materia sur une cible
    virtual void use(int idx, ICharacter& target);
};

#endif