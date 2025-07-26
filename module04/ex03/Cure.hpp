/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:34:36 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/25 19:21:09 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
public:
    // Constructeur par défaut - initialise une materia de soin
    Cure();
    
    // Destructeur virtuel - libère les ressources spécifiques
    virtual ~Cure();
    
    // Constructeur de copie - duplique une materia de soin
    Cure(const Cure& other);
    
    // Opérateur d'affectation - copie les attributs d'une materia de soin
    Cure& operator=(const Cure& other);

    // Implémente la méthode clone pour créer une copie de la materia de soin
    virtual AMateria* clone() const;
    
    // Implémente l'effet spécifique du soin sur une cible
    virtual void use(ICharacter& target);
};

#endif