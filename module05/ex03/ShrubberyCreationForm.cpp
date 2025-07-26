#include "ShrubberyCreationForm.hpp"

// Constructeur par défaut - initialise avec des valeurs par défaut
ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("ShrubberyCreationForm", signGrade, execGrade),  // Initialise la classe de base avec des grades constants
      _target("default")                                     // Cible par défaut
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

// Constructeur avec paramètre - crée un formulaire avec une cible spécifiée
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", signGrade, execGrade),  // Initialise la classe de base avec des grades constants
      _target(target)                                        // Initialise la cible avec la valeur fournie
{
    std::cout << "ShrubberyCreationForm parametric constructor called" << std::endl;
}

// Constructeur de copie - duplique un ShrubberyCreationForm existant
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
    : AForm(src),           // Appelle le constructeur de copie de la classe de base
      _target(src._target)  // Copie la cible
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

// Destructeur - libère les ressources
ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

// Opérateur d'affectation - copie les attributs copiables
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
    std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
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
const std::string &ShrubberyCreationForm::getTarget() const
{
    return _target;
}

// Implémentation de la méthode virtuelle pure de AForm
// Crée un fichier avec un dessin ASCII d'arbustes
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    // Vérifie que le formulaire est signé
    if (!this->getIsSigned())
        throw AForm::NotSignedException();
    
    // Vérifie que l'exécuteur a un grade suffisant
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowForExecutionException();
    
    // Crée le nom du fichier en ajoutant "_shrubbery" à la cible
    std::string filename = _target + "_shrubbery";
    // Ouvre le fichier en écriture
    std::ofstream outfile(filename.c_str());
    
    // Vérifie que le fichier a été ouvert correctement
    if (!outfile.is_open())
        throw FileOpenException();
    
    // Écrit un dessin ASCII d'arbustes dans le fichier
    outfile << "       _-_" << std::endl;
    outfile << "    /~~   ~~\\" << std::endl;
    outfile << " /~~         ~~\\" << std::endl;
    outfile << "{               }" << std::endl;
    outfile << " \\  _-     -_  /" << std::endl;
    outfile << "   ~  \\\\ //  ~" << std::endl;
    outfile << "_- -   | | _- _" << std::endl;
    outfile << "  _ -  | |   -_" << std::endl;
    outfile << "      // \\\\" << std::endl;
    outfile << std::endl;
    outfile << "       _-_" << std::endl;
    outfile << "    /~~   ~~\\" << std::endl;
    outfile << " /~~         ~~\\" << std::endl;
    outfile << "{               }" << std::endl;
    outfile << " \\  _-     -_  /" << std::endl;
    outfile << "   ~  \\\\ //  ~" << std::endl;
    outfile << "_- -   | | _- _" << std::endl;
    outfile << "  _ -  | |   -_" << std::endl;
    outfile << "      // \\\\" << std::endl;
    
    // Ferme le fichier
    outfile.close();
}

// Message d'erreur pour l'exception FileOpenException
const char *ShrubberyCreationForm::FileOpenException::what() const throw()
{
    return "Failed to open output file";
}