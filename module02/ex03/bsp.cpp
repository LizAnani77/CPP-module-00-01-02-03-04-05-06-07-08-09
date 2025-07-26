/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 01:31:04 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/21 14:49:54 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

// =============== FONCTIONS UTILITAIRES ===============

static Fixed abs(Fixed x)
// Calcule la valeur absolue d'un nombre
// Exemple : abs(-5) donne 5, abs(3) reste 3
// Utilisé pour s'assurer que l'aire est toujours positive
{
    if (x.toFloat() < 0)
        return x * Fixed(-1);
    return x;
}

static Fixed area(Point const p1, Point const p2, Point const p3)
// Calcule l'aire d'un triangle à partir de ses trois sommets
// Utilise la formule du déterminant : 
// Aire = |x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)| / 2
{
    return abs(
        (p1.getX() * (p2.getY() - p3.getY()) +
         p2.getX() * (p3.getY() - p1.getY()) +
         p3.getX() * (p1.getY() - p2.getY())) / Fixed(2.0f)
    );
}

// =============== FONCTION PRINCIPALE BSP ===============

bool bsp(Point const a, Point const b, Point const c, Point const point)
// Détermine si un point est strictement à l'intérieur d'un triangle
// Le point ne doit pas être sur les bords ni sur les sommets
{
    // Calcul de l'aire du triangle complet ABC
    Fixed aireTriangle = area(a, b, c);
    
    // Calcul des trois aires partielles
    // Chaque aire partielle utilise le point P et deux sommets du triangle
    Fixed aire1 = area(point, b, c);    // Aire du triangle PBC
    Fixed aire2 = area(point, c, a);    // Aire du triangle PCA
    Fixed aire3 = area(point, a, b);    // Aire du triangle PAB
    
    // Vérifications
    // Si une aire est nulle, le point est sur une arête ou un sommet
    if (aire1.toFloat() == 0 || aire2.toFloat() == 0 || aire3.toFloat() == 0)
        return false;
    
    // Le point est à l'intérieur si la somme des aires partielles
    // est égale à l'aire totale
    return (aireTriangle.toFloat() == (aire1 + aire2 + aire3).toFloat());
}