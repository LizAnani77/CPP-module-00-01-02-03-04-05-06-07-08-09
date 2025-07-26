/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:36:30 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/16 23:23:56 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>


Harl::LogLevel Harl::logLevels[4] =
// Initialisation du tableau static des niveaux de log
// Établit la correspondance entre chaque niveau et sa fonction
{
    {"DEBUG", &Harl::debug},
    {"INFO", &Harl::info},
    {"WARNING", &Harl::warning},
    {"ERROR", &Harl::error}
};


Harl::Harl() {}
Harl::~Harl() {}
// Constructeur et Destructeur
// Rôle : Initialisation et nettoyage de l'objet Harl
// Note : Implémentation vide car la classe n'utilise que des membres statiques
//        et n'a pas de ressources dynamiques à gérer

void Harl::debug(void)
{
    std::cout << "I love having extra bacon for my "
              << "7XL-double-cheese-triple-pickle-special-ketchup burger. "
              << "I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. "
              << "You didn't put enough bacon in my burger! "
              << "If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. "
              << "I've been coming for years whereas you started working here since last month." 
              << std::endl;
}

void Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now."
              << std::endl;
}

void Harl::complain(std::string level)
// Fonction : complain
// Rôle : Dispatche la plainte vers la fonction appropriée selon le niveau
// Paramètres : level - Le niveau de plainte à traiter

{
    for (int i = 0; i < 4; i++)
    // Parcourt le tableau des niveaux de log
	{
        if (level == logLevels[i].level)
        // Si le niveau correspond, appelle la fonction associée
		{
            (this->*logLevels[i].function)();
            // Utilise le pointeur sur membre pour appeler la fonction
            return;
        }
    }
    std::cout << "Invalid complaint level" << std::endl;
    // Affiche un message si le niveau n'est pas valide
}