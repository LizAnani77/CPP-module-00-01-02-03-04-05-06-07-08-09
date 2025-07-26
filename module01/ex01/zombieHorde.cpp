/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:55:31 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/17 10:33:38 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
// Fonction : zombieHorde
// Crée et initialise un tableau de zombies sur la heap
// Retourne un pointeur vers le tableau de zombies ou NULL si N <= 0
// Paramètres :
//   N : Nombre de zombies à créer
//   name : Nom à donner à chaque zombie de la horde

{
    if (N <= 0)
        return NULL;

    Zombie* horde = new Zombie[N];
    // Allocation dynamique du tableau de zombies
    // Crée un tableau de N zombies sur la heap
    for (int i = 0; i < N; i++)
    // Initialisation de chaque zombie avec le nom fourni
    {
        horde[i].setName(name);
    }

    return horde;
    // Retourne le pointeur vers le début du tableau
}