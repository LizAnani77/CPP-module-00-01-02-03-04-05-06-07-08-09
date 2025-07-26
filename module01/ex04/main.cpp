/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 02:23:11 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/17 14:12:22 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 4)
	{
        std::cerr << "Usage: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
        return 1;
    }

    FileReplacer replacer(argv[1], argv[2], argv[3]);
    // Crée un objet FileReplacer et exécute le remplacement
    return replacer.replace() ? 0 : 1;
    // Retourne 0 si le remplacement réussit, 1 sinon
}



// Créer un fichier de test simple
// echo 'Hello World! Hello Universe!' > test.txt

// Créer un fichier avec plusieurs lignes
// echo -e 'Hello World!\nHello Universe!\nHello World again!' > test.txt

// Créer un fichier vide
// touch empty.txt

// Créer un fichier avec des caractères spéciaux
// echo 'Hello***World%%%Hello###World' > test.txt



// Test de base - remplacer "Hello" par "Bonjour"
// ./replace test.txt "Hello" "Bonjour"

// Test avec des espaces
// ./replace test.txt " " "_"

// Test avec des caractères spéciaux
// ./replace test.txt "***" "..."



// Comparer les fichiers originaux et modifiés
// diff test.txt test.txt.replace


// rm test.txt test.txt.replace