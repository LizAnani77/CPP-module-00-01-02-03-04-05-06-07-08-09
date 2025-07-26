/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:19:49 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/21 10:58:06 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    // Crée un premier objet Fixed avec le constructeur par défaut
    Fixed b(a);
    // Crée un deuxième objet Fixed en copiant a
    Fixed c;
    // Crée un troisième objet Fixed avec le constructeur par défaut

    c = b;
    // Copie les valeurs de b dans c en utilisant l'opérateur d'affectation

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    // Affiche les valeurs initiales des trois objets

    return 0;
}