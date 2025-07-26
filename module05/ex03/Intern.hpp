#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
private:
    // Définition d'un type de pointeur sur une méthode de création de formulaire
    // FormCreator est un pointeur sur une méthode d'Intern qui prend une string et renvoie un AForm*
    typedef AForm* (Intern::*FormCreator)(const std::string &);
    
    // Structure qui associe un nom de formulaire à sa méthode de création
    struct FormInfo
    {
        std::string name;      // Nom du type de formulaire
        FormCreator creator;   // Méthode pour créer ce type de formulaire
    };

    // Méthodes privées pour créer chaque type de formulaire
    AForm* createShrubberyForm(const std::string &target);    // Crée un ShrubberyCreationForm
    AForm* createRobotomyForm(const std::string &target);     // Crée un RobotomyRequestForm
    AForm* createPresidentialForm(const std::string &target); // Crée un PresidentialPardonForm

    // Constante indiquant le nombre de types de formulaires supportés
    static const int formCount = 3;
    
    // Tableau associant les noms de formulaires à leurs méthodes de création
    FormInfo _formTypes[formCount];

public:
    // Constructeur par défaut - initialise le tableau de types de formulaires
    Intern();
    
    // Constructeur de copie - duplique un Intern existant
    Intern(const Intern &src);
    
    // Destructeur
    ~Intern();
    
    // Opérateur d'affectation - copie les attributs nécessaires
    Intern &operator=(const Intern &rhs);
    
    // Crée un formulaire du type spécifié avec la cible donnée
    // Lance une exception si le type de formulaire n'est pas reconnu
    AForm* makeForm(const std::string &formName, const std::string &target);
    
    // Classe d'exception pour gérer les types de formulaires non trouvés
    class FormNotFoundException : public std::exception
    {
    public:
        // Renvoie un message d'erreur descriptif
        virtual const char *what() const throw();
    };
};

#endif