/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:19:15 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/25 19:13:55 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal 
{
private:
    Brain* brain;  // Pointeur vers un objet Brain, alloué dynamiquement

public:
    // Constructeur par défaut - crée un cerveau
    Cat();
    
    // Constructeur de copie - effectue une copie profonde
    Cat(const Cat& other);
    
    // Destructeur virtuel - libère le cerveau
    virtual ~Cat();
    
    // Opérateur d'affectation - copie profonde
    Cat& operator=(const Cat& other);

    // Implémente la méthode virtuelle pure de Animal
    virtual void makeSound() const;
    
    // Définit une idée dans le cerveau
    void setIdea(int index, const std::string& idea);
    
    // Récupère une idée du cerveau
    std::string getIdea(int index) const;
};

#endif