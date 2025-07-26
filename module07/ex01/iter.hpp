#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>  // Pour size_t

// Fonction template iter qui applique une fonction à chaque élément d'un tableau
// Paramètres:
// - array: adresse (pointeur) d'un tableau de type T
// - length: longueur du tableau
// - func: fonction à appliquer à chaque élément du tableau
template <typename T, typename Func>
void iter(T *array, size_t length, Func func)
{
    // Vérifie si le tableau est NULL
    if (array == NULL)
        return;

    // Parcourt chaque élément du tableau
    for (size_t i = 0; i < length; i++)
    {
        // Applique la fonction func à l'élément courant
        func(array[i]);
    }
}

#endif