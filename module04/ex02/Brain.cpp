/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 21:37:56 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/25 19:14:40 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Constructeur par défaut - initialise avec des pensées vides
Brain::Brain() 
{
    std::cout << "🧠 Brain constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = "Empty thought";
}

// Constructeur de copie - duplique toutes les idées
Brain::Brain(const Brain& other) 
{
    std::cout << "🧠 Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = other.ideas[i];
}

// Destructeur - libère les ressources
Brain::~Brain() 
{
    std::cout << "🧠 Brain destructor called" << std::endl;
}

// Opérateur d'affectation - copie toutes les idées
Brain& Brain::operator=(const Brain& other) 
{
    std::cout << "🧠 Brain assignment operator called" << std::endl;
    if (this != &other) 
    {
        for (int i = 0; i < 100; i++)
            ideas[i] = other.ideas[i];
    }
    return *this;
}

// Définit une idée à l'index spécifié
void Brain::setIdea(int index, const std::string& idea) 
{
    if (index >= 0 && index < 100)
        ideas[index] = idea;
}

// Récupère l'idée à l'index spécifié
std::string Brain::getIdea(int index) const 
{
    if (index >= 0 && index < 100)
        return ideas[index];
    return "Invalid idea index";
}