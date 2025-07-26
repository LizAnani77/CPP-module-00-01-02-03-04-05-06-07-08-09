/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 01:21:29 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/17 10:50:20 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    
    std::string str = "HI THIS IS BRAIN";
    // Crée une string qui sera accessible de différentes manières
        
    std::string* stringPTR = &str;
    // Crée un pointeur qui stocke l'adresse de str
    
    std::string& stringREF = str;
    // Crée une référence qui agit comme un alias pour str
    // Note : Une référence est un alias direct pour la variable, sans stockage
    //        d'adresse explicite, simplement un autre nom pour une variable existante
    //        "une etiquette"
    
    std::cout << "Adresses mémoire :" << std::endl;
    std::cout << "• str       : " << &str << std::endl;
    // Affiche l'adresse de la string originale
    std::cout << "• stringPTR : " << stringPTR << std::endl;
    // Affiche l'adresse stockée dans le pointeur (même que &str)
    std::cout << "• stringREF : " << &stringREF << std::endl;
    // Affiche l'adresse de la référence (même que &str)

    
    std::cout << std::endl;
    
    std::cout << "Valeurs :" << std::endl;
    std::cout << "• str       : " << str << std::endl;
    // Affiche la valeur directement
    std::cout << "• stringPTR : " << *stringPTR << std::endl;
    // Affiche la valeur via déréférencement du pointeur
    std::cout << "• stringREF : " << stringREF << std::endl;
    // Affiche la valeur via la référence
    
    return 0;
}