/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:15:28 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/25 19:06:17 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal 
{
private:
    Brain* brain;  // Pointeur vers un objet Brain, alloué dynamiquement

public:
    // Constructeur par défaut - crée un cerveau
    Dog();
    
    // Constructeur de copie - effectue une copie profonde
    Dog(const Dog& other);
    
    // Destructeur virtuel - libère le cerveau
    virtual ~Dog();
    
    // Opérateur d'affectation - copie profonde
    Dog& operator=(const Dog& other);

    // Remplace la méthode de la classe de base
    virtual void makeSound() const;
    
    // Définit une idée dans le cerveau
    void setIdea(int index, const std::string& idea);
    
    // Récupère une idée du cerveau
    std::string getIdea(int index) const;
};

#endif