/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 23:00:44 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/21 11:53:48 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
// Cette classe implémente une représentation en virgule fixe des nombres réels.
// Elle utilise un entier 32 bits dont 8 bits sont réservés pour la partie fractionnaire,
// permettant ainsi de représenter des nombres décimaux avec une précision fixe.
{
private:
    int _value;
    // Stocke le nombre en virgule fixe sous forme d'un entier
    // Par exemple : 42.42 sera stocké comme 42.42 * 256 (2^8)
    
    static const int _fractionalBits = 8;
    // Nombre de bits utilisés pour la partie fractionnaire


public:
    // Constructeurs
    Fixed();
    // Constructeur par défaut - initialise à 0

    Fixed(const int n);
    // Constructeur à partir d'un entier
    // Convertit l'entier en format virgule fixe en le multipliant par 256 (2^8)

    Fixed(const float n);
    // Constructeur à partir d'un flottant
    // Convertit le flottant en format virgule fixe en le multipliant par 256 (2^8)

    Fixed(const Fixed& src);
    // Constructeur de copie - crée une copie exacte d'un autre nombre Fixed

    // Opérateurs
    Fixed& operator=(const Fixed& rhs);
    // Opérateur d'affectation - copie les valeurs d'un Fixed vers un autre
    
    ~Fixed();
    // Destructeur - requis pour la forme canonique

    // Méthodes de conversion et d'accès
    int getRawBits(void) const;
    // Retourne la valeur initiale stockée sans conversion

    void setRawBits(int const raw);
    // Définit directement la valeur initiale

    float toFloat(void) const;
    // Convertit le nombre Fixed en float
    // Divise la valeur initiale par 256 pour retrouver le nombre décimal

    int toInt(void) const;
    // Convertit le nombre Fixed en entier
    // Élimine la partie fractionnaire par décalage à droite
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
// Permet d'utiliser std::cout avec nos nombres Fixed
// Les affichent sous forme décimale

// Surcharge d'opérateur externe = fonction indépendante qui permet d'appliquer un opérateur à des objets 

#endif