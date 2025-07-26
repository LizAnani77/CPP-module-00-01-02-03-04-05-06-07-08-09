/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 02:21:21 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/17 13:16:59 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"
#include <iostream>

FileReplacer::FileReplacer(const std::string& filename, const std::string& s1, const std::string& s2)
    : filename(filename), s1(s1), s2(s2) {}
// Constructeur
// Initialise les membres de la classe avec les valeurs fournies
// Paramètres :
//   - filename : Nom du fichier à traiter
//   - s1 : Chaîne de caractères à rechercher
//   - s2 : Chaîne de caractères qui remplacera s1

bool FileReplacer::validateInputs() const
// Fonction : validateInputs
// Vérifie que les paramètres essentiels ne sont pas vides
{
    if (filename.empty() || s1.empty())
	{
        std::cerr << "Error: Empty filename or search string." << std::endl;
        return false;
    }
    return true;
}

std::string FileReplacer::performReplace(const std::string& line) const
// Fonction : performReplace
// Effectue le remplacement de toutes les occurrences de s1 par s2 dans une ligne
{
    std::string result;
    // Crée une chaîne vide pour stocker le résultat
    size_t last_pos = 0;
   // Position après la dernière occurrence traitée, début de la prochaine recherche
    size_t find_pos = 0;
    // Position de la prochaine occurrence de s1
    
    while ((find_pos = line.find(s1, last_pos)) != std::string::npos)
    // Boucle de recherche et remplacement :
    // 1. line.find(s1, last_pos) cherche la prochaine occurrence de s1 à partir de last_pos
    // 2. find_pos stocke la position trouvée (ou npos si aucune occurrence)
    // 3. La boucle continue tant que find_pos != npos (tant qu'une occurrence est trouvée)
	{
        result.append(line, last_pos, find_pos - last_pos);
        // Ajoute le texte entre la dernière position et l'occurrence trouvée
        result.append(s2);
        // Ajoute la chaîne de remplacement
        last_pos = find_pos + s1.length();
        // Met à jour la position pour la prochaine recherche
    }
    result.append(line, last_pos, line.length() - last_pos);
    // Ajoute à result la portion finale de line :
    // - Commence à last_pos (après la dernière occurrence traitée)
    // - Longueur = line.length() - last_pos (distance jusqu'à la fin)
    // - Nécessaire pour ne pas perdre les caractères après la dernière occurrence de s1
    // - Si aucun remplacement n'a été fait, copie la ligne entière
    return result;
}

bool FileReplacer::replace()
// Fonction : replace
// Gère le processus complet de remplacement dans le fichier
// Retourne true si le remplacement a réussi, false en cas d'erreur
{
    if (!validateInputs())
    // Vérifie la validité des paramètres d'entrée (filename, s1, s2)
    // Retourne false si les paramètres ne sont pas valides
        return false;

    std::ifstream inFile(filename.c_str());
    // Ouvre le fichier source en lecture
    // c_str() convertit string en const char* requis par ifstream
    if (!inFile.is_open())
    {
        std::cerr << "Error: Cannot open input file." << std::endl;
        return false;
    }

    std::string outFilename = filename + ".replace";
    // Crée le nom du fichier de sortie en ajoutant l'extension .replace
    std::ofstream outFile(outFilename.c_str());
    // Ouvre le fichier de sortie en écriture
    if (!outFile.is_open())
    {
        std::cerr << "Error: Cannot create output file." << std::endl;
        inFile.close(); 
        // Ferme le fichier d'entrée avant de quitter
        return false;
    }

    std::string line;
    // Variable pour stocker chaque ligne lue du fichier
    while (std::getline(inFile, line))
    // Lit le fichier ligne par ligne jusqu'à la fin
    {
        outFile << performReplace(line);
        //  performReplace(line) cherche toutes les occurrences de s1 dans la ligne
        //  Remplace chaque occurrence trouvée par s2
        //  Le résultat est écrit dans le fichier de sortie avec l'opérateur
        if (!inFile.eof())
        // Gestion des sauts de ligne :
        // - Si nous NE sommes PAS à la fin du fichier (EOF = End Of File)
        //   alors on ajoute un saut de ligne après la ligne traitée
        // - Si nous sommes à la dernière ligne, on n'ajoute pas de saut de ligne
        //   pour éviter d'avoir une ligne vide à la fin du fichier
            outFile << std::endl;
    }

    inFile.close();
    outFile.close();
    // Ferme proprement les fichiers pour libérer les ressources
    return true; 
    // Le remplacement s'est bien déroulé
}



// empty() pour vide
// find() pour la recherche
// append() pour la concaténation
// length() pour la longueur
// c_str() pour la conversion en C-string

// std::string::npos (valeur spéciale indiquant "non trouvé")