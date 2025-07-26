/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:39:45 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/25 19:19:23 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource 
{
private:
    AMateria* templates[4]; // Modèles de materias (4 max)
    int count;              // Nombre de modèles mémorisés

public:
    // Constructeur par défaut - initialise une source de materias vide
    MateriaSource();
    
    // Destructeur virtuel - libère les modèles de materias
    virtual ~MateriaSource();
    
    // Constructeur de copie - effectue une copie profonde des modèles
    MateriaSource(const MateriaSource& other);
    
    // Opérateur d'affectation - copie profonde des attributs
    MateriaSource& operator=(const MateriaSource& other);

    // Implémente l'apprentissage d'une nouvelle materia
    virtual void learnMateria(AMateria* m);
    
    // Implémente la création d'une materia à partir d'un type connu
    virtual AMateria* createMateria(std::string const & type);
};

#endif