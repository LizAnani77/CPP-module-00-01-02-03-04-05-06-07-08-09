#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>       // Pour cout, cerr
# include <string>         // Pour string
# include <stack>          // Pour stack
# include <cstdlib>        // Pour atoi
# include <exception>      // Pour exception

// Classe pour évaluer les expressions en Notation Polonaise Inversée
class RPN
{
private:
    std::stack<int> _stack;     // Pile pour stocker les opérandes
    
    // Méthodes privées
    bool isOperator(char c) const;                  // Vérifie si un caractère est un opérateur
    void performOperation(char op);                 // Effectue l'opération
    
public:
    // Forme canonique de Coplien
    RPN();                                          // Constructeur par défaut
    RPN(const RPN& src);                            // Constructeur de copie
    ~RPN();                                         // Destructeur
    
    RPN& operator=(const RPN& rhs);                 // Opérateur d'affectation
    
    // Méthodes publiques
    int evaluate(const std::string& expression);    // Évalue l'expression RPN
    
    // Classes d'exceptions
    class InvalidExpressionError : public std::exception 
    {
        public:
            virtual const char* what() const throw() 
            {
                return "Error";
            }
    };
    
    class DivisionByZeroError : public std::exception 
    {
        public:
            virtual const char* what() const throw() 
            {
                return "Error: division by zero";
            }
    };
};

#endif