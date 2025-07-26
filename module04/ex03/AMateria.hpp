/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:29:37 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/25 19:17:40 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class AMateria 
{
protected:
    std::string type;  // Type de la materia (ex: "ice", "cure")

public:
    // Constructeur avec type - initialise le type de materia
    AMateria(std::string const & type);
    
    // Destructeur virtuel - nécessaire pour une classe abstraite
    virtual ~AMateria();
    
    // Constructeur de copie - duplique une materia existante
    AMateria(const AMateria& other);
    
    // Opérateur d'affectation - copie les attributs d'une materia
    AMateria& operator=(const AMateria& other);

    // Getter pour le type de la materia
    std::string const & getType() const;
    
    // Méthode virtuelle pure pour créer une copie de la materia
    virtual AMateria* clone() const = 0;
    
    // Utilise la materia sur une cible, action par défaut
    virtual void use(ICharacter& target);
};

#endif