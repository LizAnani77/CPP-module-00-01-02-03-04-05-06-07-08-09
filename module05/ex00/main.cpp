#include "Bureaucrat.hpp"
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

// Teste la création de bureaucrates avec des grades valides
void testValidGrades()
{
    printSeparator("TESTING VALID GRADES");
    
    try 
    {
        // Crée des bureaucrates avec différents grades valides
        std::cout << "----- Creating bureaucrats with valid grades -----" << std::endl;
        
        // Grade le plus élevé
        Bureaucrat boss("Boss", 1);
        std::cout << "Highest grade bureaucrat: " << boss << std::endl;
        
        // Grade intermédiaire
        Bureaucrat manager("Manager", 75);
        std::cout << "Mid-level bureaucrat: " << manager << std::endl;
        
        // Grade le plus bas
        Bureaucrat intern("Intern", 150);
        std::cout << "Lowest grade bureaucrat: " << intern << std::endl;
    } 
    catch (std::exception &e) 
    {
        std::cout << "ERROR: Unexpected exception: " << e.what() << std::endl;
    }
}

// Teste la création de bureaucrates avec des grades invalides
void testInvalidGrades()
{
    printSeparator("TESTING INVALID GRADES");
    
    // Test d'un grade trop élevé (0)
    std::cout << "----- Test 1: Creating bureaucrat with too high grade (0) -----" << std::endl;
    try
    {
        Bureaucrat tooHigh("TooHigh", 0);
        std::cout << "ERROR: This should not be displayed" << std::endl;
    } 
    catch (std::exception &e) 
    {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }
    
    // Test d'un grade trop bas (151)
    std::cout << "\n----- Test 2: Creating bureaucrat with too low grade (151) -----" << std::endl;
    try 
    {
        Bureaucrat tooLow("TooLow", 151);
        std::cout << "ERROR: This should not be displayed" << std::endl;
    } 
    catch (std::exception &e) 
    {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }
}

// Teste les méthodes d'incrémentation et de décrémentation
void testIncrementDecrement()
{
    printSeparator("TESTING INCREMENT/DECREMENT");
    
    // Test avec un bureaucrate de grade intermédiaire
    std::cout << "----- Test 1: Normal increment and decrement operations -----" << std::endl;
    try
    {
        Bureaucrat normal("Normal", 75);
        std::cout << "Initial state: " << normal << std::endl;
        
        normal.incrementGrade();
        std::cout << "After increment (grade should be 74): " << normal << std::endl;
        
        normal.decrementGrade();
        std::cout << "After decrement (grade should be 75): " << normal << std::endl;
    } 
    catch (std::exception &e) 
    {
        std::cout << "ERROR: Unexpected exception: " << e.what() << std::endl;
    }
    
    // Test d'incrémentation au grade maximum
    std::cout << "\n----- Test 2: Incrementing from highest grade (1) -----" << std::endl;
    try 
    {
        Bureaucrat highest("Highest", 1);
        std::cout << "Initial state: " << highest << std::endl;
        
        highest.incrementGrade();
        std::cout << "ERROR: This should not be displayed" << std::endl;
    } 
    catch (std::exception &e) 
    {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }
    
    // Test de décrémentation au grade minimum
    std::cout << "\n----- Test 3: Decrementing from lowest grade (150) -----" << std::endl;
    try 
    {
        Bureaucrat lowest("Lowest", 150);
        std::cout << "Initial state: " << lowest << std::endl;
        
        lowest.decrementGrade();
        std::cout << "ERROR: This should not be displayed" << std::endl;
    } 
    catch (std::exception &e) 
    {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }
}

// Teste le constructeur de copie et l'opérateur d'affectation
void testCopyAndAssignment()
{
    printSeparator("TESTING COPY AND ASSIGNMENT");
    
    // Création d'un bureaucrate original
    std::cout << "----- Creating original bureaucrat -----" << std::endl;
    Bureaucrat original("Original", 42);
    std::cout << "Original: " << original << std::endl;
    
    // Test du constructeur de copie
    std::cout << "\n----- Test 1: Using copy constructor -----" << std::endl;
    Bureaucrat copy(original);
    std::cout << "Copy: " << copy << std::endl;
    
    // Test de l'opérateur d'affectation
    std::cout << "\n----- Test 2: Using assignment operator -----" << std::endl;
    Bureaucrat assigned = original;
    std::cout << "Assigned: " << assigned << std::endl;
    
    // Test de l'indépendance des objets
    std::cout << "\n----- Test 3: Testing independence after modification -----" << std::endl;
    std::cout << "Incrementing the original's grade..." << std::endl;
    original.incrementGrade();
    
    std::cout << "\n----- Results after modification -----" << std::endl;
    std::cout << "Original after increment (grade should be 41): " << original << std::endl;
    std::cout << "Copy (grade should still be 42): " << copy << std::endl;
    std::cout << "Assigned (grade should still be 42): " << assigned << std::endl;
}

// Fonction principale qui exécute tous les tests
int main()
{
    std::cout << "=======================================================" << std::endl;
    std::cout << "================= BUREAUCRAT TESTS ====================" << std::endl;
    std::cout << "=======================================================" << std::endl;
    
    // Exécute tous les tests
    testValidGrades();
    testInvalidGrades();
    testIncrementDecrement();
    testCopyAndAssignment();

    std::cout << "\n=======================================================" << std::endl;
    std::cout << "=================== TESTS COMPLETE ====================" << std::endl;
    std::cout << "=======================================================" << std::endl;
    
    return 0;
}