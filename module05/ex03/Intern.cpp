#include "Intern.hpp"

// Méthode privée pour créer un ShrubberyCreationForm
// Prend une cible en paramètre et retourne un pointeur vers le formulaire créé
AForm* Intern::createShrubberyForm(const std::string &target)
{
    // Alloue dynamiquement un nouveau ShrubberyCreationForm avec la cible spécifiée
    return new ShrubberyCreationForm(target);
}

// Méthode privée pour créer un RobotomyRequestForm
// Prend une cible en paramètre et retourne un pointeur vers le formulaire créé
AForm* Intern::createRobotomyForm(const std::string &target)
{
    // Alloue dynamiquement un nouveau RobotomyRequestForm avec la cible spécifiée
    return new RobotomyRequestForm(target);
}

// Méthode privée pour créer un PresidentialPardonForm
// Prend une cible en paramètre et retourne un pointeur vers le formulaire créé
AForm* Intern::createPresidentialForm(const std::string &target)
{
    // Alloue dynamiquement un nouveau PresidentialPardonForm avec la cible spécifiée
    return new PresidentialPardonForm(target);
}

// Constructeur par défaut - initialise le tableau de types de formulaires
Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
    
    // Initialise le premier type de formulaire (ShrubberyCreationForm)
    _formTypes[0].name = "shrubbery creation";
    _formTypes[0].creator = &Intern::createShrubberyForm;
    
    // Initialise le deuxième type de formulaire (RobotomyRequestForm)
    _formTypes[1].name = "robotomy request";
    _formTypes[1].creator = &Intern::createRobotomyForm;
    
    // Initialise le troisième type de formulaire (PresidentialPardonForm)
    _formTypes[2].name = "presidential pardon";
    _formTypes[2].creator = &Intern::createPresidentialForm;
}

// Constructeur de copie - duplique un Intern existant
// Bien que les attributs soient copiés via l'opérateur d'affectation,
// il n'y a pas vraiment d'état interne à copier spécifiquement
Intern::Intern(const Intern &src)
{
    std::cout << "Intern copy constructor called" << std::endl;
    *this = src;
}

// Destructeur
Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

// Opérateur d'affectation
// Comme les Interns n'ont pas vraiment d'état propre unique,
// il n'y a rien à copier, mais l'opérateur est défini pour être complet
Intern &Intern::operator=(const Intern &rhs)
{
    std::cout << "Intern assignment operator called" << std::endl;
    // (void)rhs pour éviter l'avertissement de variable non utilisée
    (void)rhs;
    return *this;
}

// Crée un formulaire du type spécifié avec la cible donnée
// Lance une exception si le type de formulaire n'est pas reconnu
AForm* Intern::makeForm(const std::string &formName, const std::string &target)
{
    // Parcourt le tableau des types de formulaires pour trouver celui demandé
    for (int i = 0; i < formCount; i++)
    {
        // Si le nom du formulaire correspond à l'un des types connus
        if (_formTypes[i].name == formName)
        {
            // Appelle la méthode de création correspondante
            AForm* form = (this->*_formTypes[i].creator)(target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }
    
    // Si le type de formulaire n'a pas été trouvé
    std::cout << "Intern cannot create form: " << formName << " (unknown form type)" << std::endl;
    // Lance une exception indiquant que le type n'existe pas
    throw FormNotFoundException();
}

// Message d'erreur pour l'exception FormNotFoundException
const char *Intern::FormNotFoundException::what() const throw()
{
    return "Form type not found";
}