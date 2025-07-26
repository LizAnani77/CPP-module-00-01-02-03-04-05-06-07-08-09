/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:43:53 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/03/06 13:35:49 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

// Constructeur avec nom - initialise un personnage avec un nom spécifique
Character::Character(std::string const & name) : name(name), count(0) 
{
    // Affiche un message pour indiquer la création du personnage
    std::cout << "👤 Character constructor called for " << name << std::endl;
    // Initialise tous les slots d'inventaire à NULL (vides)
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

// Destructeur - libère les materias équipées pour éviter les fuites de mémoire
Character::~Character() 
{
    // Affiche un message pour indiquer la destruction du personnage
    std::cout << "👤 Character destructor called for " << name << std::endl;
    // Parcourt l'inventaire et détruit chaque materia pour éviter les fuites
    for (int i = 0; i < count; i++)
        delete inventory[i];
}

// Constructeur de copie - effectue une copie profonde de l'inventaire
Character::Character(const Character& other) : name(other.name), count(other.count) 
{
    // Affiche un message pour indiquer la copie du personnage
    std::cout << "👤 Character copy constructor called" << std::endl;
    // Clone chaque materia pour créer de nouvelles instances indépendantes
    for (int i = 0; i < count; i++)
        inventory[i] = other.inventory[i]->clone();
    // Initialise les slots restants à NULL
    for (int i = count; i < 4; i++)
        inventory[i] = NULL;
}

// Opérateur d'affectation - copie profonde des attributs entre deux personnages existants
Character& Character::operator=(const Character& other) 
{
    // Affiche un message pour indiquer l'affectation
    std::cout << "👤 Character assignment operator called" << std::endl;
    // Vérifie qu'on ne s'assigne pas à soi-même (auto-affectation)
    if (this != &other) 
    {
        // Libère d'abord les materias existantes pour éviter les fuites
        for (int i = 0; i < count; i++)
            delete inventory[i];
        // Copie les attributs de base
        name = other.name;
        count = other.count;
        // Clone chaque materia pour créer de nouvelles instances indépendantes
        for (int i = 0; i < count; i++)
            inventory[i] = other.inventory[i]->clone();
        // Initialise les slots restants à NULL
        for (int i = count; i < 4; i++)
            inventory[i] = NULL;
    }
    // Retourne une référence à l'objet actuel pour permettre les affectations en chaîne
    return *this;
}

// Getter pour le nom du personnage - implémentation de la méthode virtuelle pure de ICharacter
std::string const & Character::getName() const 
{
    // Retourne simplement le nom stocké dans l'attribut privé
    return name;
}

void Character::equip(AMateria* m) 
{
    // Vérifie qu'il reste des slots disponibles et que la materia est valide
    if (count < 4 && m)
    {
        // Stocke la materia dans le premier slot libre et incrémente le compteur
        inventory[count] = m;
        std::cout << "Character " << name << " equipped a " << m->getType() 
                  << " materia in slot " << count << std::endl;
        count++;
    } 
    else if (count >= 4) 
    {
        std::cout << "Character " << name << " cannot equip more materias: inventory is full" << std::endl;
    } 
    else 
    {
        std::cout << "Character " << name << " cannot equip a null materia" << std::endl;
    }
}

void Character::unequip(int idx) 
{
    // Vérifie que l'index est valide
    if (idx >= 0 && idx < count) 
    {
        std::cout << "Character " << name << " unequipped a " << inventory[idx]->getType() 
                  << " materia from slot " << idx << std::endl;
        
        // Marque le slot comme vide
        inventory[idx] = NULL;
        // Décale toutes les materias suivantes d'une position vers le haut pour combler le trou
        for (int i = idx; i < count - 1; i++)
            inventory[i] = inventory[i + 1];
        // Assure que le dernier slot est vide après le décalage
        inventory[count - 1] = NULL;
        // Décrémente le compteur de materias
        count--;
    } 
    else 
    {
        std::cout << "Character " << name << " tried to unequip from invalid slot " << idx << std::endl;
    }
}

void Character::use(int idx, ICharacter& target) 
{
    // Vérifie que l'index est valide et que le slot contient une materia
    if (idx >= 0 && idx < count && inventory[idx]) 
    {
        std::cout << "Character " << name << " uses " << inventory[idx]->getType() 
                  << " materia from slot " << idx << " on " << target.getName() << std::endl;
        // Délègue l'action à la méthode use de la materia
        inventory[idx]->use(target);
    } 
    else if (idx < 0 || idx >= 4) {
        std::cout << "Character " << name << " tried to use an invalid slot " << idx << std::endl;
    } 
    else 
    {
        std::cout << "Character " << name << " has no materia equipped in slot " << idx << std::endl;
    }
}