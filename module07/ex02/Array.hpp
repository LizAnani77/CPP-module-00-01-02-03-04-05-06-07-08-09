#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>      // Pour std::exception
#include <stdexcept>      // Pour std::out_of_range

// Classe template Array qui implémente un tableau dynamique de type T
template <typename T>
class Array
{
private:
    T *_array;            // Pointeur vers le tableau d'éléments
    unsigned int _size;   // Nombre d'éléments dans le tableau

public:
    // Constructeur par défaut - crée un tableau vide
    Array() : _array(NULL), _size(0)
    {
        // Initialisation des membres à NULL et 0
    }

    // Constructeur avec taille - crée un tableau de n éléments initialisés par défaut
    Array(unsigned int n) : _size(n)
    {
        // Alloue la mémoire pour n éléments de type T
        _array = new T[n]();  // () initialise les éléments par défaut
    }

    // Constructeur de copie - crée une copie profonde du tableau
    Array(const Array &src) : _array(NULL), _size(0)
    {
        // Appelle l'opérateur d'affectation qui gère la copie
        *this = src;
    }

    // Destructeur - libère la mémoire allouée
    ~Array()
    {
        // Libère le tableau si alloué
        if (_array)
            delete[] _array;
    }

    // Opérateur d'affectation - copie profonde du tableau
    Array &operator=(const Array &rhs)
    {
        // Protection contre l'auto-affectation
        if (this != &rhs)
        {
            // Libère la mémoire existante si nécessaire
            if (_array)
                delete[] _array;
            
            // Copie la taille
            _size = rhs._size;
            
            // Alloue un nouveau tableau si nécessaire
            if (_size > 0)
            {
                _array = new T[_size];
                
                // Copie chaque élément
                for (unsigned int i = 0; i < _size; i++)
                    _array[i] = rhs._array[i];
            }
            else
                _array = NULL;
        }
        return *this;
    }

    // Opérateur d'accès aux éléments (version non-const)
    T &operator[](unsigned int index)
    {
        // Vérifie si l'index est valide
        if (index >= _size)
            throw std::out_of_range("Index out of bounds");
        
        // Retourne une référence à l'élément
        return _array[index];
    }

    // Opérateur d'accès aux éléments (version const)
    const T &operator[](unsigned int index) const
    {
        // Vérifie si l'index est valide
        if (index >= _size)
            throw std::out_of_range("Index out of bounds");
        
        // Retourne une référence constante à l'élément
        return _array[index];
    }

    // Méthode size() - retourne le nombre d'éléments
    unsigned int size() const
    {
        return _size;  // Retourne la taille du tableau
    }
};

#endif