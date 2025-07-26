/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:18:45 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/21 10:58:12 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
// Constructeur par défaut qui initialise la valeur à 0
// Affiche un message pour suivre l'utilisation des constructeurs
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
// Constructeur de copie qui duplique l'objet existant
// Utilise l'opérateur d'affectation pour la copie
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy; // Réutilise l'opérateur d'affectation
}

Fixed& Fixed::operator=(const Fixed& copy)
// Opérateur d'affectation qui copie les valeurs d'un objet vers un autre
// Vérifie l'auto-affectation (a = a) pour éviter les problèmes
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy) // Protection contre l'auto-affectation
        this->_value = copy.getRawBits();
    return *this;
}

Fixed::~Fixed()
// Destructeur - pas de ressources à libérer mais nécessaire pour la forme canonique
// Affiche un message pour suivre la destruction des objets
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
// Retourne la valeur initiale stockée sans conversion
// Affiche un message pour suivre l'accès aux données
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw)
// Définit directement la valeur initiale
// Permet de modifier la représentation interne du nombre
{
    this->_value = raw;
}