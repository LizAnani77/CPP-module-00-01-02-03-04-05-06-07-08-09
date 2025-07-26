/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 01:07:07 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/06/02 16:55:39 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

void printSeparator(const std::string& title) {
    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << "  " << title << std::endl;
    std::cout << std::string(50, '=') << std::endl;
}

int main(void)
{
    // ========== TEST OBLIGATOIRE DU SUJET ==========
    printSeparator("TEST OBLIGATOIRE DU SUJET");
    {
        Fixed a;
        Fixed const b(Fixed(5.05f) * Fixed(2));
        
        std::cout << "a = " << a << std::endl;
        std::cout << "++a = " << ++a << std::endl;
        std::cout << "a = " << a << std::endl;
        std::cout << "a++ = " << a++ << std::endl;
        std::cout << "a = " << a << std::endl;
        std::cout << "b = " << b << std::endl;
        std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;
    }

    // ========== TEST DES CONSTRUCTEURS ==========
    printSeparator("TEST DES CONSTRUCTEURS");
    {
        Fixed defaut;                    // Constructeur par défaut
        Fixed entier(42);               // Constructeur int
        Fixed decimal(3.14159f);        // Constructeur float
        Fixed copie(entier);            // Constructeur de copie
        Fixed affectation = decimal;    // Opérateur d'affectation
        
        std::cout << "Défaut: " << defaut << std::endl;
        std::cout << "Entier (42): " << entier << std::endl;
        std::cout << "Décimal (3.14159f): " << decimal << std::endl;
        std::cout << "Copie d'entier: " << copie << std::endl;
        std::cout << "Affectation décimal: " << affectation << std::endl;
    }

    // ========== TEST DES COMPARAISONS ==========
    printSeparator("TEST DES OPÉRATEURS DE COMPARAISON");
    {
        Fixed a(10);
        Fixed b(5.5f);
        Fixed c(10);
        
        std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
        std::cout << "a > b: " << (a > b ? "true" : "false") << std::endl;
        std::cout << "a < b: " << (a < b ? "true" : "false") << std::endl;
        std::cout << "a >= c: " << (a >= c ? "true" : "false") << std::endl;
        std::cout << "a <= b: " << (a <= b ? "true" : "false") << std::endl;
        std::cout << "a == c: " << (a == c ? "true" : "false") << std::endl;
        std::cout << "a != b: " << (a != b ? "true" : "false") << std::endl;
    }

    // ========== TEST DES OPÉRATIONS ARITHMÉTIQUES ==========
    printSeparator("TEST DES OPÉRATIONS ARITHMÉTIQUES");
    {
        Fixed a(10);
        Fixed b(3);
        Fixed c(2.5f);
        
        std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
        std::cout << "a + b = " << (a + b) << std::endl;
        std::cout << "a - b = " << (a - b) << std::endl;
        std::cout << "a * c = " << (a * c) << std::endl;
        std::cout << "a / b = " << (a / b) << std::endl;
        std::cout << "c * c = " << (c * c) << std::endl;
    }

    // ========== TEST DES INCRÉMENTATIONS ==========
    printSeparator("TEST DES INCRÉMENTATIONS/DÉCRÉMENTATIONS");
    {
        Fixed x(5);
        std::cout << "Valeur initiale x: " << x << std::endl;
        
        std::cout << "Pré-incrémentation ++x: " << ++x << std::endl;
        std::cout << "Valeur après ++x: " << x << std::endl;
        
        std::cout << "Post-incrémentation x++: " << x++ << std::endl;
        std::cout << "Valeur après x++: " << x << std::endl;
        
        std::cout << "Pré-décrémentation --x: " << --x << std::endl;
        std::cout << "Valeur après --x: " << x << std::endl;
        
        std::cout << "Post-décrémentation x--: " << x-- << std::endl;
        std::cout << "Valeur finale x: " << x << std::endl;
    }

    // ========== TEST DES FONCTIONS MIN/MAX ==========
    printSeparator("TEST DES FONCTIONS MIN/MAX");
    {
        Fixed a(42.42f);
        Fixed b(21.21f);
        const Fixed c(100);
        const Fixed d(50);
        
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "c = " << c << ", d = " << d << std::endl;
        
        std::cout << "min(a, b) = " << Fixed::min(a, b) << std::endl;
        std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;
        std::cout << "min(c, d) = " << Fixed::min(c, d) << " (const)" << std::endl;
        std::cout << "max(c, d) = " << Fixed::max(c, d) << " (const)" << std::endl;
    }

    // ========== TEST DE CONVERSION ==========
    printSeparator("TEST DE CONVERSION INT/FLOAT");
    {
        Fixed a(42.42f);
        Fixed b(-10);
        
        std::cout << "a = " << a << " -> toInt() = " << a.toInt() << std::endl;
        std::cout << "a = " << a << " -> toFloat() = " << a.toFloat() << std::endl;
        std::cout << "b = " << b << " -> toInt() = " << b.toInt() << std::endl;
        std::cout << "b = " << b << " -> toFloat() = " << b.toFloat() << std::endl;
    }

    // ========== TEST DE PRÉCISION ==========
    printSeparator("TEST DE PRÉCISION (8 bits fractionnaires)");
    {
        Fixed epsilon;
        ++epsilon;  // Plus petite valeur possible: 1/256 = 0.00390625
        
        std::cout << "Plus petite valeur (epsilon): " << epsilon << std::endl;
        std::cout << "En décimal: " << epsilon.toFloat() << std::endl;
        std::cout << "Calcul théorique: 1/256 = " << (1.0f/256.0f) << std::endl;
        
        Fixed precision_test(0.1f);
        std::cout << "Test 0.1f -> " << precision_test << std::endl;
        std::cout << "Différence avec 0.1: " << (precision_test.toFloat() - 0.1f) << std::endl;
    }

    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << "  FIN DES TESTS" << std::endl;
    std::cout << std::string(50, '=') << std::endl;

    return 0;
}