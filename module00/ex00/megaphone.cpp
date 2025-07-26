/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:33:37 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/11 22:27:53 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // Pour les entrées/sorties (cout, endl)
#include <cctype> // Pour la fonction toupper()

int main(int ac, char **av)
{
    if (ac == 1) // Si aucun argument n'est passé
    {
        std::cout << "*** LARSEN EFFECT ***" << std::endl; 
        // std::cout gére l'affichage et std::endl équivaut au retour a la ligne
        return 0;
    }

    for (int i = 1; i < ac; i++)
    {
        std::string str(av[i]); 
        // Crée une chaîne de caractères à partir de l'argument courant (av[i])
        
        for (size_t j = 0; j < str.length(); j++) 
        // Boucle qu parourt chaque caractére de la chaine et j inférieur a sa longueur
            std::cout << (char)std::toupper(str[j]);
        // Convertit le caractére en majuscule
        if (i < ac - 1)
        // Vérifie si on n'est pas au dernier argument
            std::cout << " ";
        // Affiche un espace
    }
    std::cout << std::endl;
    return 0;
}

// NB : cout = "Character OUTput" 
//      endl = "End line"
//      str.length() renvoie un size_t