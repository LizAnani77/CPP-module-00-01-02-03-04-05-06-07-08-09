/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:10:48 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/28 17:59:09 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal 
{
protected:
    std::string type;  // Type d'animal, accessible aux classes dérivées

public:
    // Constructeur par défaut - initialise un animal de type "Unknown"
    Animal();
    
    // Constructeur de copie - crée une copie exacte d'un animal existant
    Animal(const Animal& other);
    
    // Destructeur virtuel - garantit l'appel correct des destructeurs des classes dérivées
    virtual ~Animal();
    
    // Opérateur d'affectation - assigne les attributs d'un animal à un autre
    Animal& operator=(const Animal& other);
    
    // Méthode virtuelle pour produire un son spécifique à l'animal
    // Cette méthode peut être redéfinie dans les classes dérivées
    virtual void makeSound() const;
    
    // Renvoie le type de l'animal
    std::string getType() const;
};

#endif