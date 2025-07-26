/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 01:28:41 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/21 14:23:41 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
// Cette classe représente un point dans un espace 2D
// Elle utilise des nombres à virgule fixe pour les coordonnées
// Les coordonnées sont constantes après leur initialisation
{
private:
    const Fixed x;
    // La coordonnée x du point
    // Utilise un nombre à virgule fixe pour plus de précision
    // Est constante une fois initialisée
    
    const Fixed y;
    // La coordonnée y du point
    // Utilise un nombre à virgule fixe pour plus de précision
    // Est constante une fois initialisée

public:
    Point();
    // Crée un point à l'origine (0,0)
    // Utilise le constructeur par défaut de Fixed pour les coordonnées
    
    Point(const float x, const float y);
    // Crée un point aux coordonnées spécifiées
    // x : position sur l'axe horizontal
    // y : position sur l'axe vertical
    // Les coordonnées sont converties en nombres à virgule fixe
    
    Point(const Point& rhs);
    // Crée une copie exacte d'un autre point
    // Copie les coordonnées x et y
    
    ~Point();
    // Destructeur

    Point& operator=(const Point& rhs);
    // L'opérateur = ne fait rien car les coordonnées sont constantes
    // Inclus pour respecter la forme canonique
    // Renvoie le point actuel sans modification

    Fixed getX() const;
    // Renvoie la coordonnée x du point
    // Retourne une copie, impossible de modifier la valeur
    
    Fixed getY() const;
    // Renvoie la coordonnée y du point
    // Retourne une copie, impossible de modifier la valeur
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
// Vérifie si un point est à l'intérieur d'un triangle
// a, b, c : les trois points qui forment le triangle
// point : le point à tester
// Retourne vrai uniquement si le point est strictement à l'intérieur
// (pas sur les bords ni sur les sommets)

#endif