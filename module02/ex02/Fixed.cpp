/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 23:39:47 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/06/02 16:51:16 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _value(0)
// Constructeur par défaut
// Quand on crée un nombre Fixed sans préciser de valeur, il est initialisé à zéro
// Exemple: Fixed a; // a vaut 0
{}

Fixed::Fixed(const int n) : _value(n << _fractionalBits)
// Constructeur qui convertit un nombre entier en nombre à virgule fixe
// Pour stocker l'entier, on le décale de 8 positions vers la gauche
// Exemple: Si n = 5
//    5 en binaire            = 00000101
//    5 décalé de 8 positions = 00000101 00000000
//    Donc 5 est stocké comme 1280 en interne (5 * 256)
{}

Fixed::Fixed(const float n) : _value(roundf(n * (1 << _fractionalBits)))
// Constructeur qui convertit un nombre décimal en nombre à virgule fixe
// Pour stocker le décimal, on le multiplie par 256 et on arrondit le résultat
// Exemple: Si n = 5.5
//    5.5 * 256 = 1408
//    1408 est la valeur stockée en interne
{}

Fixed::Fixed(const Fixed& source)
// Constructeur de copie - crée un nouveau nombre Fixed identique à un autre
// Utilise l'opérateur = pour faire la copie
{
    *this = source;
}

Fixed::~Fixed()
// Destructeur - appelé quand un nombre Fixed est détruit
{}

// =============== OPÉRATEURS DE BASE ===============

Fixed& Fixed::operator=(const Fixed& rhs)
// L'opérateur = permet de copier un nombre Fixed dans un autre
// Exemple: a = b; // Copie la valeur de b dans a
{
    if (this != &rhs)  // Vérifie qu'on ne copie pas un nombre sur lui-même
        this->_value = rhs.getRawBits();
    return *this;
}

// =============== OPÉRATEURS DE COMPARAISON ===============

bool Fixed::operator>(const Fixed& rhs) const  
// Vérifie si ce nombre est plus grand que l'autre
{ return _value > rhs._value; }

bool Fixed::operator<(const Fixed& rhs) const  
// Vérifie si ce nombre est plus petit que l'autre
{ return _value < rhs._value; }

bool Fixed::operator>=(const Fixed& rhs) const 
// Vérifie si ce nombre est plus grand ou égal à l'autre
{ return _value >= rhs._value; }

bool Fixed::operator<=(const Fixed& rhs) const 
// Vérifie si ce nombre est plus petit ou égal à l'autre
{ return _value <= rhs._value; }

bool Fixed::operator==(const Fixed& rhs) const 
// Vérifie si les deux nombres sont égaux
{ return _value == rhs._value; }

bool Fixed::operator!=(const Fixed& rhs) const 
// Vérifie si les deux nombres sont différents
{ return _value != rhs._value; }

// =============== OPÉRATEURS MATHÉMATIQUES ===============

Fixed Fixed::operator+(const Fixed& rhs) const
// Addition de deux nombres Fixed
// Exemple: c = a + b;
{
    Fixed resultat;
    resultat.setRawBits(_value + rhs._value);
    return resultat;
}

Fixed Fixed::operator-(const Fixed& rhs) const
// Soustraction de deux nombres Fixed
// Exemple: c = a - b;
{
    Fixed resultat;
    resultat.setRawBits(_value - rhs._value);
    return resultat;
}

Fixed Fixed::operator*(const Fixed& rhs) const
// Multiplication de deux nombres Fixed
// On doit ajuster le résultat car les deux nombres sont déjà multipliés par 256
{
    Fixed resultat;
    resultat.setRawBits((_value * rhs._value) >> _fractionalBits);
    return resultat;
}

Fixed Fixed::operator/(const Fixed& rhs) const
// Division de deux nombres Fixed
// Vérifie d'abord qu'on ne divise pas par zéro
{
    if (rhs._value == 0)
        throw std::runtime_error("You can't divide by zero!");
    Fixed resultat;
    // Multiplie d'abord par 256 pour ne pas perdre de précision
    resultat.setRawBits((_value << _fractionalBits) / rhs._value);
    return resultat;
}

// =============== OPÉRATEURS D'INCRÉMENTATION ===============

Fixed& Fixed::operator++()
// Augmente la valeur de 1/256 (++nombre)
// La valeur est augmentée avant d'être utilisée
{
    ++_value;
    return *this;
}

Fixed Fixed::operator++(int)
// Augmente la valeur de 1/256 (nombre++)
// La valeur originale est renvoyée, puis augmentée
{
    Fixed temp(*this);
    ++_value;
    return temp;
}

Fixed& Fixed::operator--()
// Diminue la valeur de 1/256 (--nombre)
// La valeur est diminuée avant d'être utilisée
{
    --_value;
    return *this;
}

Fixed Fixed::operator--(int)
// Diminue la valeur de 1/256 (nombre--)
// La valeur originale est renvoyée, puis diminuée
{
    Fixed temp(*this);
    --_value;
    return temp;
}

// =============== FONCTIONS DE CONVERSION ===============

int Fixed::getRawBits(void) const
// Renvoie la valeur initiale stockée en interne
{ return _value; }

void Fixed::setRawBits(int const valeur)
// Change directement la valeur initiale stockée
{ _value = valeur; }

float Fixed::toFloat(void) const
// Convertit le nombre Fixed en nombre décimal
// Divise la valeur par 256 pour retrouver le nombre d'origine
{ return (float)_value / (1 << _fractionalBits); }

int Fixed::toInt(void) const
// Convertit le nombre Fixed en nombre entier
// Enlève la partie décimale en décalant les bits vers la droite
{ return _value >> _fractionalBits; }

// =============== FONCTIONS MIN/MAX ===============

Fixed& Fixed::min(Fixed& a, Fixed& b)
// Renvoie le plus petit des deux nombres
{ return (a < b) ? a : b; }

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
// Version pour les nombres constants
{ return (a < b) ? a : b; }

Fixed& Fixed::max(Fixed& a, Fixed& b)
// Renvoie le plus grand des deux nombres
{ return (a > b) ? a : b; }

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
// Version pour les nombres constants
{ return (a > b) ? a : b; }

// =============== AFFICHAGE ===============

std::ostream& operator<<(std::ostream& sortie, const Fixed& nombre)
// Permet d'afficher un nombre Fixed avec cout
// Convertit d'abord le nombre en décimal pour l'afficher
{
    sortie << nombre.toFloat();
    return sortie;
}