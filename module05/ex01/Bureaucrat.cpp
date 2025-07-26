#include "Bureaucrat.hpp"
#include "Form.hpp"

// Constructeur par défaut - initialise avec nom "default" et grade 150 (le plus bas)
Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

// Constructeur avec paramètres - crée un bureaucrate avec nom et grade spécifiés
// Lance une exception si le grade est invalide (< 1 ou > 150)
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
    std::cout << "Bureaucrat constructor called" << std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade = grade;
}

// Constructeur de copie - duplique un Bureaucrat existant
// Le nom est copié directement car il est constant
Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

// Destructeur - libère les ressources et affiche un message
Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

// Opérateur d'affectation - copie uniquement le grade car le nom est constant
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
    std::cout << "Bureaucrat assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->_grade = rhs._grade;
    }
    return *this;
}

// Getter pour obtenir le nom du bureaucrate
const std::string &Bureaucrat::getName() const
{
    return _name;
}

// Getter pour obtenir le grade du bureaucrate
int Bureaucrat::getGrade() const
{
    return _grade;
}

// Incrémente le grade (diminue la valeur numérique)
// Lance une exception si le grade deviendrait trop élevé (< 1)
void Bureaucrat::incrementGrade()
{
    if (_grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}

// Décrémente le grade (augmente la valeur numérique)
// Lance une exception si le grade deviendrait trop bas (> 150)
void Bureaucrat::decrementGrade()
{
    if (_grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}

// Méthode pour signer un formulaire
// Essaie de signer le formulaire et affiche un message approprié
void Bureaucrat::signForm(Form &form)
{
    try
    {
        // Tente de faire signer le formulaire par ce bureaucrate
        form.beSigned(*this);
        // Si la signature réussit, affiche un message de succès
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        // Si la signature échoue (exception), affiche un message d'échec
        std::cout << _name << " couldn't sign " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}

// Message d'erreur pour l'exception GradeTooHighException
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high (minimum is 1)";
}

// Message d'erreur pour l'exception GradeTooLowException
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low (maximum is 150)";
}

// Surcharge de l'opérateur d'insertion pour afficher les informations du bureaucrate
// Format: nom, bureaucrat grade X
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}