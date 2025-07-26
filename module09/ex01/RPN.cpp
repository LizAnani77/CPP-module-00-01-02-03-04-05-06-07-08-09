#include "RPN.hpp"

// Constructeur par défaut - initialise la pile vide
RPN::RPN()
{
    // La pile _stack est initialisée par défaut
}

// Constructeur de copie - copie la pile depuis l'objet source
RPN::RPN(const RPN& src)
{
    *this = src;                                  // Utilise l'opérateur d'affectation
}

// Destructeur - nettoie les ressources
RPN::~RPN()
{
    // Pas de mémoire dynamique à libérer
}

// Opérateur d'affectation - copie la pile depuis l'objet source
RPN& RPN::operator=(const RPN& rhs)
{
    if (this != &rhs)                            // Vérifie l'auto-assignation
    {
        _stack = rhs._stack;                     // Copie la pile
    }
    return *this;                                // Retourne une référence sur this
}

// Vérifie si un caractère est un opérateur valide
bool RPN::isOperator(char c) const
{
    return (c == '+' || c == '-' || c == '*' || c == '/'); // Retourne vrai si c est un opérateur
}

// Effectue l'opération avec les deux derniers éléments de la pile
void RPN::performOperation(char op)
{
    if (_stack.size() < 2)                                // Vérifie s'il y a au moins 2 opérandes
        throw InvalidExpressionError();                   // Lance une exception si pas assez d'opérandes
    
    int b = _stack.top();                                 // Récupère le deuxième opérande
    _stack.pop();                                         // Retire le deuxième opérande de la pile
    int a = _stack.top();                                 // Récupère le premier opérande
    _stack.pop();                                         // Retire le premier opérande de la pile
    
    switch (op)                                           // Effectue l'opération selon l'opérateur
    {
        case '+':
            _stack.push(a + b);                           // Addition
            break;
        case '-':
            _stack.push(a - b);                           // Soustraction
            break;
        case '*':
            _stack.push(a * b);                           // Multiplication
            break;
        case '/':
            if (b == 0)                                   // Vérifie la division par zéro
                throw DivisionByZeroError();              // Lance une exception si division par zéro
            _stack.push(a / b);                           // Division
            break;
        default:
            throw InvalidExpressionError();               // Lance une exception si opérateur invalide
    }
}

// Évalue l'expression RPN et retourne le résultat
int RPN::evaluate(const std::string& expression)
{
    for (size_t i = 0; i < expression.size(); i++)        // Parcourt chaque caractère de l'expression
    {
        char c = expression[i];                           // Caractère courant
        
        if (c == ' ')                                     // Ignore les espaces
            continue;
        
        if (isdigit(c))                                   // Si c'est un chiffre
        {
            if (c - '0' >= 10)                            // Vérifie que le chiffre est < 10
                throw InvalidExpressionError();           // Lance une exception si chiffre >= 10
            _stack.push(c - '0');                         // Convertit le caractère en entier et l'ajoute à la pile
        }
        else if (isOperator(c))                           // Si c'est un opérateur
        {
            performOperation(c);                          // Effectue l'opération
        }
        else                                              // Si c'est un caractère invalide
        {
            throw InvalidExpressionError();              // Lance une exception
        }
    }
    
    if (_stack.size() != 1)                              // Vérifie qu'il reste exactement un résultat
        throw InvalidExpressionError();                  // Lance une exception si expression invalide
    
    return _stack.top();                                 // Retourne le résultat final
}