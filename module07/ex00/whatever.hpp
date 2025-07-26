#ifndef WHATEVER_HPP
# define WHATEVER_HPP

// Fonction template swap qui échange les valeurs de deux arguments de même type
// Ne retourne rien (void)
template <typename T>
void swap(T &a, T &b)
{
    // Utilisation d'une variable temporaire pour l'échange
    T temp = a;          // Stocke la valeur de a dans temp
    a = b;               // Remplace a par b
    b = temp;            // Remplace b par l'ancienne valeur de a (stockée dans temp)
}

// Fonction template min qui compare deux valeurs et retourne la plus petite
// Si elles sont égales, retourne la seconde
template <typename T>
T const &min(T const &a, T const &b)
{
    // Compare a et b avec l'opérateur 
    // Si a est inférieur à b, retourne a, sinon retourne b
    return (a < b) ? a : b;
}

// Fonction template max qui compare deux valeurs et retourne la plus grande
// Si elles sont égales, retourne la seconde
template <typename T>
T const &max(T const &a, T const &b)
{
    // Compare a et b avec l'opérateur >
    // Si a est supérieur à b, retourne a, sinon retourne b
    return (a > b) ? a : b;
}

#endif