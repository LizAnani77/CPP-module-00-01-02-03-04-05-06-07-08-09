#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

// Déclaration anticipée pour éviter l'inclusion cyclique
class AForm;

class Bureaucrat
{
private:
    const std::string   _name;  // Nom du bureaucrate, ne peut pas être modifié après création
    int                 _grade; // Grade du bureaucrate (1 à 150, 1 étant le plus élevé)

public:
    // Constructeur par défaut - initialise avec nom "default" et grade 150
    Bureaucrat();
    
    // Constructeur avec paramètres - crée un bureaucrate avec nom et grade spécifiés
    Bureaucrat(const std::string &name, int grade);
    
    // Constructeur de copie - duplique un Bureaucrat existant
    Bureaucrat(const Bureaucrat &src);
    
    // Destructeur - libère les ressources
    ~Bureaucrat();
    
    // Opérateur d'affectation - copie les attributs copiables (grade uniquement)
    Bureaucrat &operator=(const Bureaucrat &rhs);

    // Getter pour obtenir le nom du bureaucrate
    const std::string &getName() const;
    
    // Getter pour obtenir le grade du bureaucrate
    int getGrade() const;

    // Incrémente le grade (diminue la valeur numérique)
    void incrementGrade();
    
    // Décrémente le grade (augmente la valeur numérique)
    void decrementGrade();
    
    // Méthode pour signer un formulaire
    // Affiche un message de succès ou d'échec selon le résultat
    void signForm(AForm &form);
    
    // Méthode pour exécuter un formulaire
    // Affiche un message de succès ou d'échec selon le résultat
    void executeForm(AForm const &form);

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

// Surcharge de l'opérateur d'insertion pour afficher les informations du bureaucrate
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif