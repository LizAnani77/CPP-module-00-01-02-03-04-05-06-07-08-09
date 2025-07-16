/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lizzieananifoli <lizzieananifoli@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 01:31:56 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/11 23:05:22 by lizzieanani      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream> 

class Contact
// Une classe est par définition, la création d'un nouveau type d'objet ici Contact 
{
private:
// Private : Les éléments private d'une classe (variables ou fonctions) 
// ne peuvent être utilisés ou modifiés que par les fonctions définies dans cette même classe.

    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;

public:
// Public : Les éléments public d'une classe (variables ou fonctions) peuvent être utilisés
// ou modifiés par les fonctions définies dans la classe ET par n'importe quelle autre partie
// du programme utilisant cette classe.

    Contact();
    // Le constructeur permet l'initialisation des valeurs des variables qui composent ta classe ici Contact
    
    void setFirstName(std::string name);
    void setLastName(std::string name);
    void setNickName(std::string name);
    void setPhoneNumber(std::string number);
    void setDarkestSecret(std::string secret);
    // Fonctions permettant de saisir les informations du contact
    
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickName() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
    // Fonctions permettant de récupérer et lire les informations du contact
};

#endif

// NB : const = "Constant" ceci ne doit pas être modifié