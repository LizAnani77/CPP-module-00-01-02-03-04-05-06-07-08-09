/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:32:57 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/25 19:18:21 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria 
{
public:
    // Constructeur par défaut - initialise une materia de glace
    Ice();
    
    // Destructeur virtuel - libère les ressources spécifiques
    virtual ~Ice();
    
    // Constructeur de copie - duplique une materia de glace
    Ice(const Ice& other);
    
    // Opérateur d'affectation - copie les attributs d'une materia de glace
    Ice& operator=(const Ice& other);

    // Implémente la méthode clone pour créer une copie de la materia de glace
    virtual AMateria* clone() const;
    
    // Implémente l'effet spécifique de la glace sur une cible
    virtual void use(ICharacter& target);
};

#endif