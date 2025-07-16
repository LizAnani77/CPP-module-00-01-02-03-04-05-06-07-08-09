/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 01:35:11 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/11 21:01:28 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
// Une classe est par définition, la création d'un nouveau type d'objet ici PhoneBook
{
private:
// Private : Les éléments private d'une classe (variables ou fonctions) 
// ne peuvent être utilisés ou modifiés que par les fonctions définies dans cette même classe.

    Contact contacts[8];
    // Tableau qui stocke les informations des contacts
    int     currentIndex;
    // Indique l'index actuel
    int     totalContacts;
    // Totalitée des contacts

public:
// Public : Les éléments public d'une classe (variables ou fonctions) peuvent être utilisés
// ou modifiés par les fonctions définies dans la classe ET par n'importe quelle autre partie
// du programme utilisant cette classe.

    PhoneBook();
    // Le constructeur permet l'initialisation des valeurs des variables qui composent ta classe ici PhoneBook
    
    void    addContact(const Contact& contact);
    // Ajoute un contact au carnet.
    void    searchContact() const;
    // Recherche un contact 
    void    displayContactList() const;
    // Affiche une liste succinte des contacts
};

#endif

// const = "Constant" ceci ne doit pas être modifié