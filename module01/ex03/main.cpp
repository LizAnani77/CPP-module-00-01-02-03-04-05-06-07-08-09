/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 01:39:46 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/16 15:37:54 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        // Crée une arme initiale
        HumanA bob("Bob", club);
        // Crée un HumanA avec une arme (obligatoire)
        bob.attack();
        // Test d'attaque avec l'arme initiale
        club.setType("some other type of club");
        // Modifie le type d'arme
        bob.attack();
        // Test d'attaque avec l'arme modifiée
    }
    
    {
        Weapon club = Weapon("crude spiked club");
        // Crée une arme initiale
        HumanB jim("Jim");
        // Crée un HumanB sans arme
        jim.setWeapon(club);
        // Équipe Jim avec l'arme
        jim.attack();
        // Test d'attaque avec l'arme initiale
        club.setType("some other type of club");
        // Modifie le type d'arme
        jim.attack();
         // Test d'attaque avec l'arme modifiée
    }
    return 0;
}