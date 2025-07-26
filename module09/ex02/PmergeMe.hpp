#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>       // Pour cout, cerr
# include <vector>         // Pour vector
# include <deque>          // Pour deque
# include <ctime>          // Pour clock
# include <iomanip>        // Pour std::fixed, std::setprecision
# include <algorithm>      // Pour sort, merge
# include <string>         // Pour string
# include <sstream>        // Pour stringstream
# include <utility>        // Pour std::pair

// Classe pour implémenter l'algorithme de tri Ford-Johnson (merge-insert sort)
class PmergeMe
{
private:
    std::vector<int> _vector;        // Conteneur vector pour le tri
    std::deque<int> _deque;          // Conteneur deque pour le tri
    double _vectorSortTime;          // Temps de tri pour vector
    double _dequeSortTime;           // Temps de tri pour deque
    
    // Méthodes privées pour le tri Ford-Johnson
    template <typename T>
    void fordJohnsonSort(T& container);          // Tri Ford-Johnson générique
    
    // Méthodes auxiliaires pour le tri Ford-Johnson
    std::vector<int> generateJacobsthalNumbers(size_t size);  // Génère les nombres de Jacobsthal
    
    template <typename T>
    size_t binarySearchInsertPosition(T& arr, int value, size_t start, size_t end);  // Recherche binaire
    
    template <typename T>
    void insertionSort(T& container, int left, int right);  // Tri par insertion pour petits tableaux
    
    template <typename T>
    void pairInsertionSort(T& chain, T& pend);    // Insertion des éléments selon Jacobsthal
    
    // Méthodes pour afficher le résultat
    void printBeforeSort(char **argv, int size);  // Affiche avant le tri
    void printAfterSort();                        // Affiche après le tri
    void printSortTimes(int size);                // Affiche les temps de tri
    
public:
    // Forme canonique de Coplien
    PmergeMe();                                   // Constructeur par défaut
    PmergeMe(char **argv, int size);              // Constructeur avec arguments
    PmergeMe(const PmergeMe& src);                // Constructeur de copie
    ~PmergeMe();                                  // Destructeur
    
    PmergeMe& operator=(const PmergeMe& rhs);     // Opérateur d'affectation
    
    // Méthodes publiques
    void sort();                                  // Trie les éléments
    void display(char **argv, int size);          // Affiche les résultats
    
    // Classes d'exceptions
    class InvalidInputError : public std::exception 
    {
        public:
            virtual const char* what() const throw() 
            {
                return "Error";
            }
    };
};

#endif