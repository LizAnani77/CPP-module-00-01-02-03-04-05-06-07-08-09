/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:43:15 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/25 18:39:53 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal 
{
public:
    // Constructeur par défaut - initialise un animal incorrect de type "WrongCat"
    WrongCat();
    
    // Constructeur de copie - crée une copie exacte d'un WrongCat existant
    WrongCat(const WrongCat& other);
    
    // Destructeur NON virtuel - problématique avec le polymorphisme
    ~WrongCat();
    
    // Opérateur d'affectation - assigne les attributs d'un WrongCat à un autre
    WrongCat& operator=(const WrongCat& other);
    
    // Méthode NON virtuelle - ne sera pas appelée correctement via un pointeur WrongAnimal
    void makeSound() const;
};

#endif