#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

// Affiche un séparateur visuel pour améliorer la lisibilité de la sortie
void printSeparator(const std::string &title)
{
    std::cout << "\n";
    std::cout << "===============================================" << std::endl;
    std::cout << title << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "\n";
}

// Teste un type de formulaire spécifique avec un stagiaire
void testSpecificForm(Intern &intern, Bureaucrat &boss, 
                      const std::string &formType, const std::string &target)
{
    std::cout << "\n----- Testing " << formType << " form -----" << std::endl;
    
    try 
    {
        // Création du formulaire par le stagiaire
        std::cout << "\n1. Creating the form:" << std::endl;
        AForm* form = intern.makeForm(formType, target);
        
        // Affichage des informations du formulaire
        std::cout << "\n2. Form details:" << std::endl;
        std::cout << *form << std::endl;
        
        // Signature du formulaire
        std::cout << "\n3. Signing the form:" << std::endl;
        boss.signForm(*form);
        
        // Exécution du formulaire
        std::cout << "\n4. Executing the form:" << std::endl;
        boss.executeForm(*form);
        
        // Libération de la mémoire
        std::cout << "\n5. Cleaning up resources:" << std::endl;
        delete form;
    } 
    catch (std::exception &e) 
    {
        std::cout << "ERROR: " << e.what() << std::endl;
    }
}

// Teste spécifiquement l'exception GradeTooLowForExecutionException
void testGradeTooLowForExecution()
{
    printSeparator("TESTING NEW EXCEPTION: GradeTooLowForExecutionException");
    
    try 
    {
        // Création des objets de test
        std::cout << "Creating test objects..." << std::endl;
        
        // Formulaires avec différentes exigences de grade
        ShrubberyCreationForm shrubForm("Garden");      // Exécution: grade 137
        RobotomyRequestForm robotForm("Android");       // Exécution: grade 45
        PresidentialPardonForm pardonForm("Criminal");  // Exécution: grade 5
        
        // Bureaucrates avec différents grades
        Bureaucrat chief("Chief", 1);        // Peut tout faire
        Bureaucrat manager("Manager", 50);   // Peut signer mais pas exécuter certains formulaires
        Bureaucrat clerk("Clerk", 140);      // Grade très bas
        
        // Affichage des informations
        std::cout << "\n----- Test objects details -----" << std::endl;
        std::cout << "Shrub Form: " << shrubForm << std::endl;
        std::cout << "Robot Form: " << robotForm << std::endl;
        std::cout << "Pardon Form: " << pardonForm << std::endl;
        std::cout << "Chief: " << chief << std::endl;
        std::cout << "Manager: " << manager << std::endl;
        std::cout << "Clerk: " << clerk << std::endl;
        
        // Test de signature des formulaires
        std::cout << "\n----- Signing forms -----" << std::endl;
        chief.signForm(shrubForm);
        chief.signForm(robotForm);
        chief.signForm(pardonForm);
        
        // Tests d'exécution avec des bureaucrates de grade insuffisant
        std::cout << "\n----- Testing execution with insufficient grades -----" << std::endl;
        std::cout << "\nClerk tries to execute Shrub Form:" << std::endl;
        clerk.executeForm(shrubForm);
        
        std::cout << "\nManager tries to execute Robot Form:" << std::endl;
        manager.executeForm(robotForm);
        
        std::cout << "\nManager tries to execute Pardon Form:" << std::endl;
        manager.executeForm(pardonForm);
        
        // Tests d'exécution avec un bureaucrate de grade suffisant
        std::cout << "\n----- Testing execution with sufficient grade -----" << std::endl;
        std::cout << "\nChief executes all forms:" << std::endl;
        chief.executeForm(shrubForm);
        chief.executeForm(robotForm);
        chief.executeForm(pardonForm);
        
    }
    catch (std::exception &e) 
    {
        std::cout << "ERROR: Unexpected exception: " << e.what() << std::endl;
    }
}

void testInternFormCreation()
{
    std::cout << "\n=== TESTING INTERN FORM CREATION ===\n" << std::endl;
    
    // Création des objets nécessaires
    Intern intern;
    Bureaucrat boss("Boss", 1); // Grade 1 pour pouvoir signer/exécuter n'importe quel formulaire
    
    std::cout << "1. Testing valid form types:" << std::endl;
    
    // Test des trois types de formulaires valides
    const char* validTypes[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    
    for (int i = 0; i < 3; i++) 
    {
        try
        {
            std::cout << "\n-- Creating " << validTypes[i] << " form --" << std::endl;
            AForm* form = intern.makeForm(validTypes[i], "Test Target");
            
            // Afficher les détails du formulaire
            std::cout << "Form details: " << *form << std::endl;
            
            // Test de signature et d'exécution
            boss.signForm(*form);
            boss.executeForm(*form);
            
            // Libération de la mémoire
            delete form;
        }
        catch (std::exception& e) 
        {
            std::cout << "ERROR: " << e.what() << std::endl;
        }
    }
    
    // Test avec un type de formulaire invalide
    std::cout << "\n2. Testing invalid form type:" << std::endl;
    try
    {
        std::cout << "-- Attempting to create \"nonexistent form\" --" << std::endl;
        AForm* invalidForm = intern.makeForm("nonexistent form", "Test Target");
        delete invalidForm;  // Ne devrait jamais être exécuté
        std::cout << "ERROR: Exception was not thrown!" << std::endl;
    }
    catch (Intern::FormNotFoundException& e) 
    {
        std::cout << "SUCCESS: Expected exception caught - " << e.what() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "PARTIAL SUCCESS: Exception caught, but wrong type - " << e.what() << std::endl;
    }
}

// Teste l'exemple donné dans le sujet
void testSubjectExample()
{
    printSeparator("TESTING SUBJECT EXAMPLE");
    
    Intern someRandomIntern;
    AForm* rrf;
    
    std::cout << "Following the example from the subject..." << std::endl;
    try
    {
        std::cout << "\n1. Creating a robotomy request form:" << std::endl;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        
        std::cout << "\n2. Form details:" << std::endl;
        std::cout << *rrf << std::endl;
        
        std::cout << "\n3. Cleaning up resources:" << std::endl;
        delete rrf;
    }
    catch (std::exception &e)
    {
        std::cout << "ERROR: " << e.what() << std::endl;
    }
}

void testShrubberyFileCreation() 
{
    std::cout << "\n=== TESTING SHRUBBERY FILE CREATION ===\n" << std::endl;
    
    // Création des objets nécessaires
    Intern intern;
    Bureaucrat boss("Boss", 1);
    std::string target = "garden";
    
    try 
    {
        // Créer et exécuter un formulaire ShrubberyCreationForm
        std::cout << "Creating and executing a shrubbery creation form..." << std::endl;
        AForm* form = intern.makeForm("shrubbery creation", target);
        boss.signForm(*form);
        boss.executeForm(*form);
        
        // Lire le fichier créé
        std::string filename = target + "_shrubbery";
        std::ifstream file(filename.c_str());
        
        if (file.is_open()) 
        {
            std::cout << "\nContenu du fichier " << filename << ":\n" << std::endl;
            std::string line;
            while (std::getline(file, line)) 
            {
                std::cout << line << std::endl;
            }
            file.close();
            std::cout << "\nFichier lu avec succès!" << std::endl;
        } 
        else 
        {
            std::cout << "ERREUR: Impossible d'ouvrir le fichier " << filename << std::endl;
        }
        // Libération de la mémoire
        delete form;
    }
    catch (std::exception& e) 
    {
        std::cout << "ERREUR: " << e.what() << std::endl;
    }
}

// Fonction principale qui exécute tous les tests
int main()
{
    std::cout << "=======================================================" << std::endl;
    std::cout << "=================== EXCEPTION TESTS ===================" << std::endl;
    std::cout << "=======================================================" << std::endl;
    
    // Test de la nouvelle exception
    testGradeTooLowForExecution();
    
    std::cout << "=======================================================" << std::endl;
    std::cout << "=================== INTERN TESTS ======================" << std::endl;
    std::cout << "=======================================================" << std::endl;
    
    testInternFormCreation();
    testSubjectExample();
    testShrubberyFileCreation();
    
    std::cout << "\n=======================================================" << std::endl;
    std::cout << "=================== TESTS COMPLETE ====================" << std::endl;
    std::cout << "=======================================================" << std::endl;
    
    return 0;
}