/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 22:45:10 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/25 19:05:29 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal 
{
protected:
    std::string type;  // Type d'animal, utilisé pour l'identification

public:
    // Constructeur par défaut - initialise avec "Unknown"
    Animal();
    
    // Constructeur de copie - duplique un Animal existant
    Animal(const Animal& other);
    
    // Destructeur virtuel - essentiel pour le polymorphisme
    virtual ~Animal();
    
    // Opérateur d'affectation - copie les attributs
    Animal& operator=(const Animal& other);

    // Méthode virtuelle pour émettre un son spécifique à l'animal
    virtual void makeSound() const;
    
    // Accesseur pour obtenir le type de l'animal
    std::string getType() const;
};

#endif