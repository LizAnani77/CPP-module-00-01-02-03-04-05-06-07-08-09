/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 23:02:51 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/21 13:06:06 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    // Crée un objet Fixed par défaut
    Fixed const b(10);
    // Crée un objet Fixed constant à partir d'un entier
    Fixed const c(42.42f);
    // Crée un Fixed constant à partir d'un flottant
    Fixed const d(b);
    // Crée un Fixed constant en copiant b

    a = Fixed(1234.4321f);
    // Assigne à 'a' un nouveau Fixed créé à partir d'un flottant

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    // Test d'affichage des valeurs en utilisant l'opérateur <<
    
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    // Test de conversion en entier pour chaque objet
    
    return 0;
}