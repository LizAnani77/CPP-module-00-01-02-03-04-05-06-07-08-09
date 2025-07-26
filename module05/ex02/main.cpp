#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
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

// Teste le formulaire ShrubberyCreationForm dans différents scénarios
void testShrubberyCreationForm()
{
    printSeparator("TESTING SHRUBBERY CREATION FORM");
    
    try 
    {
        // Création des objets de test
        std::cout << "Creating test objects..." << std::endl;
        ShrubberyCreationForm form("garden");
        Bureaucrat boss("Boss", 1);           // Grade très élevé (peut tout faire)
        Bureaucrat manager("Manager", 140);   // Grade suffisant pour signer mais pas pour exécuter
        Bureaucrat intern("Intern", 150);     // Grade insuffisant pour signer ou exécuter
        
        // Affichage des informations du formulaire
        std::cout << "\n----- Form details -----" << std::endl;
        std::cout << "Form: " << form << std::endl;
        std::cout << "Boss: " << boss << std::endl;
        std::cout << "Manager: " << manager << std::endl;
        std::cout << "Intern: " << intern << std::endl;
        
        // Test d'exécution sans signature
        std::cout << "\n----- Test 1: Executing without signing -----" << std::endl;
        boss.executeForm(form);

        // Test de signature par un bureaucrate de grade insuffisant
        std::cout << "\n----- Test 2: Intern tries to sign (insufficient grade) -----" << std::endl;
        intern.signForm(form);
        
        // Test de signature par un bureaucrate de grade suffisant
        std::cout << "\n----- Test 3: Manager signs the form (sufficient grade) -----" << std::endl;
        manager.signForm(form);
        
        // Test d'exécution par un bureaucrate de grade insuffisant
        std::cout << "\n----- Test 4: Manager tries to execute (insufficient grade) -----" << std::endl;
        manager.executeForm(form);
        
        // Test d'exécution par un bureaucrate de grade suffisant
        std::cout << "\n----- Test 5: Boss executes the form (sufficient grade) -----" << std::endl;
        boss.executeForm(form);
        
    } 
    catch (std::exception &e) 
    {
        std::cout << "ERROR: Unexpected exception: " << e.what() << std::endl;
    }
}

// Teste le formulaire RobotomyRequestForm dans différents scénarios
void testRobotomyRequestForm()
{
    printSeparator("TESTING ROBOTOMY REQUEST FORM");
    
    try 
    {
        // Création des objets de test
        std::cout << "Creating test objects..." << std::endl;
        RobotomyRequestForm form("Bender");
        Bureaucrat boss("Boss", 1);         // Grade très élevé (peut tout faire)
        Bureaucrat manager("Manager", 50);  // Grade insuffisant pour exécuter (> 45 requis)
        Bureaucrat clerk("Clerk", 70);      // Grade suffisant pour signer mais pas pour exécuter
        
        // Affichage des informations du formulaire
        std::cout << "\n----- Form details -----" << std::endl;
        std::cout << "Form: " << form << std::endl;
        std::cout << "Boss: " << boss << std::endl;
        std::cout << "Manager: " << manager << std::endl;
        std::cout << "Clerk: " << clerk << std::endl;
        
        // Test de signature par un bureaucrate de grade suffisant
        std::cout << "\n----- Test 1: Clerk signs the form (sufficient grade) -----" << std::endl;
        clerk.signForm(form);
        
        // Test d'exécution par un bureaucrate de grade insuffisant
        std::cout << "\n----- Test 2: Manager tries to execute (insufficient grade) -----" << std::endl;
        manager.executeForm(form);
        
        // Tests multiples d'exécution pour démontrer l'aléatoire
        std::cout << "\n----- Test 3: Boss executes the form multiple times -----" << std::endl;
        for (int i = 0; i < 3; i++) 
        {
            std::cout << "\nExecution attempt " << (i+1) << ":" << std::endl;
            boss.executeForm(form);
        }
        
    } 
    catch (std::exception &e) 
    {
        std::cout << "ERROR: Unexpected exception: " << e.what() << std::endl;
    }
}

// Teste le formulaire PresidentialPardonForm dans différents scénarios
void testPresidentialPardonForm()
{
    printSeparator("TESTING PRESIDENTIAL PARDON FORM");
    
    try 
    {
        // Création des objets de test
        std::cout << "Creating test objects..." << std::endl;
        PresidentialPardonForm form("Arthur Dent");
        Bureaucrat president("President", 1);    // Grade très élevé (peut tout faire)
        Bureaucrat minister("Minister", 20);     // Grade suffisant pour signer mais pas pour exécuter
        Bureaucrat secretary("Secretary", 30);   // Grade insuffisant pour signer ou exécuter
        
        // Affichage des informations du formulaire
        std::cout << "\n----- Form details -----" << std::endl;
        std::cout << "Form: " << form << std::endl;
        std::cout << "President: " << president << std::endl;
        std::cout << "Minister: " << minister << std::endl;
        std::cout << "Secretary: " << secretary << std::endl;
        
        // Test de signature par un bureaucrate de grade insuffisant
        std::cout << "\n----- Test 1: Secretary tries to sign (insufficient grade) -----" << std::endl;
        secretary.signForm(form);
        
        // Test de signature par un bureaucrate de grade suffisant
        std::cout << "\n----- Test 2: Minister signs the form (sufficient grade) -----" << std::endl;
        minister.signForm(form);
        
        // Test d'exécution par un bureaucrate de grade insuffisant
        std::cout << "\n----- Test 3: Minister tries to execute (insufficient grade) -----" << std::endl;
        minister.executeForm(form);
        
        // Test d'exécution par un bureaucrate de grade suffisant
        std::cout << "\n----- Test 4: President executes the form (sufficient grade) -----" << std::endl;
        president.executeForm(form);
        
    } 
    catch (std::exception &e) 
    {
        std::cout << "ERROR: Unexpected exception: " << e.what() << std::endl;
    }
}

void testFormsExecution()
{
    std::cout << "\n=== TESTING CONCRETE FORMS ===\n" << std::endl;
    
    // Création des objets
    Bureaucrat boss("BigBoss", 1);
    std::string target = "test";
    
    try 
    {
        // Test ShrubberyCreationForm
        std::cout << "1. Testing ShrubberyCreationForm:" << std::endl;
        ShrubberyCreationForm shrub(target);
        boss.signForm(shrub);
        boss.executeForm(shrub);
        
        // Vérification et affichage du fichier créé
        std::string filename = target + "_shrubbery";
        std::ifstream file(filename.c_str());
        if (file.is_open()) {
            std::cout << "   - Fichier " << filename << " créé avec succès!" << std::endl;
            std::cout << "   - Contenu du fichier:" << std::endl;
            std::cout << "   ----------------------" << std::endl;
            std::string line;
            while (std::getline(file, line)) 
            {
                std::cout << "   " << line << std::endl;
            }
            std::cout << "   ----------------------" << std::endl;
            file.close();
        } 
        else 
        {
            std::cout << "   - ERREUR: Impossible d'ouvrir le fichier " << filename << std::endl;
        }
        
        // Reste du test...
        std::cout << "\n2. Testing RobotomyRequestForm:" << std::endl;
        RobotomyRequestForm robot(target);
        boss.signForm(robot);
        boss.executeForm(robot);
        
        std::cout << "\n3. Testing PresidentialPardonForm:" << std::endl;
        PresidentialPardonForm pardon(target);
        boss.signForm(pardon);
        boss.executeForm(pardon);
    }
    catch (std::exception& e)
    {
        std::cout << "ERROR: " << e.what() << std::endl;
    }
}

// Fonction principale qui exécute tous les tests
int main()
{
    std::cout << "=======================================================" << std::endl;
    std::cout << "=============== CONCRETE FORMS TESTS ==================" << std::endl;
    std::cout << "=======================================================" << std::endl;
    
    // Exécute tous les tests pour chaque type de formulaire
    testShrubberyCreationForm();
    testRobotomyRequestForm();
    testPresidentialPardonForm();
    testFormsExecution();
    
    std::cout << "\n=======================================================" << std::endl;
    std::cout << "=================== TESTS COMPLETE ====================" << std::endl;
    std::cout << "=======================================================" << std::endl;
    
    return 0;
}