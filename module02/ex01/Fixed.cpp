/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 23:01:04 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/21 11:58:41 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "Fixed.hpp"

// Constructeurs et destructeur
Fixed::Fixed() : _value(0)
{
    // Initialise un nouveau nombre Fixed à 0
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) : _value(n << _fractionalBits)
{
    // Conversion d'un entier vers Fixed
    // Exemple: 42 devient 42 * 256 = 10752 en interne
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n) : _value(roundf(n * (1 << _fractionalBits)))
{
    // Conversion d'un flottant vers Fixed
    // Multiplie par 256 et arrondit pour avoir une représentation précise
    // Exemple: 42.42f devient round(42.42 * 256) = 10859
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src)
{
    // Crée une copie exacte d'un autre nombre Fixed
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

// Opérateurs
Fixed& Fixed::operator=(const Fixed& rhs)
{
    // Copie la valeur d'un Fixed vers un autre
    // Vérifie qu'on ne copie pas un objet sur lui-même
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->_value = rhs.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    // La destruction est simple car nous n'utilisons que de la mémoire stack
    std::cout << "Destructor called" << std::endl;
}

// Méthodes de conversion
float Fixed::toFloat(void) const
{
    // Convertit la représentation fixe en float
    // Divise par 256 pour replacer la virgule correctement
    return (float)this->_value / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
    // Convertit en entier en supprimant la partie fractionnaire
    return this->_value >> _fractionalBits;
}

// Méthodes d'accès
int Fixed::getRawBits(void) const
{
    // Accès direct à la valeur initiale stockée
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    // Modification directe de la valeur initiale
    this->_value = raw;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    // Affiche le nombre Fixed sous forme décimale via conversion en float
    out << fixed.toFloat();
    return out;
}

// Surcharge d'opérateur externe = fonction indépendante qui permet d'appliquer un opérateur à des objets 