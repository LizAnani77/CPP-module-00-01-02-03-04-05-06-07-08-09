#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>   // Pour la classe std::stack
# include <deque>   // Pour le container par défaut std::deque

// Classe MutantStack qui étend std::stack en ajoutant des itérateurs
// Utilise l'héritage public pour étendre std::stack, tous les membres publics
// de std::stack deviennent des membres publics de MutantStack
// Container est le container sous-jacent, std::deque par défaut
template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
    // Constructeur par défaut - initialise la pile avec le constructeur par défaut de std::stack
    MutantStack() : std::stack<T, Container>() {}
    
    // Constructeur de copie - initialise la pile avec le constructeur de copie de std::stack
    MutantStack(const MutantStack &src) : std::stack<T, Container>(src) {}
    
    // Destructeur virtuel - permet l'héritage sécurisé
    virtual ~MutantStack() {}

    // Opérateur d'affectation - utilise l'opérateur d'affectation de std::stack
    MutantStack &operator=(const MutantStack &rhs)
    {
        // Vérification d'auto-affectation
        if (this != &rhs)
            std::stack<T, Container>::operator=(rhs);  // Appel de l'opérateur d'affectation de la classe de base
        return *this;  // Retourne l'objet courant
    }

    // Définition des types d'itérateurs en utilisant ceux du container sous-jacent
    typedef typename Container::iterator iterator;                     // Itérateur standard
    typedef typename Container::const_iterator const_iterator;         // Itérateur constant
    typedef typename Container::reverse_iterator reverse_iterator;     // Itérateur inverse
    typedef typename Container::const_reverse_iterator const_reverse_iterator;  // Itérateur inverse constant

    // Méthodes pour accéder aux itérateurs du container sous-jacent
    // std::stack a un membre protégé 'c' qui est le container
    
    // Début du container (premier élément ajouté)
    iterator begin() { return this->c.begin(); }
    // Fin du container (après le dernier élément)
    iterator end() { return this->c.end(); }
    
    // Versions const des itérateurs pour les objets const
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }
    
    // Début du container en ordre inverse (dernier élément ajouté)
    reverse_iterator rbegin() { return this->c.rbegin(); }
    // Fin du container en ordre inverse (avant le premier élément)
    reverse_iterator rend() { return this->c.rend(); }
    
    // Versions const des itérateurs inverses pour les objets const
    const_reverse_iterator rbegin() const { return this->c.rbegin(); }
    const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif