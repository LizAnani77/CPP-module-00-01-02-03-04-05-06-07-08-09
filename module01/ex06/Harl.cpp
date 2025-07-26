/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 21:10:34 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/17 15:25:43 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::LogLevel Harl::logLevels[4] =
{
    {"DEBUG", &Harl::debug},
    {"INFO", &Harl::info},
    {"WARNING", &Harl::warning},
    {"ERROR", &Harl::error}
};

Harl::Harl() {}
Harl::~Harl() {}
// Constructeur et Destructeur
// Initialise et nettoie l'objet Harl

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my "
              << "7XL-double-cheese-triple-pickle-special-ketchup burger. "
              << "I really do!" << std::endl << std::endl;
}

void Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. "
              << "You didn't put enough bacon in my burger! "
              << "If you did, I wouldn't be asking for more!" << std::endl << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. "
              << "I've been coming for years whereas you started working here since last month." 
              << std::endl << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now."
              << std::endl << std::endl;
}

int Harl::getLevelIndex(std::string level) const
// Fonction : getLevelIndex
// Convertit un niveau textuel en index numérique
// Retourne l'index du niveau ou -1 si non trouvé
{
    for (int i = 0; i < 4; i++)
    // Parcourt le tableau des niveaux de log
	{
        if (level == logLevels[i].level)
        // Compare le niveau recherché avec chaque niveau du tableau
            return i;
            // Si trouvé, retourne l'index correspondant
    }
    return -1;
    // Si aucune correspondance n'est trouvée, retourne -1
}

void Harl::complain(std::string level)
// Fonction : complain
// Émet une plainte d'un niveau spécifique
{
    int idx = getLevelIndex(level);
    // Obtient l'index correspondant au niveau de plainte demandé
    if (idx != -1)
    // Si le niveau est valide (index différent de -1)
        (this->*logLevels[idx].function)();
        // Appelle la fonction membre correspondante via le pointeur stocké dans logLevels
}

void Harl::filterComplain(std::string level)
// Fonction : filterComplain
// Implémente un système de filtrage en cascade des plaintes
// Note : Utilise un switch pour afficher tous les niveaux
//        à partir du niveau spécifié
{
    int levelIndex = getLevelIndex(level);
    
    switch (levelIndex) 
    {
        case 0:
            std::cout << "[ DEBUG ]" << std::endl;
            debug();
        case 1:
            std::cout << "[ INFO ]" << std::endl;
            info();
        case 2:
            std::cout << "[ WARNING ]" << std::endl;
            warning();
        case 3:
            std::cout << "[ ERROR ]" << std::endl;
            error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}