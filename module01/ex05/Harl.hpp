/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:35:23 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/16 23:08:42 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl
// Classe : Harl
// Rôle : Simule un système de journalisation de plaintes avec différents niveaux
//        en utilisant des pointeurs sur membres de fonction pour le dispatch
{
private:
    
    typedef void (Harl::*LogFunction)(void);
    // Type : LogFunction
    // Rôle : Définit un type pour les pointeurs sur membres de fonction
    //        qui ne prennent pas de paramètres et ne retournent rien

    // Fonctions privées pour chaque niveau de plainte
    // Ces fonctions sont appelées via des pointeurs sur membres
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

    struct LogLevel
    // Structure : LogLevel
    // Rôle : Associe un niveau de log à sa fonction correspondante
	{
        std::string level;
        // Nom du niveau (DEBUG, INFO, etc.)
        LogFunction function;
        // Pointeur vers la fonction associée

    };

    static LogLevel logLevels[4];
    // Tableau static : logLevels
    // Rôle : Stocke la correspondance entre les niveaux et leurs fonctions
    // Note : Static car partagé entre toutes les instances de Harl

public:

    Harl();
    // Constructeur : Initialise une instance de Harl
    ~Harl();
    // Destructeur : Nettoie l'instance de Harl

    void complain(std::string level);
    // Fonction : complain
    // Rôle : Interface publique pour émettre une plainte d'un niveau donné
    // Paramètres : level - Le niveau de plainte (DEBUG, INFO, WARNING, ERROR) 
};

#endif