/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:56:49 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/17 10:43:59 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    // Test 1: Petite horde
    int N = 3;
    Zombie* horde1 = zombieHorde(N, "Walker");
    for (int i = 0; i < N; ++i)
    {
        std::cout << "Zombie " << i + 1 << " : ";
        horde1[i].announce();
    }
    delete[] horde1;

    // Test 2: Grande horde
    N = 50;
    Zombie* horde2 = zombieHorde(N, "Walker");
    for (int i = 0; i < N; ++i)
    {
        std::cout << "Zombie " << i + 1 << " : ";
        horde2[i].announce();
    }
    delete[] horde2;

    // Test 3: Pas de zombie (N = 0)
    N = 0;
    Zombie* horde3 = zombieHorde(N, "Walker");
    if (!horde3)
    {
        std::cout << "No zombies created for N = 0." << std::endl;
    }

    // Test 4: Nombre négatif de zombies
    N = -5;
    Zombie* horde4 = zombieHorde(N, "Walker");
    if (!horde4)
    {
        std::cout << "No zombies created for N = -5." << std::endl;
    }
    return 0;
}