#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>  // Pour utiliser std::find
# include <stdexcept>  // Pour utiliser les exceptions standard

// Fonction template qui trouve la première occurrence d'un entier dans un container
// T est le type de container (vector, list, deque, etc.)
// Retourne un itérateur vers l'élément trouvé ou lance une exception
template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    // std::find recherche la première occurrence de value dans le container
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    
    // Si l'élément n'est pas trouvé (itérateur atteint la fin), lance une exception
    if (it == container.end())
        throw std::runtime_error("Value not found in container");
    
    // Retourne l'itérateur vers l'élément trouvé
    return it;
}

#endif


// class ValueNotFoundException : public std::exception
// {
// public:
//     virtual const char* what() const throw()
//     {
//         return "Value not found in container";
//     }
// };

// template <typename T>
// typename T::iterator easyfind(T &container, int value)
// {
//     typename T::iterator it = std::find(container.begin(), container.end(), value);

//     if (it == container.end())
//         throw ValueNotFoundException();
//     return it;
// }