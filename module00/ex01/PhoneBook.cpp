/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 01:37:36 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/11 22:39:51 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream> // Pour utiliser les entrées/sorties (cin, cout, endl)
#include <iomanip> // Pour formater l'affichage (setw pour définir la largeur)
#include <limits> // Pour utiliser numeric_limits (utile pour nettoyer le buffer d'entrée)



PhoneBook::PhoneBook() : currentIndex(0), totalContacts(0) {}
// Constructeur : PhoneBook
// Initialise un nouveau carnet d'adresses avec deux valeurs
// currentIndex : Position actuelle dans le tableau où un nouveau contact sera ajouté.
// totalContacts : Nombre total de contacts actuellement dans le carnet.


// Fonction : addContact
// Rôle : Ajoute un contact au carnet d'adresses.
// Arguments : contact : Une instance de la classe Contact représentant le contact à ajouter.
void PhoneBook::addContact(const Contact& contact) 
{
    contacts[currentIndex] = contact;
    // Sauvegarde le nouveau contact à la position actuelle dans le tableau 'contacts'
    
    currentIndex = (currentIndex + 1) % 8;
    // Avance à la position suivante (retourne à 0 après avoir atteint 7)
    if (totalContacts < 8)
    // Si on n'a pas encore 8 contacts, augmente le compteur total de contacts
        totalContacts++;
}

// Fonction statique : formatString
// Rôle : Formate une chaîne pour qu'elle tienne dans 10 caractères.
// Arguments : str : La chaîne à formater.
static std::string formatString(const std::string& str) 
{
    if (str.length() > 10)
    // Si la chaîne fait plus de 10 caractères
        return str.substr(0, 9) + ".";
        // Garde les 9 premiers caractères et ajoute un point à la fin
    return str;
}

// Fonction : displayContactList
// Rôle : Affiche la liste des contacts du carnet dans un format tabulaire.
void PhoneBook::displayContactList() const
// Affiche l'en-tête du tableau avec chaque colonne sur 10 caractères, séparées par |
{
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < totalContacts; i++) 
    // Pour chaque contact existant dans le carnet
    // Affiche sur une ligne : numéro, prénom, nom et surnom du contact, formatés sur 10 caractères
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << formatString(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << formatString(contacts[i].getLastName()) << "|"
                  << std::setw(10) << formatString(contacts[i].getNickName()) << std::endl;
    }
}

// Fonction : searchContact
// Rôle : Recherche un contact spécifique dans le carnet.
void PhoneBook::searchContact() const
{
    if (totalContacts == 0)
    // Si le carnet est vide, affiche un message et arrête la fonction 
    {
        std::cout << "No contacts in phonebook." << std::endl;
        return;
    }
    
    displayContactList();
    // Affiche la liste de tous les contacts
    
    int index;
    // Prépare une variable pour stocker le numéro du contact à afficher
    std::cout << "Enter index: ";
    
    if (!(std::cin >> index) || index < 0 || index >= totalContacts)
    // Vérifie si l'index entré est valide (un nombre et dans les limites du carnet)
    {
        std::cout << "Invalid index!" << std::endl;
        std::cin.clear();
        // Réinitialise cin en cas d'erreur
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // Vide le buffer d'entrée
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // Vide le buffer d'entrée
    
    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickName() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
    // Affiche toutes les informations du contact demandé
}

// NB : cout = "Character OUTput" 
//      endl = "End line"
//      const = "Constant" ceci ne doit pas être modifié
//      cin = "Console Input" 
//      setw =  "Set Width" 