/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 01:43:43 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/21 14:02:55 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
// Cette classe permet de manipuler des nombres avec une partie décimale
// Elle utilise une représentation en virgule fixe au lieu des nombres flottants
// Cela permet d'avoir des calculs exacts et une meilleure performance
{
private:
    int _value;
    // La valeur stockée en interne
    // Exemple : 42.42 est stocké comme 42.42 * 256 = 10859

    static const int _fractionalBits = 8;
    // Nombre de bits utilisés pour la partie décimale
    // 8 bits signifie une précision de 1/256
    // Exemple : 1 est représenté comme 1 * 256 = 256 en interne

public:
    // -------- CONSTRUCTEURS ET DESTRUCTEUR --------
    Fixed();
    // Crée un nombre initialisé à 0

    Fixed(const int n);
    // Crée un nombre à partir d'un entier
    // Exemple : Fixed(5) crée le nombre 5.0

    Fixed(const float n);
    // Crée un nombre à partir d'un décimal
    // Exemple : Fixed(5.5f) crée le nombre 5.5

    Fixed(const Fixed& rhs);
    // Crée une copie d'un autre nombre Fixed
    
    ~Fixed();
    // Nettoie la mémoire (rien à faire ici)

    // -------- OPÉRATEUR D'AFFECTATION --------
    Fixed& operator=(const Fixed& rhs);
    // Copie la valeur d'un autre nombre dans celui-ci

    // -------- OPÉRATEURS DE COMPARAISON --------
    bool operator>(const Fixed& rhs) const;   // Plus grand que
    bool operator<(const Fixed& rhs) const;   // Plus petit que
    bool operator>=(const Fixed& rhs) const;  // Plus grand ou égal
    bool operator<=(const Fixed& rhs) const;  // Plus petit ou égal
    bool operator==(const Fixed& rhs) const;  // Égal
    bool operator!=(const Fixed& rhs) const;  // Différent

    // -------- OPÉRATEURS MATHÉMATIQUES --------
    Fixed operator+(const Fixed& rhs) const;  // Addition
    Fixed operator-(const Fixed& rhs) const;  // Soustraction
    Fixed operator*(const Fixed& rhs) const;  // Multiplication
    Fixed operator/(const Fixed& rhs) const;  // Division

    // -------- OPÉRATEURS D'INCRÉMENTATION/DÉCRÉMENTATION --------
    Fixed& operator++();      // ++nombre
    Fixed operator++(int);    // nombre++
    Fixed& operator--();      // --nombre
    Fixed operator--(int);    // nombre--

    // -------- FONCTIONS DE CONVERSION --------
    int getRawBits(void) const;
    // Renvoie la valeur stockée en interne
    
    void setRawBits(int const valeur);
    // Modifie directement la valeur stockée
    
    float toFloat(void) const;
    // Convertit en nombre décimal
    // Exemple : 10859 devient 42.42
    
    int toInt(void) const;
    // Convertit en nombre entier (arrondi vers le bas)
    // Exemple : 42.42 devient 42

    // -------- FONCTIONS MIN/MAX --------
    static Fixed& min(Fixed& a, Fixed& b);
    // Renvoie le plus petit des deux nombres
    
    static const Fixed& min(const Fixed& a, const Fixed& b);
    // Version pour les nombres constants
    
    static Fixed& max(Fixed& a, Fixed& b);
    // Renvoie le plus grand des deux nombres
    
    static const Fixed& max(const Fixed& a, const Fixed& b);
    // Version pour les nombres constants
};

// -------- AFFICHAGE --------
std::ostream& operator<<(std::ostream& sortie, const Fixed& nombre);
// Permet d'afficher un nombre Fixed avec cout
// Exemple : cout << nombre affiche "42.42"

#endif