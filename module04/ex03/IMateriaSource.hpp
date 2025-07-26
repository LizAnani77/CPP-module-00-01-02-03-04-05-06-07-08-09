/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:36:53 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/25 19:17:25 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource 
{
public:
    // Destructeur virtuel - nécessaire pour une interface
    virtual ~IMateriaSource() {}
    
    // Mémorise une materia pour pouvoir la reproduire plus tard
    virtual void learnMateria(AMateria*) = 0;
    
    // Crée une nouvelle materia du type spécifié si elle est connue
    virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif