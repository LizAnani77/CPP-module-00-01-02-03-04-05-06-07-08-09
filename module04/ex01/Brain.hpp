/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 21:37:33 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/25 19:05:46 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

class Brain 
{
private:
    std::string ideas[100];  // Tableau contenant 100 idées/pensées

public:
    // Constructeur par défaut - initialise avec des pensées vides
    Brain();
    
    // Constructeur de copie - duplique toutes les idées
    Brain(const Brain& other);
    
    // Destructeur - libère les ressources
    ~Brain();
    
    // Opérateur d'affectation - copie toutes les idées
    Brain& operator=(const Brain& other);

    // Définit une idée à l'index spécifié
    void setIdea(int index, const std::string& idea);
    
    // Récupère l'idée à l'index spécifié
    std::string getIdea(int index) const;
};

#endif