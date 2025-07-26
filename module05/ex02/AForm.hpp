#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

// Déclaration anticipée pour éviter l'inclusion cyclique
class Bureaucrat;

class AForm
{
private:
    const std::string   _name;          // Nom du formulaire, ne peut pas être modifié
    bool                _isSigned;      // État de signature du formulaire
    const int           _gradeToSign;   // Grade minimum requis pour signer (1-150)
    const int           _gradeToExecute;// Grade minimum requis pour exécuter (1-150)

public:
    // Constructeur par défaut - initialise avec valeurs par défaut
    AForm();
    
    // Constructeur avec paramètres - crée un formulaire avec nom et grades spécifiés
    AForm(const std::string &name, int gradeToSign, int gradeToExecute);
    
    // Constructeur de copie - duplique un AForm existant
    AForm(const AForm &src);
    
    // Destructeur virtuel - nécessaire pour les classes abstraites
    virtual ~AForm();
    
    // Opérateur d'affectation - copie les attributs copiables (_isSigned uniquement)
    AForm &operator=(const AForm &rhs);
    
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
    
    // Méthode virtuelle pure pour exécuter le formulaire
    // Doit être implémentée par les classes dérivées
    virtual void execute(Bureaucrat const &executor) const = 0;
    
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
    
    // Classe d'exception pour gérer les cas où le grade du bureaucrate
    // est trop bas pour exécuter le formulaire
    class GradeTooLowForExecutionException : public std::exception
    {
    public:
        // Renvoie un message d'erreur descriptif
        virtual const char *what() const throw();
    };
    
    // Classe d'exception pour gérer les tentatives d'exécution de formulaires non signés
    class NotSignedException : public std::exception
    {
    public:
        // Renvoie un message d'erreur descriptif
        virtual const char *what() const throw();
    };
};

// Surcharge de l'opérateur d'insertion pour afficher les informations du formulaire
std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif