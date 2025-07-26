/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:19:15 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/03/04 14:21:44 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal 
{
public:
    // Constructeur par défaut - initialise un animal de type "Cat"
    Cat();
    
    // Constructeur de copie - crée une copie exacte d'un Cat existant
    Cat(const Cat& other);
    
    // Destructeur virtuel - libère les ressources spécifiques au Cat
    virtual ~Cat();
    
    // Opérateur d'affectation - assigne les attributs d'un Cat à un autre
    Cat& operator=(const Cat& other);
    
    // Remplace la méthode makeSound de la classe Animal avec un miaulement
    virtual void makeSound() const;
};

#endif