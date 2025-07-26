/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 21:53:04 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/17 10:35:11 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie
// Classe : Zombie
// Représente un zombie avec un nom et des fonctionnalités de base
{
private:
    std::string name;
    // Attribut stockant le nom du zombie

public:
    Zombie();
    // Constructeur : Initialise un zombie sans nom
    Zombie(std::string name);
    // Constructeur : Initialise un zombie avec le nom spécifié
    // Paramètres : name : Le nom à donner au zombie

    ~Zombie();
    // Destructeur : Affiche un message lors de la destruction du zombie
    
    void setName(std::string name);
    // Fonction : setName
    // Modifie le nom du zombie
    // Paramètres : name : Le nouveau nom à attribuer au zombie 

    void announce(void);
    // Fonction : announce
    // Fait annoncer le zombie en affichant son nom et sa phrase caractéristique
};

Zombie* zombieHorde(int N, std::string name);
// Fonction : zombieHorde
// Crée une horde de zombies sur la heap
// Retourne un pointeur vers le premier zombie de la horde ou NULL si N <= 0
// Paramètres : 
//   N : Nombre de zombies à créer dans la horde
//   name : Le nom à donner à tous les zombies de la horde

#endif