/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanani-f <lanani-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 21:24:57 by lizzieanani       #+#    #+#             */
/*   Updated: 2025/02/13 10:26:43 by lanani-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream> // Pour utiliser les entrées/sorties (cin, cout, endl)
#include <iomanip> // Pour formater l'affichage (setw pour définir la largeur)
#include <time.h> // Pour manipuler les dates et heures, notamment pour horodater

// Variables statiques de la classe Account :

int Account::_nbAccounts = 0;
//  _nbAccounts : Nombre total de comptes créés.
int Account::_totalAmount = 0;
//  _totalAmount : Somme totale de tous les soldes des comptes.
int Account::_totalNbDeposits = 0;
//  _totalNbDeposits : Nombre total de dépôts effectués sur tous les comptes.
int Account::_totalNbWithdrawals = 0;
//  _totalNbWithdrawals : Nombre total de retraits effectués sur tous les comptes.

void Account::_displayTimestamp(void)
{
    time_t rawtime;
    struct tm* timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    
    std::cout << "["
              // Début du formatage de l'affichage   
              << std::setfill('0') << std::setw(4) << timeinfo->tm_year + 1900
              << std::setfill('0') << std::setw(2) << timeinfo->tm_mon + 1
              << std::setfill('0') << std::setw(2) << timeinfo->tm_mday
              << "_"
              // Séparateur entre la date et l'heure  
              << std::setfill('0') << std::setw(2) << timeinfo->tm_hour
              << std::setfill('0') << std::setw(2) << timeinfo->tm_min
              << std::setfill('0') << std::setw(2) << timeinfo->tm_sec
              << "] ";
              // Fin du formatage avec fermeture du crochet 
}

Account::Account(int initial_deposit)
// Constructeur : Account
// Rôle : Initialise un nouveau compte avec un dépôt initial.
{
    _accountIndex = _nbAccounts++;
    // Assigne l'index du compte et incrémente le nombre total de comptes  
    _amount = initial_deposit;
    // Initialise le montant du compte avec le dépôt initial  
    _nbDeposits = 0;
    // Initialise le nombre de dépôts à 0
    _nbWithdrawals = 0;
    // Initialise le nombre de retraits à 0
    _totalAmount += initial_deposit;
    // Ajoute le dépôt initial au total des montants de tous les comptes  

    _displayTimestamp();
    // Affiche l'horodatage de la création du compte
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
    // Affiche les infos du compte  

}

Account::~Account(void)
// Destructeur : ~Account
// Rôle : Gère la fermeture d'un compte.
{
    _displayTimestamp();
    // Affiche l'horodatage de la fermeture du compte  
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
    // Affiche les infos du compte avant sa destruction  
}

// Méthodes statiques pour récupérer les statistiques globales
int Account::getNbAccounts(void) { return _nbAccounts; }
// Retourne le nombre total de comptes.
int Account::getTotalAmount(void) { return _totalAmount; }
// Retourne le montant total détenu par tous les comptes.
int Account::getNbDeposits(void) { return _totalNbDeposits; }
// Retourne le nombre total de dépôts effectués.
int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }
// Retourne le nombre total de retraits effectués.


void Account::displayAccountsInfos(void)
// Fonction statique : displayAccountsInfos
// Rôle : Affiche les statistiques globales de tous les comptes.
{
    _displayTimestamp();
    // Affiche l'horodatage de l'affichage des infos des comptes  
    std::cout << "accounts:" << _nbAccounts
              // Affiche le nombre total de comptes  
              << ";total:" << _totalAmount
              // Affiche le montant total de tous les comptes
              << ";deposits:" << _totalNbDeposits
              // Affiche le nombre total de dépôts 
              << ";withdrawals:" << _totalNbWithdrawals << std::endl;
              // Affiche le nombre total de retraits  
}


void Account::makeDeposit(int deposit)
// Méthode : makeDeposit
// Rôle : Effectue un dépôt sur le compte actuel.
{
    _displayTimestamp();
    // Affiche l'horodatage de l'opération 
    std::cout << "index:" << _accountIndex
              // Affiche l'index du compte  
              << ";p_amount:" << _amount
              // Affiche le montant avant le dépôt 
              << ";deposit:" << deposit;
              // Affiche le montant du dépôt
    
    _amount += deposit;
    // Ajoute le dépôt au montant du compte
    _nbDeposits++;
    // Incrémente le nombre de dépôts du compte 
    _totalAmount += deposit;
    // Met à jour le montant total de tous les comptes  
    _totalNbDeposits++;
    // Incrémente le nombre total de dépôts

    std::cout << ";amount:" << _amount
              // Affiche le montant après le dépôt
              << ";nb_deposits:" << _nbDeposits << std::endl;
              // Affiche le nombre total de dépôts du compte 
}


bool Account::makeWithdrawal(int withdrawal)
// Méthode : makeWithdrawal
// Rôle : Effectue un retrait sur le compte actuel.
{
    _displayTimestamp();
    // Affiche l'horodatage de l'opération
    std::cout << "index:" << _accountIndex
              // Affiche l'index du compte  
              << ";p_amount:" << _amount
              // Affiche le montant avant le retrait
              << ";withdrawal:";
              // Prépare l'affichage du montant du retrait
    
    if (_amount < withdrawal) 
    // Vérifie si le retrait est possible
    {
        std::cout << "refused" << std::endl;
        // Indique que le retrait est refusé 
        return false;
        // Retourne false car fonds insuffisants  
    }
    
    _amount -= withdrawal;
    // Déduit le montant du retrait du compte
    _nbWithdrawals++;
    // Incrémente le nombre de retraits du compte 
    _totalAmount -= withdrawal;
    // Met à jour le montant total de tous les comptes  
    _totalNbWithdrawals++;
    // Incrémente le nombre total de retraits

    std::cout << withdrawal 
              // Affiche le montant du retrait effectué  
              << ";amount:" << _amount
              // Affiche le montant après retrait
              << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
              // Affiche le nombre total de retraits du compte
    return true;
    // Retourne true car le retrait a été effectué
}


int Account::checkAmount(void) const
// Méthode : checkAmount
// Rôle : Retourne le montant actuel du compte.
{
    return _amount;
}


void Account::displayStatus(void) const
// Méthode : displayStatus
// Rôle : Affiche l'état actuel du compte (index, montant, dépôts et retraits).
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals << std::endl;
}