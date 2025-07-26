/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 01:32:04 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/18 13:37:37 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main(void) 
{
    // Test avec un point à l'intérieur du triangle
    Point a(0.0f, 0.0f);
    // Point : Sommet A du triangle
    // Coordonnées : Origine du repère (0,0)
    
    Point b(4.0f, 0.0f);
    // Point : Sommet B du triangle
    // Coordonnées : (4,0) sur l'axe X
    
    Point c(2.0f, 4.0f);
    // Point : Sommet C du triangle
    // Coordonnées : (2,4) formant un triangle isocèle
    
    Point point(2.0f, 2.0f);
    // Point : Point de test intérieur
    // Coordonnées : (2,2) situé au centre du triangle
    
    std::cout << "Test 1 - Point intérieur: " << std::endl;
    std::cout << "Point devrait être à l'intérieur: ";
    // Test 1 : Vérifie qu'un point clairement à l'intérieur est bien détecté
    if (bsp(a, b, c, point))
    {
        std::cout << "VRAI";
        // Résultat attendu : Le point est à l'intérieur
    }
    else
    {
        std::cout << "FAUX";
        // Résultat inattendu pour ce test
    }
    std::cout << std::endl;

    // Test avec un point à l'extérieur
    
    Point outside(6.0f, 6.0f);
    // Point : Point de test extérieur
    // Coordonnées : (6,6) clairement en dehors du triangle
    
    std::cout << "\nTest 2 - Point extérieur: " << std::endl;
    std::cout << "Point devrait être à l'extérieur: ";
    // Test 2 : Vérifie qu'un point clairement à l'extérieur est bien détecté
    if (bsp(a, b, c, outside))
    {
        std::cout << "VRAI";
        // Résultat inattendu pour ce test
    }
    else
    {
        std::cout << "FAUX";
        // Résultat attendu : Le point est à l'extérieur
    }
    std::cout << std::endl;

    // Test avec un point sur une arête
    Point edge(2.0f, 0.0f);
    // Point : Point de test sur une arête
    // Coordonnées : (2,0) exactement sur la base du triangle
    
    std::cout << "\nTest 3 - Point sur une arête: " << std::endl;
    std::cout << "Point devrait être à l'extérieur: ";
    // Test 3 : Vérifie qu'un point sur une arête est considéré comme extérieur
    if (bsp(a, b, c, edge))
    {
        std::cout << "VRAI";
        // Résultat inattendu : Le point sur une arête devrait être considéré extérieur
    }
    else
    {
        std::cout << "FAUX";
        // Résultat attendu : Le point sur une arête est considéré extérieur
    }
    std::cout << std::endl;

    // Test avec un point sur un sommet
    Point vertex(0.0f, 0.0f);
    // Point : Point de test sur un sommet
    // Coordonnées : (0,0) exactement sur le sommet A
    
    std::cout << "\nTest 4 - Point sur un sommet: " << std::endl;
    std::cout << "Point devrait être à l'extérieur: ";
    // Test 4 : Vérifie qu'un point sur un sommet est considéré comme extérieur
    if (bsp(a, b, c, vertex))
    {
        std::cout << "VRAI";
        // Résultat inattendu : Le point sur un sommet devrait être considéré extérieur
    }
    else
    {
        std::cout << "FAUX";
        // Résultat attendu : Le point sur un sommet est considéré extérieur
    }
    std::cout << std::endl;

    return 0;
    // Fin du programme de test
}