#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>  // Pour std::rand
# include <ctime>    // Pour std::time

class RobotomyRequestForm : public AForm
{
private:
    std::string _target;  // Cible du formulaire, représente le sujet de la robotomisation

public:
    // Constructeur par défaut - initialise avec une cible par défaut
    RobotomyRequestForm();
    
    // Constructeur avec paramètre - crée un formulaire avec une cible spécifiée
    RobotomyRequestForm(const std::string &target);
    
    // Constructeur de copie - duplique un RobotomyRequestForm existant
    RobotomyRequestForm(const RobotomyRequestForm &src);
    
    // Destructeur - libère les ressources
    ~RobotomyRequestForm();
    
    // Opérateur d'affectation - copie les attributs copiables
    RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
    
    // Getter pour obtenir la cible du formulaire
    const std::string &getTarget() const;
    
    // Implémentation de la méthode virtuelle pure de AForm
    // Effectue une tentative de robotomisation avec 50% de chance de succès
    virtual void execute(Bureaucrat const &executor) const;
    
    // Constantes de classe pour les grades requis (partagées par toutes les instances)
    static const int signGrade = 72;    // Grade requis pour signer (grade moyen)
    static const int execGrade = 45;    // Grade requis pour exécuter (plus élevé que pour signer)
};

#endif