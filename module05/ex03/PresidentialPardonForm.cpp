#include "PresidentialPardonForm.hpp"

// Constructeur par défaut - initialise avec des valeurs par défaut
PresidentialPardonForm::PresidentialPardonForm() 
    : AForm("PresidentialPardonForm", signGrade, execGrade),  // Initialise la classe de base avec des grades constants
      _target("default")                                       // Cible par défaut
{
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

// Constructeur avec paramètre - crée un formulaire avec une cible spécifiée
PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", signGrade, execGrade),  // Initialise la classe de base avec des grades constants
      _target(target)                                          // Initialise la cible avec la valeur fournie
{
    std::cout << "PresidentialPardonForm parametric constructor called" << std::endl;
}

// Constructeur de copie - duplique un PresidentialPardonForm existant
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
    : AForm(src),           // Appelle le constructeur de copie de la classe de base
      _target(src._target)  // Copie la cible
{
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

// Destructeur - libère les ressources
PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

// Opérateur d'affectation - copie les attributs copiables
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
    std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
    if (this != &rhs)
    {
        // Appelle l'opérateur d'affectation de la classe de base
        AForm::operator=(rhs);
        // Copie la cible
        this->_target = rhs._target;
    }
    return *this;
}

// Getter pour obtenir la cible du formulaire
const std::string &PresidentialPardonForm::getTarget() const
{
    return _target;
}

// Implémentation de la méthode virtuelle pure de AForm
// Annonce la grâce présidentielle de la cible
void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    // Vérifie que le formulaire est signé
    if (!this->getIsSigned())
        throw AForm::NotSignedException();
    
    // Vérifie que l'exécuteur a un grade suffisant
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowForExecutionException();
    
    // Annonce la grâce présidentielle
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}