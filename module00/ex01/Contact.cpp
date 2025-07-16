/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 01:36:07 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/12 09:49:00 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}
// Constructeur Contact
// Initialise un objet `Contact` sans valeurs particulières.


void Contact::setFirstName(std::string name)
// Fonction : setFirstName
// Rôle : Définit le prénom (firstName) du contact.
// Paramètre : name : Une chaîne de caractères représentant le prénom.
{
    firstName = name;
}


void Contact::setLastName(std::string name)
// Fonction : setLastName
// Rôle : Définit le nom de famille (lastName) du contact.
// Paramètre : name : Une chaîne de caractères représentant le nom de famille.
{
    lastName = name;
}


void Contact::setNickName(std::string name)
// Fonction : setNickName
// Rôle : Définit le surnom (nickName) du contact.
// Paramètre : name : Une chaîne de caractères représentant le surnom.
{ 
    nickName = name;
}


void Contact::setPhoneNumber(std::string number)
// Fonction : setPhoneNumber
// Rôle : Définit le numéro de téléphone (phoneNumber) du contact.
// Paramètre : number : Une chaîne de caractères représentant le numéro de téléphone.
{
    
    for (size_t i = 0; i < number.length(); i++)
    // Vérifier si tous les caractères sont des chiffres
    {
        if (number[i] < '0' || number[i] > '9')
        {
            std::cout << "Error: Phone number must contain only digits." << std::endl;
            std::cout << "Please enter a valid phone number: ";
            std::getline(std::cin, number);
            i = -1;
            // Recommencer la vérification depuis le début
            continue;
        }
    }
    phoneNumber = number;
}



void Contact::setDarkestSecret(std::string secret)
// Fonction : setDarkestSecret
// Rôle : Définit le secret le plus sombre (darkestSecret) du contact.
// Paramètre : secret : Une chaîne de caractères représentant le secret.
{
    darkestSecret = secret;
}


std::string Contact::getFirstName() const
// Fonction : getFirstName
// Rôle : Récupère le prénom (firstName) du contact.
// Retour : Une chaîne de caractères contenant le prénom.
{
    return firstName;
}


std::string Contact::getLastName() const
// Fonction : getLastName
// Rôle : Récupère le nom de famille (lastName) du contact.
// Retour : Une chaîne de caractères contenant le nom de famille.
{
    return lastName;
}


std::string Contact::getNickName() const
// Fonction : getNickName
// Rôle : Récupère le surnom (nickName) du contact.
// Retour : Une chaîne de caractères contenant le surnom.
{
    return nickName;
}


std::string Contact::getPhoneNumber() const
// Fonction : getPhoneNumber
// Rôle : Récupère le numéro de téléphone (phoneNumber) du contact.
// Retour : Une chaîne de caractères contenant le numéro de téléphone.
{
    return phoneNumber;
}


std::string Contact::getDarkestSecret() const
// Fonction : getDarkestSecret
// Rôle : Récupère le secret le plus sombre (darkestSecret) du contact.
// Retour : Une chaîne de caractères contenant le secret.
{
    return darkestSecret;
}

// NB : const = "Constant" ceci ne doit pas être modifié