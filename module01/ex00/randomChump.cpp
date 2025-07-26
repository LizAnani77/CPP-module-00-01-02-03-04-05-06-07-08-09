/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:24:53 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/17 10:05:30 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump(std::string name)
// Fonction : randomChump
// Crée un zombie sur la stack, le fait s'annoncer, puis le détruit automatiquement
// Paramètres : name : Le nom à donner au zombie temporaire
{
    Zombie zombie(name);
    zombie.announce();
}