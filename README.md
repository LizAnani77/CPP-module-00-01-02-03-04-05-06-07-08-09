# CPP-module-00-a-09
# C++ Module 00

## 📚 Résumé
Introduction à la syntaxe C++98, déclaration de classes simples, fonctions membres, gestion de la mémoire automatique.

## 🔧 Objectifs
- Découvrir la syntaxe de base de C++
- Créer des classes simples et leurs instances
- Comprendre les constructeurs et destructeurs

## 🛠️ Exercices clés
- **ex00** : Fonctions classiques
- **ex01** : Introduction aux classes
- **ex02** : Construction d’un `Account` avec comportement comptable
- **ex03** : Cycle de vie des objets (constructeur, destructeur, affichage)
- **ex04** : Révision et forme canonique

## ⚙️ Contraintes
- Compilation avec `-Wall -Wextra -Werror -std=c++98`
- Aucun `using namespace` autorisé
- Pas d’allocation dynamique inutile

# C++ Module 01

## 📚 Résumé
Ce module explore les notions de référence, pointeurs, opérateurs de flux, manipulation de fichiers, et fonctions membres statiques.

## 🔧 Objectifs
- Comprendre la différence entre références et pointeurs.
- Utiliser les flux d'entrée/sortie (`std::cin`, `std::cout`, `std::ifstream`, `std::ofstream`)
- Gérer les fichiers en lecture et écriture
- Étendre les compétences de base de la POO.

## 🛠️ Exercices clés
- **ex00** : Déréférencement, assignation de pointeurs
- **ex01** : Remplacement de mots dans un fichier
- **ex02** : Introduction à la POO : `Harl` et ses méthodes
- **ex03** : Fonctions membres statiques, filtrage de messages

## ⚙️ Contraintes
- Compilation avec `-Wall -Wextra -Werror -std=c++98`
- Aucun `using namespace` autorisé
- Pas d’allocation mémoire dynamique inutile

# C++ Module 02

## 📚 Résumé
Encapsulation, héritage simple, polymorphisme de base et forme canonique.

## 🔧 Objectifs
- Comprendre l’héritage en C++
- Maîtriser la forme canonique
- Appliquer l’encapsulation et la composition

## 🛠️ Exercices clés
- **ex00** : Création de classes respectant la forme canonique
- **ex01** : Création d’animaux avec héritage simple
- **ex02** : Ajout d’un cerveau (`Brain`) à certaines classes
- **ex03** : Gestion de la mémoire dynamique (`new` / `delete`)
- **ex04** : Tests de deep copy sur les objets

## ⚙️ Contraintes
- Utiliser `-std=c++98` et respecter les bonnes pratiques d’allocation/désallocation

# C++ Module 03

## 📚 Résumé
Classes abstraites, héritage, et polymorphisme dynamique.

## 🔧 Objectifs
- Comprendre les classes abstraites et les méthodes pures
- Gérer les pointeurs de classe de base vers objets dérivés
- Appliquer le polymorphisme dynamique

## 🛠️ Exercices clés
- **ex00** : Création d’interfaces (`AMateria`) et dérivés (`Ice`, `Cure`)
- **ex01** : Gestion d’un inventaire de matières avec une classe `Character`
- **ex02** : Implémentation d’un `MateriaSource` capable de créer dynamiquement des objets

## ⚙️ Contraintes
- Utiliser des pointeurs dynamiques
- Pas de fuite mémoire : bien gérer le `delete`

# C++ Module 04

## 📚 Résumé
Surcharge d'opérateurs, exceptions, et gestion avancée de l’héritage.

## 🔧 Objectifs
- Surcharger les opérateurs comme `<<`, `=`
- Créer des classes avec hiérarchie complexe
- Gérer les erreurs avec `try/catch` et exceptions personnalisées

## 🛠️ Exercices clés
- **ex00** : Implémentation d’une classe `Animal` avec surcharge d'opérateur
- **ex01** : Création de classes avec exceptions (`Bureaucrat`)
- **ex02** : Hiérarchie de `Form` avec autorisations de signature
- **ex03** : Formulaires spécialisés comme `RobotomyRequestForm`, `PresidentialPardonForm`

## ⚙️ Contraintes
- Exceptions obligatoires pour les cas d'erreurs
- Respect de la forme canonique et des bonnes pratiques de copie

# C++ Module 05

## 📚 Résumé
Exceptions, hiérarchie de classes et signature de formulaires.

## 🔧 Objectifs
- Utiliser des exceptions héritées de `std::exception`
- Créer une hiérarchie logique de classes pour représenter des processus administratifs

## 🛠️ Exercices clés
- **ex00** : Classe `Bureaucrat` avec gestion de grade
- **ex01** : Classe `Form` avec conditions de signature
- **ex02** : Classe `ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm`

## ⚙️ Contraintes
- Manipulation sûre via pointeurs et références
- Gestion précise des exceptions (grade trop haut/bas)

# C++ Module 06

## 📚 Résumé
Conversions de types, sérialisation, et identification dynamique de types.

## 🔧 Objectifs
- Comprendre les conversions implicites et explicites
- Utiliser les `reinterpret_cast`, `static_cast`, `dynamic_cast`
- Identifier des objets dynamiquement à l’exécution

## 🛠️ Exercices clés
- **ex00** : Conversion de types simples (char, int, float, double) via `ScalarConverter`
- **ex01** : Sérialisation d’un objet en `uintptr_t`
- **ex02** : Identification de classes avec `dynamic_cast` via pointeurs et références

## ⚙️ Contraintes
- Aucune allocation dynamique abusive
- Respect de la forme canonique

# C++ Module 07

## 📚 Résumé
Templates de fonctions et de classes, généricité.

## 🔧 Objectifs
- Utiliser des templates pour écrire du code générique
- Appliquer les fonctions templates à différents types

## 🛠️ Exercices clés
- **ex00** : Fonctions templates `swap`, `min`, `max`
- **ex01** : Fonction `iter()` pour appliquer une fonction à chaque élément d’un tableau
- **ex02** : Classe `Array<T>` avec opérateurs et exceptions

## ⚙️ Contraintes
- Gérer les erreurs sur les indices hors limites
- Ne jamais faire de copie non contrôlée

# C++ Module 08

## 📚 Résumé
Découverte de la STL (containers `vector`, `list`, `stack`) et algorithmes.

## 🔧 Objectifs
- Utiliser les conteneurs standards de la STL
- Comprendre les itérateurs et la manipulation de collections

## 🛠️ Exercices clés
- **ex00** : `easyfind()` – recherche d’un élément dans un conteneur
- **ex01** : Classe `Span` – calcul des écarts entre nombres
- **ex02** : `MutantStack` – pile avec itérateurs accessibles

## ⚙️ Contraintes
- Ne jamais provoquer d’accès hors limites
- Utiliser des itérateurs partout où c’est pertinent

# C++ Module 09

## 📚 Résumé
Algorithmes pratiques utilisant la STL.

## 🔧 Objectifs
- Lire et interpréter un fichier CSV avec données financières
- Évaluer des expressions via pile (notation RPN)
- Implémenter un algorithme de tri optimisé Ford-Johnson

## 🛠️ Exercices clés
- **ex00** : `BitcoinExchange` – conversion d’un fichier CSV en valeurs monétaires
- **ex01** : `RPN` – calculatrice avec pile postfixée
- **ex02** : `PmergeMe` – tri avec Ford-Johnson sur `vector` et `deque`

## ⚙️ Contraintes
- Respecter la forme canonique
- Optimiser les performances selon le conteneur

