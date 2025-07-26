/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 01:46:23 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/21 14:04:53 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "Fixed.hpp"

// =============== CONSTRUCTEURS ===============

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

Fixed::Fixed(const Fixed& rhs)
// Crée une copie exacte d'un autre nombre Fixed
{
    *this = rhs;
}

Fixed::~Fixed()
// Destructeur - appelé quand un nombre Fixed est détruit
{}

// =============== OPÉRATEURS DE BASE ===============

Fixed& Fixed::operator=(const Fixed& rhs)
// Copie la valeur d'un nombre dans un autre
// Vérifie qu'on ne copie pas un nombre sur lui-même
{
    if (this != &rhs)
        this->_value = rhs.getRawBits();
    return *this;
}

// =============== COMPARAISONS ===============

bool Fixed::operator>(const Fixed& rhs) const
// Vérifie si ce nombre est plus grand que l'autre
{ return _value > rhs._value; }

bool Fixed::operator<(const Fixed& rhs) const
// Vérifie si ce nombre est plus petit que l'rhs
{ return _value < rhs._value; }

bool Fixed::operator>=(const Fixed& rhs) const
// Vérifie si ce nombre est plus grand ou égal
{ return _value >= rhs._value; }

bool Fixed::operator<=(const Fixed& rhs) const
// Vérifie si ce nombre est plus petit ou égal
{ return _value <= rhs._value; }

bool Fixed::operator==(const Fixed& rhs) const
// Vérifie si les deux nombres sont égaux
{ return _value == rhs._value; }

bool Fixed::operator!=(const Fixed& rhs) const
// Vérifie si les deux nombres sont différents
{ return _value != rhs._value; }

// =============== OPÉRATIONS MATHÉMATIQUES ===============

Fixed Fixed::operator+(const Fixed& rhs) const
// Addition de deux nombres
// Les valeurs sont déjà dans le bon format, donc on peut les ajouter directement
{
    Fixed resultat;
    resultat.setRawBits(_value + rhs._value);
    return resultat;
}

Fixed Fixed::operator-(const Fixed& rhs) const
// Soustraction de deux nombres
{
    Fixed resultat;
    resultat.setRawBits(_value - rhs._value);
    return resultat;
}

Fixed Fixed::operator*(const Fixed& rhs) const
// Multiplication de deux nombres
// On doit réajuster la virgule car on multiplie deux nombres déjà décalés
{
    Fixed resultat;
    resultat.setRawBits((_value * rhs._value) >> _fractionalBits);
    return resultat;
}

Fixed Fixed::operator/(const Fixed& rhs) const
// Division de deux nombres
// Vérifie qu'on ne divise pas par zéro
{
    if (rhs._value == 0)
        throw std::runtime_error("Division par zéro impossible!");
    Fixed resultat;
    resultat.setRawBits((_value << _fractionalBits) / rhs._value);
    return resultat;
}

// =============== INCRÉMENTATION/DÉCRÉMENTATION ===============

Fixed& Fixed::operator++()
// ++nombre : Augmente de 1/256 et renvoie le nouveau nombre
{
    ++_value;
    return *this;
}

Fixed Fixed::operator++(int)
// nombre++ : Renvoie le nombre actuel et augmente de 1/256
{
    Fixed temp(*this);
    ++_value;
    return temp;
}

Fixed& Fixed::operator--()
// --nombre : Diminue de 1/256 et renvoie le nouveau nombre
{
    --_value;
    return *this;
}

Fixed Fixed::operator--(int)
// nombre-- : Renvoie le nombre actuel et diminue de 1/256
{
    Fixed temp(*this);
    --_value;
    return temp;
}

// =============== FONCTIONS DE CONVERSION ===============

int Fixed::getRawBits(void) const
// Renvoie la valeur stockée en interne
{ return _value; }

void Fixed::setRawBits(int const valeur)
// Change directement la valeur stockée
{ _value = valeur; }

float Fixed::toFloat(void) const
// Convertit en nombre décimal
// Divise par 256 pour replacer la virgule au bon endroit
{ return (float)_value / (1 << _fractionalBits); }

int Fixed::toInt(void) const
// Convertit en nombre entier
// Supprime la partie décimale en décalant les bits
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
// Convertit d'abord en décimal pour un affichage naturel
{
    sortie << nombre.toFloat();
    return sortie;
}