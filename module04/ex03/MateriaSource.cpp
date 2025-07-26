/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:38:59 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/03/06 13:47:19 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

// Constructeur par défaut - initialise une source de materias vide
MateriaSource::MateriaSource() : count(0) 
{
    // Affiche un message pour indiquer la création de la source de materias
    std::cout << "📚 MateriaSource constructor called" << std::endl;
    // Initialise tous les emplacements de templates à NULL (vides)
    for (int i = 0; i < 4; i++)
        templates[i] = NULL;
}

// Destructeur - libère les modèles de materias pour éviter les fuites de mémoire
MateriaSource::~MateriaSource() 
{
    // Affiche un message pour indiquer la destruction de la source
    std::cout << "📚 MateriaSource destructor called" << std::endl;
    // Parcourt le tableau et détruit chaque template de materia
    for (int i = 0; i < count; i++)
        delete templates[i];
}

// Constructeur de copie - effectue une copie profonde des modèles de materias
MateriaSource::MateriaSource(const MateriaSource& other) : count(other.count) 
{
    // Affiche un message pour indiquer la copie de la source
    std::cout << "📚 MateriaSource copy constructor called" << std::endl;
    // Clone chaque template pour créer des copies indépendantes
    for (int i = 0; i < count; i++)
        templates[i] = other.templates[i]->clone();
    // Initialise les emplacements restants à NULL
    for (int i = count; i < 4; i++)
        templates[i] = NULL;
}

// Opérateur d'affectation - copie profonde entre deux sources existantes
MateriaSource& MateriaSource::operator=(const MateriaSource& other) 
{
    // Affiche un message pour indiquer l'affectation
    std::cout << "📚 MateriaSource assignment operator called" << std::endl;
    // Vérifie qu'on ne s'assigne pas à soi-même (auto-affectation)
    if (this != &other) 
    {
        // Libère d'abord les templates existants pour éviter les fuites
        for (int i = 0; i < count; i++)
            delete templates[i];
        // Copie le nombre de templates
        count = other.count;
        // Clone chaque template pour créer des copies indépendantes
        for (int i = 0; i < count; i++)
            templates[i] = other.templates[i]->clone();
        // Initialise les emplacements restants à NULL
        for (int i = count; i < 4; i++)
            templates[i] = NULL;
    }
    // Retourne une référence à l'objet actuel pour permettre les affectations en chaîne
    return *this;
}

// Mémorise une nouvelle materia pour pouvoir la reproduire plus tard
void MateriaSource::learnMateria(AMateria* m) 
{
    // Vérifie qu'il reste des emplacements disponibles et que la materia est valide
    if (count < 4 && m) 
    {
        // Stocke une copie du modèle (pas l'original) et incrémente le compteur
        templates[count++] = m->clone();
        // Détruit l'original pour éviter les fuites de mémoire
        delete m;
    }
    // Si pas d'emplacement disponible mais materia valide, libère la mémoire
    else if (m)
        delete m;
}

// Crée une nouvelle materia du type spécifié si elle est connue
AMateria* MateriaSource::createMateria(std::string const & type) 
{
    // Parcourt les templates connus
    for (int i = 0; i < count; i++) 
    {
        // Si un template du type demandé est trouvé
        if (templates[i]->getType() == type)
            // Crée et retourne une nouvelle instance de ce type (pas l'original)
            return templates[i]->clone();
    }
    // Si aucun template correspondant n'est trouvé, retourne NULL
    return NULL;
}