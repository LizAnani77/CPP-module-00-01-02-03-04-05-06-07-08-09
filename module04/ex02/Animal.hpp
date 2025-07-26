/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 22:45:10 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/03/04 11:51:11 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal 
{
protected:
    std::string type;  // Type de l'animal, utilisé pour l'identification

public:
    // Constructeur par défaut - initialise avec "AAnimal"
    Animal();
    
    // Constructeur de copie - duplique un Animal existant
    Animal(const Animal& other);
    
    // Destructeur virtuel - essentiel pour le polymorphisme
    virtual ~Animal();
    
    // Opérateur d'affectation - copie les attributs
    Animal& operator=(const Animal& other);

    // Méthode virtuelle pure - doit être implémentée par les classes dérivées
    virtual void makeSound() const = 0;
    
    // Accesseur pour obtenir le type de l'animal
    std::string getType() const;
};

#endif