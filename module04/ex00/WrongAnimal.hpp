/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:34:52 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/25 18:37:48 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal 
{
protected:
    std::string type;  // Type d'animal incorrect, accessible aux classes dérivées

public:
    // Constructeur par défaut - initialise un animal incorrect de type "WrongUnknown"
    WrongAnimal();
    
    // Constructeur de copie - crée une copie exacte d'un animal incorrect existant
    WrongAnimal(const WrongAnimal& other);
    
    // Destructeur NON virtuel - ne garantit pas l'appel correct des destructeurs dérivés
    ~WrongAnimal();
    
    // Opérateur d'affectation - assigne les attributs d'un animal incorrect à un autre
    WrongAnimal& operator=(const WrongAnimal& other);
    
    // Méthode NON virtuelle - ne sera pas substituée correctement dans les classes dérivées
    void makeSound() const;
    
    // Renvoie le type de l'animal incorrect
    std::string getType() const;
};

#endif