/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 01:29:04 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/21 14:05:49 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// -------- CONSTRUCTEURS ET DESTRUCTEUR --------

Point::Point() : x(0), y(0)
// Crée un point à l'origine
// x et y sont initialisés à 0 avec Fixed(0)
{}

Point::Point(const float x_val, const float y_val) : x(Fixed(x_val)), y(Fixed(y_val))
// Crée un point avec les coordonnées spécifiées
// Convertit automatiquement les nombres flottants en nombres à virgule fixe
{}

Point::Point(const Point& rhs) : x(rhs.x), y(rhs.y)
// Crée une copie d'un autre point
// Copie directement les coordonnées x et y
{}

Point::~Point()
// Destructeur
// Ne fait rien car pas de mémoire à libérer
{}

// -------- OPÉRATEURS --------

Point& Point::operator=(const Point& rhs)
// Opérateur d'affectation
// Ne fait rien car x et y sont constants
// Présent uniquement pour la forme canonique
{
    (void)rhs;  // Évite l'avertissement de variable non utilisée
    return *this;
}

// -------- ACCESSEURS --------

Fixed Point::getX() const
// Renvoie la coordonnée x
// La valeur retournée ne peut pas être modifiée (const)
{
    return this->x;
}

Fixed Point::getY() const
// Renvoie la coordonnée y
// La valeur retournée ne peut pas être modifiée (const)
{
    return this->y;
}