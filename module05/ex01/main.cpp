#include "Bureaucrat.hpp"
#include "Form.hpp"
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

// Teste la création de formulaires avec des grades valides et invalides
void testFormCreation()
{
    printSeparator("TESTING FORM CREATION");
    
    try 
    {
        // Crée un formulaire avec des grades valides
        std::cout << "----- Creating a valid form -----" << std::endl;
        Form f1("Tax Form", 100, 50);
        std::cout << "Form created: " << f1 << std::endl;
        
        // Teste un grade de signature trop élevé (0 - devrait échouer)
        std::cout << "\n----- Testing form with too high sign grade (0) -----" << std::endl;
        try 
        {
            Form f2("Invalid Form", 0, 50);
            std::cout << "ERROR: This should not be displayed" << std::endl;
        } 
        catch (std::exception &e) 
        {
            std::cout << "Expected exception: " << e.what() << std::endl;
        }
        
        // Teste un grade d'exécution trop bas (151 - devrait échouer)
        std::cout << "\n----- Testing form with too low execute grade (151) -----" << std::endl;
        try 
        {
            Form f3("Invalid Form", 100, 151);
            std::cout << "ERROR: This should not be displayed" << std::endl;
        } 
        catch (std::exception &e) 
        {
            std::cout << "Expected exception: " << e.what() << std::endl;
        }
    } 
    catch (std::exception &e) 
    {
        std::cout << "ERROR: Unexpected exception: " << e.what() << std::endl;
    }
}

// Teste la signature de formulaires par différents bureaucrates
void testFormSigning()
{
    printSeparator("TESTING FORM SIGNING");
    
    // Création des objets de test
    std::cout << "Creating test objects..." << std::endl;
    Form form("Important Document", 50, 25);
    Bureaucrat boss("Boss", 1);          // Grade très élevé
    Bureaucrat manager("Manager", 40);   // Grade suffisant pour signer
    Bureaucrat intern("Intern", 150);    // Grade insuffisant pour signer
    
    // Affichage des informations
    std::cout << "\n----- Test objects details -----" << std::endl;
    std::cout << "Form: " << form << std::endl;
    std::cout << "Boss: " << boss << std::endl;
    std::cout << "Manager: " << manager << std::endl;
    std::cout << "Intern: " << intern << std::endl;
    
    // Test de signature par un bureaucrate de grade insuffisant
    std::cout << "\n----- Test 1: Intern tries to sign (insufficient grade) -----" << std::endl;
    intern.signForm(form);
    std::cout << "Form state after attempt: " << form << std::endl;
    
    // Test de signature par un bureaucrate de grade suffisant
    std::cout << "\n----- Test 2: Manager tries to sign (sufficient grade) -----" << std::endl;
    manager.signForm(form);
    std::cout << "Form state after signing: " << form << std::endl;
    
    // Test de signature d'un formulaire déjà signé
    std::cout << "\n----- Test 3: Boss tries to sign already signed form -----" << std::endl;
    boss.signForm(form);
    std::cout << "Form state after second signing attempt: " << form << std::endl;
}

// Teste la copie et l'affectation de formulaires
void testFormCopyAndAssignment()
{
    printSeparator("TESTING FORM COPY AND ASSIGNMENT");
    
    // Création des objets de test
    std::cout << "Creating test objects..." << std::endl;
    Form original("Original Form", 100, 75);
    Bureaucrat boss("Boss", 1);
    
    // Affichage de l'original
    std::cout << "\n----- Original form details -----" << std::endl;
    std::cout << "Original: " << original << std::endl;
    
    // Test du constructeur de copie
    std::cout << "\n----- Test 1: Testing copy constructor -----" << std::endl;
    Form copy(original);
    std::cout << "Copy: " << copy << std::endl;
    
    // Test de l'opérateur d'affectation (version corrigée)
    std::cout << "\n----- Test 2: Testing assignment operator -----" << std::endl;
    Form assigned; // Utilise le constructeur par défaut
    std::cout << "Before assignment: " << assigned << std::endl;
    assigned = original; // Maintenant utilise l'opérateur d'affectation
    std::cout << "After assignment: " << assigned << std::endl;
    
    // Modification de l'original pour tester l'indépendance
    std::cout << "\n----- Test 3: Testing independence of copied forms -----" << std::endl;
    std::cout << "Signing the original form..." << std::endl;
    boss.signForm(original);
    
    // Vérification de l'indépendance
    std::cout << "\n----- Results after signing original -----" << std::endl;
    std::cout << "Original (should be signed): " << original << std::endl;
    std::cout << "Copy (should be unchanged): " << copy << std::endl;
    std::cout << "Assigned (should be unchanged): " << assigned << std::endl;
}

// Fonction principale qui exécute tous les tests
int main()
{
    std::cout << "=======================================================" << std::endl;
    std::cout << "==================== FORM TESTS =======================" << std::endl;
    std::cout << "=======================================================" << std::endl;
    
    // Exécute tous les tests
    testFormCreation();
    testFormSigning();
    testFormCopyAndAssignment();
    
    std::cout << "\n=======================================================" << std::endl;
    std::cout << "=================== TESTS COMPLETE ====================" << std::endl;
    std::cout << "=======================================================" << std::endl;
    
    return 0;
}