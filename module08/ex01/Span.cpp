#include "Span.hpp"

// Constructeur par défaut - initialise un Span vide avec capacité 0
Span::Span() : _N(0)
{
    // _numbers est initialisé à un vecteur vide par le constructeur par défaut de vector
}

// Constructeur avec paramètre - initialise un Span avec capacité N
Span::Span(unsigned int N) : _N(N)
{
    // _numbers est initialisé à un vecteur vide mais avec capacité potentielle de N
}

// Constructeur de copie - crée une copie profonde du Span source
Span::Span(const Span &src) : _N(src._N), _numbers(src._numbers)
{
    // Copie la capacité et le vecteur d'entiers
}

// Destructeur - pas de mémoire à libérer manuellement (vector s'en charge)
Span::~Span()
{
    // Les membres sont automatiquement détruits
}

// Opérateur d'affectation - copie profonde des attributs
Span &Span::operator=(const Span &rhs)
{
    // Vérification d'auto-affectation
    if (this != &rhs)
    {
        // Copie de la capacité
        _N = rhs._N;
        // Copie des nombres
        _numbers = rhs._numbers;
    }
    return *this;  // Retourne l'objet courant
}

// Ajoute un entier au Span, lance une exception si le Span est plein
void Span::addNumber(int number)
{
    // Vérifie si le Span est déjà plein
    if (_numbers.size() >= _N)
        throw std::out_of_range("Cannot add number: Span is full");
    
    // Ajoute le nombre au vecteur
    _numbers.push_back(number);
}

// Calcule le plus petit écart entre deux entiers du Span
// Lance une exception s'il y a moins de 2 entiers
int Span::shortestSpan() const
{
    // Vérifie s'il y a au moins 2 entiers pour calculer un écart
    if (_numbers.size() <= 1)
        throw std::logic_error("Cannot find span: need at least 2 numbers");

    // Crée une copie triée du vecteur d'entiers
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    // Calcule le plus petit écart en parcourant le vecteur trié
    int minSpan = std::numeric_limits<int>::max();  // Initialise à la valeur maximale possible
    for (size_t i = 1; i < sorted.size(); ++i)
    {
        // Calcule l'écart entre deux éléments consécutifs
        int span = sorted[i] - sorted[i - 1];
        // Met à jour le plus petit écart si nécessaire
        if (span < minSpan)
            minSpan = span;
    }

    return minSpan;  // Retourne le plus petit écart trouvé
}

// Calcule le plus grand écart entre deux entiers du Span
// Lance une exception s'il y a moins de 2 entiers
int Span::longestSpan() const
{
    // Vérifie s'il y a au moins 2 entiers pour calculer un écart
    if (_numbers.size() <= 1)
        throw std::logic_error("Cannot find span: need at least 2 numbers");

    // Trouve l'élément minimum dans le vecteur
    std::vector<int>::const_iterator min = std::min_element(_numbers.begin(), _numbers.end());
    // Trouve l'élément maximum dans le vecteur
    std::vector<int>::const_iterator max = std::max_element(_numbers.begin(), _numbers.end());

    // Retourne la différence entre le maximum et le minimum (le plus grand écart)
    return *max - *min;
}