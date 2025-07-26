#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>      // Pour utiliser std::vector comme container
# include <algorithm>   // Pour std::sort, std::min_element, std::max_element
# include <stdexcept>   // Pour les exceptions standard
# include <limits>      // Pour std::numeric_limits

// Classe Span qui peut stocker N entiers et calculer des écarts
class Span
{
private:
    unsigned int _N;             // Nombre maximum d'entiers que le Span peut contenir
    std::vector<int> _numbers;   // Container pour stocker les entiers

public:
    // Constructeurs et destructeur (forme canonique de Coplien)
    Span();                      // Constructeur par défaut
    Span(unsigned int N);        // Constructeur avec taille maximale
    Span(const Span &src);       // Constructeur de copie
    ~Span();                     // Destructeur

    // Opérateur d'affectation (forme canonique de Coplien)
    Span &operator=(const Span &rhs);

    // Ajoute un entier au Span
    void addNumber(int number);
    
    // Calcule le plus petit écart entre deux entiers du Span
    int shortestSpan() const;
    
    // Calcule le plus grand écart entre deux entiers du Span
    int longestSpan() const;

    // Méthode template pour ajouter une plage d'itérateurs au Span
    // Permet d'ajouter plusieurs entiers en un seul appel
    template <typename Iterator>
    void addRange(Iterator begin, Iterator end)
    {
        // Compte le nombre d'éléments dans la plage
        unsigned int count = 0;
        for (Iterator it = begin; it != end; ++it)
            count++;
        
        // Vérifie si l'ajout dépasserait la capacité
        if (_numbers.size() + count > _N)
            throw std::out_of_range("Cannot add range: would exceed capacity");
        
        // Insère tous les éléments de la plage à la fin du vecteur
        _numbers.insert(_numbers.end(), begin, end);
    }
};

#endif