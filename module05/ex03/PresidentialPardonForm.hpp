#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    std::string _target;  // Cible du formulaire, représente la personne à gracier

public:
    // Constructeur par défaut - initialise avec une cible par défaut
    PresidentialPardonForm();
    
    // Constructeur avec paramètre - crée un formulaire avec une cible spécifiée
    PresidentialPardonForm(const std::string &target);
    
    // Constructeur de copie - duplique un PresidentialPardonForm existant
    PresidentialPardonForm(const PresidentialPardonForm &src);
    
    // Destructeur - libère les ressources
    ~PresidentialPardonForm();
    
    // Opérateur d'affectation - copie les attributs copiables
    PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
    
    // Getter pour obtenir la cible du formulaire
    const std::string &getTarget() const;
    
    // Implémentation de la méthode virtuelle pure de AForm
    // Annonce la grâce présidentielle de la cible
    virtual void execute(Bureaucrat const &executor) const;
    
    // Constantes de classe pour les grades requis (partagées par toutes les instances)
    static const int signGrade = 25;    // Grade requis pour signer (très élevé)
    static const int execGrade = 5;     // Grade requis pour exécuter (extrêmement élevé)
};

#endif