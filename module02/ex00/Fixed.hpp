/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:17:59 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/21 11:30:13 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
// Cette classe implémente un nombre à virgule fixe en utilisant 
// un entier pour stocker la valeur et 8 bits pour la partie fractionnaire
{
private:
    int _value;
    // Stocke la valeur du nombre à virgule fixe sous forme d'un entier
    // La vraie valeur est _value / (1 << _fractionalBits)
    
    static const int _fractionalBits = 8;
    // Nombre de bits utilisés pour représenter la partie fractionnaire
    // Cette valeur fixe détermine la précision de nos nombres
    // equivaut a diviser la valeur par 256 ex : 1 << 8 = 2⁸ = 256

public:
    Fixed(); 
    // Constructeur par défaut
    // Initialise la valeur à 0
    
    Fixed(const Fixed& copy);
    // Constructeur de copie
    // Crée une nouvelle instance qui est une copie exacte de copy
    
    Fixed& operator=(const Fixed& copy);
    // Opérateur d'affectation
    // Copie les valeurs de copy vers l'instance courante
    // Vérifie l'auto-affectation
    // Retourne une référence vers l'objet courant
   
    ~Fixed();
    // Destructeur
    // Nécessaire pour respecter la forme canonique

    int getRawBits(void) const;
    // Retourne la valeur initiale stockée (_value)
    // Ne convertit pas la valeur, retourne l'entier tel quel
    
    void setRawBits(int const raw);
    // Définit directement la valeur initiale (_value)
    // Permet de modifier la représentation interne du nombre
};

#endif