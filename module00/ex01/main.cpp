/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 01:40:02 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/13 13:50:31 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>  // Pour les entrées/sorties (cout, endl)
#include <string>   // Pour utiliser la classe string et ses méthodes
#include <cstdlib> // Pour les fonctions générales de la bibliothèque standard C

bool isValidInput(const std::string& str) 
{
    for (size_t i = 0; i < str.length(); i++) 
    {
        // Vérifie si le caractère est imprimable (entre 32 et 126 inclus en ASCII)
        if (str[i] < 32 || str[i] >126) 
            return false;
    }
    return true;
}


std::string getInput(const std::string& prompt)
// Fonction : getInput
// Rôle : Cette fonction affiche une invite à l'utilisateur et récupère une saisie clavier.
// Paramètres : prompt : Un message affiché à l'utilisateur pour lui indiquer quoi saisir.
// Retour : Une chaîne de caractères saisie par l'utilisateur.
{
    std::string input;
    // Déclaration d'une variable string vide pour stocker l'entrée utilisateur
    
    do
    {
        std::cout << prompt;
         // Affiche le message d'invite à l'utilisateur
        std::getline(std::cin, input);
        // Lit une ligne complète depuis l'entrée standard et la stocke dans input
        if (std::cin.eof())
        // Vérifie si l'utilisateur a envoyé un signal de fin de fichier (Ctrl+D/Ctrl+Z)
        {
            input.clear();
            return (input);
        }
        // Quitte le programme si un EOF est détecté
        if (!input.empty() && !isValidInput(input))
        {
            std::cout << "Error: Input contains non-printable characters." << std::endl;
            input.clear();
        }
    } 
    while (input.empty());
    // Continue la boucle tant que l'entrée est vide 
    return input;
    // Retourne l'entrée non-vide de l'utilisateur
}


int addNewContact(PhoneBook& book)
// Fonction : addNewContact
// Rôle : Cette fonction permet d'ajouter un nouveau contact dans le répertoire.
// Paramètres : book : Une référence au répertoire `PhoneBook` dans lequel le contact sera ajouté.
{
    Contact newContact;
    // Création d'un nouvel objet Contact temporaire

    newContact.setFirstName(getInput("Enter first name: "));
    if (newContact.getFirstName().empty())
        return (1);
    newContact.setLastName(getInput("Enter last name: "));
    if (newContact.getLastName().empty())
        return (1);
    newContact.setNickName(getInput("Enter nickname: "));
    if (newContact.getNickName().empty())
        return (1);
    newContact.setPhoneNumber(getInput("Enter phone number: "));
    if (newContact.getPhoneNumber().empty())
        return (1);
    newContact.setDarkestSecret(getInput("Enter darkest secret: "));
    if (newContact.getDarkestSecret().empty())
        return (1);
    book.addContact(newContact);
    // Ajoute le contact complété au répertoire téléphonique
    std::cout << "Contact added successfully!" << std::endl;
    // Affiche un message de confirmation de l'ajout
    return 0;
}


int main()
// Fonction : main
// Rôle : Point d'entrée du programme qui gère l'interface utilisateur principale.
{
    PhoneBook book;
    // Création d'un objet PhoneBook pour stocker les contacts
    std::string command;
    // Déclaration d'une variable pour stocker la commande utilisateur

    std::cout << "Welcome to Lizzie PhoneBook!" << std::endl;
    
    while (true)
    {
        std::cout << "\nEnter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        // Lit la commande entrée par l'utilisateur

        if (std::cin.eof())
        // Vérifie si l'utilisateur a envoyé un signal de fin de fichier (Ctrl+D)
            break;

        if (command == "ADD")
            addNewContact(book);
        else if (command == "SEARCH")
            book.searchContact();
        else if (command == "EXIT")
            break;
        else if (!command.empty())
        // Vérifie si la commande n'est pas vide
            std::cout << "Invalid command!" << std::endl;
            // Affiche message d'erreur si commande invalide
    }
    
    std::cout << "\nGoodbye!" << std::endl;
    return 0;
}