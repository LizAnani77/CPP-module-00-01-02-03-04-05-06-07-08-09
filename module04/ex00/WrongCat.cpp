/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:43:53 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/25 18:43:50 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() 
{
    // Initialise un animal incorrect de type "WrongCat"
    type = "WrongCat";
    std::cout << "😾 WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) 
{
    // Crée une copie exacte d'un WrongCat existant
    std::cout << "😾 WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat() 
{
    // Destructeur de WrongCat - ne sera pas appelé correctement en cas de polymorphisme
    std::cout << "😾 WrongCat destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) 
{
    // Assigne les attributs d'un WrongCat à un autre
    std::cout << "😾 WrongCat assignment operator called" << std::endl;
    WrongAnimal::operator=(other);
    return *this;
}

void WrongCat::makeSound() const 
{
    // Produit un son spécifique au chat incorrect
    // Cette méthode ne sera pas appelée via un pointeur WrongAnimal*
    std::cout << "😾 Wrong Meow! Wrong Meow!" << std::endl;
}