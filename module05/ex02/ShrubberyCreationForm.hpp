#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
    std::string _target;  // Cible du formulaire, représente le nom du fichier à créer

public:
    // Constructeur par défaut - initialise avec une cible par défaut
    ShrubberyCreationForm();
    
    // Constructeur avec paramètre - crée un formulaire avec une cible spécifiée
    ShrubberyCreationForm(const std::string &target);
    
    // Constructeur de copie - duplique un ShrubberyCreationForm existant
    ShrubberyCreationForm(const ShrubberyCreationForm &src);
    
    // Destructeur - libère les ressources
    ~ShrubberyCreationForm();
    
    // Opérateur d'affectation - copie les attributs copiables
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
    
    // Getter pour obtenir la cible du formulaire
    const std::string &getTarget() const;
    
    // Implémentation de la méthode virtuelle pure de AForm
    // Crée un fichier avec un dessin ASCII d'arbustes
    virtual void execute(Bureaucrat const &executor) const;
    
    // Classe d'exception pour gérer les erreurs d'ouverture de fichier
    class FileOpenException : public std::exception
    {
    public:
        // Renvoie un message d'erreur descriptif
        virtual const char *what() const throw();
    };
    
    // Constantes de classe pour les grades requis (partagées par toutes les instances)
    static const int signGrade = 145;    // Grade requis pour signer (relativement bas)
    static const int execGrade = 137;    // Grade requis pour exécuter (plus élevé que pour signer)
};

#endif