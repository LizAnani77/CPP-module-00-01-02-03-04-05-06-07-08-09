#include "PmergeMe.hpp"

// Constructeur par défaut - initialise les conteneurs vides
PmergeMe::PmergeMe() : _vectorSortTime(0.0), _dequeSortTime(0.0)
{
    // Les conteneurs _vector et _deque sont initialisés par défaut
}

// Constructeur avec arguments - remplit les conteneurs avec les valeurs fournies, et initialise à zéro les chronomètres
PmergeMe::PmergeMe(char **argv, int size) : _vectorSortTime(0.0), _dequeSortTime(0.0)
{
    for (int i = 1; i < size; ++i)                 // Parcourt tous les arguments
    {
        std::stringstream ss(argv[i]);             // Crée un stream pour l'argument
        int value;                                 // Valeur à extraire
        
        if (!(ss >> value) || !ss.eof() || value < 0) // Vérifie si l'argument est un entier positif
            throw InvalidInputError();             // Lance une exception si invalide
        
        _vector.push_back(value);                  // Ajoute la valeur au vector
        _deque.push_back(value);                   // Ajoute la valeur au deque
    }
}

// Constructeur de copie - copie les conteneurs et les temps
PmergeMe::PmergeMe(const PmergeMe& src)
{
    *this = src;                                   // Utilise l'opérateur d'affectation
}

// Destructeur - nettoie les ressources
PmergeMe::~PmergeMe()
{
    // Pas de mémoire dynamique à libérer
}

// Opérateur d'affectation - copie les conteneurs et les temps
PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
    if (this != &rhs)                             // Vérifie l'auto-assignation
    {
        _vector = rhs._vector;                    // Copie le vector
        _deque = rhs._deque;                      // Copie le deque
        _vectorSortTime = rhs._vectorSortTime;    // Copie le temps de tri du vector
        _dequeSortTime = rhs._dequeSortTime;      // Copie le temps de tri du deque
    }
    return *this;                                 // Retourne une référence sur this
}

// Tri par insertion pour un conteneur générique (utilisé pour les petits tableaux)
template <typename T>
void PmergeMe::insertionSort(T& container, int left, int right)
{
    for (int i = left + 1; i <= right; i++)        // Parcourt le conteneur de gauche à droite
    {
        int temp = container[i];                   // Élément à insérer
        int j = i - 1;                             // Position précédente
        
        // Déplace les éléments plus grands que temp vers la droite
        while (j >= left && container[j] > temp)
        {
            container[j + 1] = container[j];       // Déplace l'élément vers la droite
            j--;                                   // Passe à l'élément précédent
        }
        
        container[j + 1] = temp;                   // Insère temp à sa position correcte
    }
}

// Génère les nombres de Jacobsthal jusqu'à une taille donnée
std::vector<int> PmergeMe::generateJacobsthalNumbers(size_t size)
{
    std::vector<int> jacobsthal;                   // Tableau pour stocker les nombres
    
    jacobsthal.push_back(0);                       // J(0) = 0
    if (size == 0) return jacobsthal;              // Si size est 0, on retourne [0]
    
    jacobsthal.push_back(1);                       // J(1) = 1
    if (size == 1) return jacobsthal;              // Si size est 1, on retourne [0, 1]
    
    size_t i = 2;                                  // Index pour calculer J(i)
    while (i <= size)                              // Tant qu'on n'a pas calculé assez de nombres
    {
        // Formule de récurrence: J(n) = J(n-1) + 2*J(n-2)
        jacobsthal.push_back(jacobsthal[i-1] + 2 * jacobsthal[i-2]);
        i++;                                       // Passe au nombre suivant
    }
    
    return jacobsthal;                             // Retourne les nombres calculés
}

// Recherche binaire pour trouver la position d'insertion 
template <typename T>
size_t PmergeMe::binarySearchInsertPosition(T& arr, int value, size_t start, size_t end)
{
    if (start >= end)                              // Cas de base: un seul élément à considérer
        return (arr[start] > value) ? start : start + 1;
    
    size_t mid = start + (end - start) / 2;        // Trouve le milieu
    
    if (arr[mid] == value)                         // Si la valeur est trouvée
        return mid;
    
    if (arr[mid] > value)                          // Si la valeur est dans la moitié gauche
        return binarySearchInsertPosition(arr, value, start, mid);
    
    return binarySearchInsertPosition(arr, value, mid + 1, end);  // Sinon, dans la moitié droite
}

// Insertion des éléments selon la séquence de Jacobsthal
template <typename T>
void PmergeMe::pairInsertionSort(T& chain, T& pend)
{
    size_t n = pend.size();                        // Nombre d'éléments à insérer
    if (n == 0) return;                            // Si rien à insérer, on s'arrête
    
    // Calculer les indices de Jacobsthal
    std::vector<int> jacobsthal = generateJacobsthalNumbers(n);
    
    // Filtrer et ordonner les indices de Jacobsthal pour l'insertion
    std::vector<size_t> insertIndices;             // Stocke les indices à insérer
    
    for (size_t i = 1; i <= n; ++i)                // Pour chaque indice de 1 à n
    {
        size_t idx = 0;                            // Indice de Jacobsthal à utiliser
        while (idx < jacobsthal.size() && static_cast<size_t>(jacobsthal[idx]) <= i)
            idx++;                                 // Trouve le plus grand nombre de Jacobsthal <= i
        
        idx--;                                     // Recule d'un pas
        size_t jIdx = jacobsthal[idx];             // Obtient le nombre de Jacobsthal
        
        if (jIdx <= i && !std::count(insertIndices.begin(), insertIndices.end(), jIdx - 1))
            insertIndices.push_back(jIdx - 1);     // Ajoute l'indice si pas déjà présent
    }
    
    // Insérer les éléments selon l'ordre calculé
    for (size_t i = 0; i < insertIndices.size(); ++i)
    {
        size_t idx = insertIndices[i];             // Indice de l'élément à insérer
        if (idx < pend.size())                     // Vérifie que l'indice est valide
        {
            // Recherche binaire pour trouver la position d'insertion
            size_t pos = 0;                        // Position d'insertion
            if (!chain.empty())                    // Si la chaîne n'est pas vide
                pos = binarySearchInsertPosition(chain, pend[idx], 0, chain.size() - 1);
            
            chain.insert(chain.begin() + pos, pend[idx]);  // Insère l'élément
        }
    }
    
    // Vérifier s'il reste des éléments non insérés
    for (size_t i = 0; i < pend.size(); ++i)
    {
        if (std::find(insertIndices.begin(), insertIndices.end(), i) == insertIndices.end())
        {
            // Pour les éléments non couverts par la séquence, insertion classique
            size_t pos = 0;                        // Position d'insertion
            if (!chain.empty())                    // Si la chaîne n'est pas vide
                pos = binarySearchInsertPosition(chain, pend[i], 0, chain.size() - 1);
            
            chain.insert(chain.begin() + pos, pend[i]);  // Insère l'élément
        }
    }
}

// Implémentation de l'algorithme de tri Ford-Johnson
template <typename T>
void PmergeMe::fordJohnsonSort(T& container)
{
    size_t size = container.size();                // Taille du conteneur
    
    if (size <= 1)                                 // Si 0 ou 1 élément, déjà trié
        return;
    
    // Si petit tableau, utiliser tri insertion direct
    if (size <= 16)
    {
        insertionSort(container, 0, size - 1);
        return;
    }
    
    // Étape 1: Former des paires
    T mainChain;                                   // Chaîne principale pour les grands éléments
    T pendingElements;                             // Éléments en attente (petits de chaque paire)
    size_t extraIndex = -1;                        // Indice pour un éventuel élément non apparié
    
    for (size_t i = 0; i < size - 1; i += 2)       // Parcourir par paires
    {
        if (container[i] > container[i + 1])       // Si premier > second
        {
            mainChain.push_back(container[i]);     // Grand élément dans mainChain
            pendingElements.push_back(container[i + 1]);  // Petit élément dans pending
        }
        else                                        // Si premier <= second
        {
            mainChain.push_back(container[i + 1]);  // Grand élément dans mainChain
            pendingElements.push_back(container[i]);// Petit élément dans pending
        }
    }
    
    // Traiter l'élément non apparié s'il existe
    if (size % 2 != 0)                              // Si nombre impair d'éléments
    {
        extraIndex = size - 1;                      // Dernier élément
    }
    
    // Étape 2: Trier récursivement les grands éléments
    fordJohnsonSort(mainChain);                     // Appel récursif
    
    // Étape 3: Insérer les petits éléments selon la séquence de Jacobsthal
    pairInsertionSort(mainChain, pendingElements);  // Insertion des petits éléments
    
    // Étape 4: Insérer l'élément non apparié si nécessaire
    if (extraIndex != static_cast<size_t>(-1))      // Si élément non apparié
    {
        int extraElement = container[extraIndex];   // Récupère l'élément
        
        // Recherche binaire pour trouver la position d'insertion
        size_t pos = binarySearchInsertPosition(mainChain, extraElement, 0, mainChain.size() - 1);
        
        mainChain.insert(mainChain.begin() + pos, extraElement);  // Insère l'élément
    }
    
    // Copier le résultat trié dans le conteneur original
    container = mainChain;                         // Remplace le conteneur par la chaîne triée
}

void PmergeMe::sort()
{
    // Définit le nombre de répétitions selon la taille du conteneur pour obtenir des mesures fiables
    int repeat = (_vector.size() <= 10) ? 10000 : (_vector.size() <= 100 ? 1000 : (_vector.size() <= 1000 ? 100 : 1));
    
    // Initialise les variables pour stocker le temps total de tri pour chaque conteneur
    double totalVectorTime = 0.0;
    double totalDequeTime = 0.0;
    
    // Déclare des variables pour stocker les versions triées des conteneurs
    std::vector<int> sortedVector;
    std::deque<int> sortedDeque;
    
    // Boucle pour mesurer les performances du tri avec vector
    for (int i = 0; i < repeat; ++i)
    {
        // Crée une copie du vecteur original pour ne pas le modifier pendant les tests
        std::vector<int> tmp = _vector;
        
        // Enregistre le temps avant de commencer le tri
        clock_t start = clock();
        // Trie la copie du vecteur avec l'algorithme Ford-Johnson
        fordJohnsonSort(tmp);
        // Enregistre le temps après la fin du tri
        clock_t end = clock();
        
        // Calcule la durée du tri en microsecondes et l'ajoute au temps total
        totalVectorTime += (double)(end - start) / CLOCKS_PER_SEC * 1000000.0;
        
        // Lors de la dernière itération, sauvegarde la version triée pour l'utiliser plus tard
        if (i == repeat - 1) {
            sortedVector = tmp;
        }
    }
    
    // Boucle pour mesurer les performances du tri avec deque (même processus que pour vector)
    for (int i = 0; i < repeat; ++i)
    {
        // Crée une copie de la deque originale
        std::deque<int> tmp = _deque;
        
        // Mesure le temps de tri de la deque
        clock_t start = clock();
        fordJohnsonSort(tmp);
        clock_t end = clock();
        
        // Ajoute le temps de cette itération au total
        totalDequeTime += (double)(end - start) / CLOCKS_PER_SEC * 1000000.0;
        
        // Sauvegarde la version triée de la deque lors de la dernière itération
        if (i == repeat - 1) {
            sortedDeque = tmp;
        }
    }
    
    // Calcule la moyenne du temps d'exécution pour les deux conteneurs
    _vectorSortTime = totalVectorTime / repeat;
    _dequeSortTime = totalDequeTime / repeat;
    
    // Met à jour les conteneurs originaux avec leurs versions triées
    _vector = sortedVector;
    _deque = sortedDeque;
}

// Affiche les éléments avant le tri
void PmergeMe::printBeforeSort(char **argv, int size)
{
    std::cout << "Before: ";                       // Entête
    for (int i = 1; i < size; ++i)                 // Parcourt tous les arguments
    {
        std::cout << argv[i] << " ";               // Affiche chaque argument
    }
    std::cout << std::endl;                        // Saut de ligne
}

// Affiche les éléments après le tri
void PmergeMe::printAfterSort()
{
    std::cout << "After:  ";                       // Entête
    for (size_t i = 0; i < _vector.size(); ++i)    // Parcourt le vector trié
    {
        std::cout << _vector[i] << " ";            // Affiche chaque élément
    }
    std::cout << std::endl;                        // Saut de ligne
}

// Affiche les temps de tri pour les deux conteneurs
void PmergeMe::printSortTimes(int size)
{
    std::cout << "Time to process a range of " << size - 1 << " elements with std::vector : " 
              << std::fixed << std::setprecision(5) << _vectorSortTime << " us" << std::endl;
    std::cout << "Time to process a range of " << size - 1 << " elements with std::deque : " 
              << std::fixed << std::setprecision(5) << _dequeSortTime << " us" << std::endl;
}


// Affiche tous les résultats (avant, après et temps)
void PmergeMe::display(char **argv, int size)
{
    printBeforeSort(argv, size);                   // Affiche avant le tri
    printAfterSort();                              // Affiche après le tri
    printSortTimes(size);                          // Affiche les temps de tri
}