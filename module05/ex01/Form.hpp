#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

// Déclaration anticipée pour éviter l'inclusion cyclique
class Bureaucrat;

class Form
{
private:
    const std::string   _name;          // Nom du formulaire, ne peut pas être modifié
    bool                _isSigned;      // État de signature du formulaire
    const int           _gradeToSign;   // Grade minimum requis pour signer (1-150)
    const int           _gradeToExecute;// Grade minimum requis pour exécuter (1-150)

public:
    // Constructeur par défaut - initialise avec valeurs par défaut
    Form();
    
    // Constructeur avec paramètres - crée un formulaire avec nom et grades spécifiés
    Form(const std::string &name, int gradeToSign, int gradeToExecute);
    
    // Constructeur de copie - duplique un Form existant
    Form(const Form &src);
    
    // Destructeur - libère les ressources
    ~Form();
    
    // Opérateur d'affectation - copie les attributs copiables (_isSigned uniquement)
    Form &operator=(const Form &rhs);
    
    // Getter pour obtenir le nom du formulaire
    const std::string &getName() const;
    
    // Getter pour vérifier si le formulaire est signé
    bool getIsSigned() const;
    
    // Getter pour obtenir le grade requis pour signer
    int getGradeToSign() const;
    
    // Getter pour obtenir le grade requis pour exécuter
    int getGradeToExecute() const;
    
    // Méthode pour faire signer le formulaire par un bureaucrate
    // Lance une exception si le grade du bureaucrate est insuffisant
    void beSigned(const Bureaucrat &bureaucrat);
    
    // Classe d'exception pour gérer les grades trop élevés (< 1)
    class GradeTooHighException : public std::exception
    {
    public:
        // Renvoie un message d'erreur descriptif
        virtual const char *what() const throw();
    };
    
    // Classe d'exception pour gérer les grades trop bas (> 150)
    class GradeTooLowException : public std::exception
    {
    public:
        // Renvoie un message d'erreur descriptif
        virtual const char *what() const throw();
    };
};

// Surcharge de l'opérateur d'insertion pour afficher les informations du formulaire
std::ostream &operator<<(std::ostream &out, const Form &form);

#endif