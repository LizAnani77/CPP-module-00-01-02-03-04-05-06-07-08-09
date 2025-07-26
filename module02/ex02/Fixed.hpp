/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 23:31:05 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/21 13:21:57 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
// Cette classe implémente une représentation personnalisée des nombres décimaux
// en utilisant une représentation en virgule fixe. Elle offre toutes les opérations
// mathématiques courantes et des fonctionnalités de comparaison.
{
private:
    int _value;
    // La valeur du nombre en format virgule fixe
    // Exemple: Pour représenter 42.42, on stocke 42.42 * 256 = 10859

    static const int _fractionalBits = 8;
    // Définit la précision de nos nombres (8 bits)
    // Permet de représenter 256 fractions différentes entre chaque entier

public:
    // -------- Constructeurs et Destructeur --------
    Fixed();                    // Initialise à 0
    Fixed(const int n);         // Convertit un entier en virgule fixe
    Fixed(const float n);       // Convertit un flottant en virgule fixe
    Fixed(const Fixed& src);    // Crée une copie d'un nombre existant
    ~Fixed();                   // Nettoyage

    // -------- Opérateur d'affectation --------
    Fixed& operator=(const Fixed& rhs);  // Copie les valeurs

    // -------- Opérateurs de comparaison --------
    bool operator>(const Fixed& rhs) const;   // Plus grand que
    bool operator<(const Fixed& rhs) const;   // Plus petit que
    bool operator>=(const Fixed& rhs) const;  // Plus grand ou égal
    bool operator<=(const Fixed& rhs) const;  // Plus petit ou égal
    bool operator==(const Fixed& rhs) const;  // Égal
    bool operator!=(const Fixed& rhs) const;  // Différent

    // -------- Opérateurs arithmétiques --------
    Fixed operator+(const Fixed& rhs) const;  // Addition
    Fixed operator-(const Fixed& rhs) const;  // Soustraction
    Fixed operator*(const Fixed& rhs) const;  // Multiplication
    Fixed operator/(const Fixed& rhs) const;  // Division

    // -------- Opérateurs d'incrémentation/décrémentation --------
    Fixed& operator++();     // Pré-incrémentation (++x)
    Fixed operator++(int);   // Post-incrémentation (x++)
    Fixed& operator--();     // Pré-décrémentation (--x)
    Fixed operator--(int);   // Post-décrémentation (x--)

    // -------- Méthodes de conversion et d'accès --------
    int getRawBits(void) const;     // Obtient la valeur initiale
    void setRawBits(int const raw); // Définit la valeur initiale
    float toFloat(void) const;      // Convertit en float
    int toInt(void) const;          // Convertit en int

    // -------- Méthodes statiques de comparaison --------
    // Permettent de comparer deux nombres sans modifier leurs valeurs
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};

// -------- Opérateur de flux --------
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
// Permet d'utiliser std::cout pour afficher nos nombres

// Surcharge d'opérateur externe = fonction indépendante qui permet d'appliquer un opérateur à des objets 
#endif