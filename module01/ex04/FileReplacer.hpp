/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 02:20:34 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/16 21:06:17 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEREPLACER_HPP
# define FILEREPLACER_HPP

#include <string>
#include <fstream>

class FileReplacer
// Classe : FileReplacer
// Rôle : Gère le remplacement de toutes les occurrences d'une chaîne par une autre dans un fichier
{
private:
    std::string filename;
    // Nom du fichier à traiter
    std::string s1;
    // Chaîne à rechercher
    std::string s2;
     // Chaîne de remplacement
    
    bool validateInputs() const;
    // Fonction : validateInputs
    // Rôle : Vérifie la validité des paramètres d'entrée
    // Retour : true si les entrées sont valides, false sinon
    // Note : const indique que la méthode ne modifie pas l'objet
    std::string performReplace(const std::string& line) const;

public:
    FileReplacer(const std::string& filename, const std::string& s1, const std::string& s2);
    // Constructeur : Initialise le replacer avec les paramètres nécessaires
    // Paramètres :
    //   filename : Nom du fichier à traiter
    //   s1 : Chaîne à rechercher
    //   s2 : Chaîne de remplacement
    bool replace();
    // Fonction : replace
    // Rôle : Exécute l'opération de remplacement sur l'ensemble du fichier
    // Retour : true si l'opération réussit, false en cas d'erreur
};

#endif