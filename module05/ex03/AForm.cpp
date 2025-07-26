#include "AForm.hpp"

// Constructeur par défaut - initialise avec des valeurs par défaut
AForm::AForm() 
    : _name("default"),        // Nom par défaut
      _isSigned(false),        // Non signé par défaut
      _gradeToSign(150),       // Grade le plus bas pour signer
      _gradeToExecute(150)     // Grade le plus bas pour exécuter
{
    std::cout << "AForm default constructor called" << std::endl;
}

// Constructeur avec paramètres - crée un formulaire avec nom et grades spécifiés
// Lance une exception si l'un des grades est invalide (< 1 ou > 150)
AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) 
    : _name(name),             // Initialise le nom
      _isSigned(false),        // Tout nouveau formulaire n'est pas signé
      _gradeToSign(gradeToSign),       // Grade requis pour signer
      _gradeToExecute(gradeToExecute)  // Grade requis pour exécuter
{
    std::cout << "AForm parametric constructor called" << std::endl;
    
    // Vérifie que les grades sont valides
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

// Constructeur de copie - duplique un AForm existant
AForm::AForm(const AForm &src) 
    : _name(src._name),                // Copie le nom
      _isSigned(src._isSigned),        // Copie l'état de signature
      _gradeToSign(src._gradeToSign),       // Copie le grade pour signer
      _gradeToExecute(src._gradeToExecute)  // Copie le grade pour exécuter
{
    std::cout << "AForm copy constructor called" << std::endl;
}

// Destructeur virtuel - nécessaire pour les classes abstraites
AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;
}

// Opérateur d'affectation - copie uniquement l'état de signature car les autres 
// attributs sont constants
AForm &AForm::operator=(const AForm &rhs)
{
    std::cout << "AForm assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->_isSigned = rhs._isSigned;
    }
    return *this;
}

// Getter pour obtenir le nom du formulaire
const std::string &AForm::getName() const
{
    return _name;
}

// Getter pour vérifier si le formulaire est signé
bool AForm::getIsSigned() const
{
    return _isSigned;
}

// Getter pour obtenir le grade requis pour signer
int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

// Getter pour obtenir le grade requis pour exécuter
int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

// Méthode pour faire signer le formulaire par un bureaucrate
// Lance une exception si le grade du bureaucrate est insuffisant
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    // Vérifie que le bureaucrate a un grade suffisant pour signer
    if (bureaucrat.getGrade() > _gradeToSign)
        throw AForm::GradeTooLowException();
    
    // Marque le formulaire comme signé
    _isSigned = true;
}

// Message d'erreur pour l'exception GradeTooHighException
const char *AForm::GradeTooHighException::what() const throw()
{
    return "AForm grade is too high (minimum is 1)";
}

// Message d'erreur pour l'exception GradeTooLowException
const char *AForm::GradeTooLowException::what() const throw()
{
    return "AForm grade is too low (maximum is 150)";
}

// Message d'erreur pour l'exception GradeTooLowForExecutionException
const char *AForm::GradeTooLowForExecutionException::what() const throw()
{
    return "Bureaucrat's grade is too low to execute this form";
}

// Message d'erreur pour l'exception NotSignedException
const char *AForm::NotSignedException::what() const throw()
{
    return "AForm is not signed";
}

// Surcharge de l'opérateur d'insertion pour afficher les informations du formulaire
// Format: Form: nom, signed: oui/non, grade to sign: X, grade to execute: Y
std::ostream &operator<<(std::ostream &out, const AForm &form)
{
    out << "Form: " << form.getName() 
        << ", signed: " << (form.getIsSigned() ? "yes" : "no") 
        << ", grade to sign: " << form.getGradeToSign() 
        << ", grade to execute: " << form.getGradeToExecute();
    return out;
}