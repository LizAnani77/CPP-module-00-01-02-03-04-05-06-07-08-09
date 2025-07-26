/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:15:28 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/25 18:34:21 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal 
{
public:
    // Constructeur par défaut - initialise un animal de type "Dog"
    Dog();
    
    // Constructeur de copie - crée une copie exacte d'un Dog existant
    Dog(const Dog& other);
    
    // Destructeur virtuel - libère les ressources spécifiques au Dog
    virtual ~Dog();
    
    // Opérateur d'affectation - assigne les attributs d'un Dog à un autre
    Dog& operator=(const Dog& other);
    
    // Remplace la méthode makeSound de la classe Animal avec un aboiement
    virtual void makeSound() const;
};

#endif