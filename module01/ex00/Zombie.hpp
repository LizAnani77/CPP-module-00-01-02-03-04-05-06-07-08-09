/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:19:50 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/17 10:13:03 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie
{
private:
    std::string name;
    // Attribut stockant le nom du zombie

public:
    Zombie(std::string name);
    // Constructeur : Initialise un nouveau zombie avec le nom spécifié
    ~Zombie(void);
     // Destructeur : Affiche un message lors de la destruction du zombie

    void announce(void);
    // Fonction : announce
    // Annonce le zombie en affichant son nom suivi d'un message caractéristique
};

Zombie* newZombie(std::string name);
// Fonction : newZombie
// Crée un nouveau zombie sur la heap et retourne son pointeur
// Paramètres : name : Le nom à donner au nouveau zombie
void randomChump(std::string name);
// Fonction : randomChump
// Crée un zombie temporaire sur la stack le fait s'annoncer, puis le détruit
// Paramètres : name : Le nom à donner au zombie temporaire

#endif