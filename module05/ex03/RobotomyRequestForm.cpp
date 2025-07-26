#include "RobotomyRequestForm.hpp"

// Constructeur par défaut - initialise avec des valeurs par défaut
RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("RobotomyRequestForm", signGrade, execGrade),  // Initialise la classe de base avec des grades constants
      _target("default")                                    // Cible par défaut
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

// Constructeur avec paramètre - crée un formulaire avec une cible spécifiée
RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", signGrade, execGrade),  // Initialise la classe de base avec des grades constants
      _target(target)                                       // Initialise la cible avec la valeur fournie
{
    std::cout << "RobotomyRequestForm parametric constructor called" << std::endl;
}

// Constructeur de copie - duplique un RobotomyRequestForm existant
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
    : AForm(src),           // Appelle le constructeur de copie de la classe de base
      _target(src._target)  // Copie la cible
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

// Destructeur - libère les ressources
RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

// Opérateur d'affectation - copie les attributs copiables
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
    std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
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
const std::string &RobotomyRequestForm::getTarget() const
{
    return _target;
}

// Implémentation de la méthode virtuelle pure de AForm
// Effectue une tentative de robotomisation avec 50% de chance de succès
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    // Vérifie que le formulaire est signé
    if (!this->getIsSigned())
        throw AForm::NotSignedException();
    
    // Vérifie que l'exécuteur a un grade suffisant
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowForExecutionException();
    
    // Émet des bruits de forage pour simuler la robotomisation
    std::cout << "* DRILLING NOISES * Bzzzzzz... Drrrrrr... Whirrrrrrr... *" << std::endl;
    
    // Initialise le générateur de nombres aléatoires une seule fois
    static bool seeded = false;
    if (!seeded)
    {
        std::srand(std::time(NULL));
        seeded = true;
    }
    
    // Détermine le succès de la robotomisation avec 50% de chance
    if (std::rand() % 2)
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy of " << _target << " has failed!" << std::endl;
}