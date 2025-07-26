/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:26:12 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/16 12:36:15 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{

    std::cout << "Creating a zombie on the heap:" << std::endl;
    Zombie* heapZombie = newZombie("Heap Walker");
    // Crée un zombie sur la heap et garde son pointeur
    
    heapZombie->announce();
    // Fait s'annoncer le zombie sur la heap
    delete heapZombie;
    // Libère la mémoire allouée pour le zombie sur la heap

    std::cout << "\nCreating a zombie on the stack:" << std::endl;
    randomChump("Stack Crawler");
   // Crée un zombie temporaire sur la stack qui s'annonce et est détruit automatiquement

    
    return 0;
}

// int main()
// {
//     // Test 1 : Création multiple de zombies sur le tas
//     Zombie* z1 = newZombie("Alice");
//     Zombie* z2 = newZombie("Bob");
//     z1->announce();
//     z2->announce();
//     delete z1;
//     delete z2;

//     // Test 2 : Plusieurs zombies sur la pile
//     randomChump("Charlie");
//     randomChump("David");

//     // Test 3 : Mélange des deux
//     Zombie* z3 = newZombie("Eve");
//     z3->announce();
//     randomChump("Frank");
//     delete z3;

//     return 0;
// }