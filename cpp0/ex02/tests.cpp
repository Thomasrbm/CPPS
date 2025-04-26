// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"


// chaque ft écrit dans la stdout si on redirige ca ecrirat le meme ficiher.


// VECTOR = tab dynamique qui prend n importe quel type donne en <>
int		main( void ) {
																		// std::vector s alloue tout seul
																		// peut créer tab vide a alouer avec fonction pushback
																		// peut std::vector<int> tab(5, 42); va crée   5 case alouer toutes a 42

																		// int arr[] = {1, 2, 3}; : allou le tableau

																	 // std::vector<int> v(arr, arr + 3): declare tableau de 3 case

																	 // si prend tab existant et donne debut et fin va y mettre toutes valeur du tab.

	// definit un type de tab dynamique d account
	typedef std::vector<Account::t>							  accounts_t;  // std::vector = tab dyna. account::t = methode alias de account. La ligne veut dire , je cree un type qui est un tableau d account dynamique avec pour alias account_t
	// d int
	typedef std::vector<int>								  ints_t; // type pour un tab dynamiaue d int 
	// une pair d iterateur (diff des index)
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t; // cree une paire d iterateur. c pas un index(un pointeur pas un chiffre, plus sur, moins de risaue de dépassements.)

	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 }; // solde inituayx sur les 8 comptes
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) ); // donne le nombre de compte   sizeof(amounts) = 8 x 4(taille int) / sizeof(int) ) = 8
	accounts_t				accounts( amounts, amounts + amounts_size ); // je cree les accounts_t qui est un tableau d acount avec pour l instant des valeurs.
						// donc on construit au début en donnant que les amounts de dépot initiaux. reste à 0. 
						// 
						// va creer le tab et allouer du debut (0 = 42 a 7 = 16576)

	accounts_t::iterator	acc_begin	= accounts.begin(); // begin et end sont de vector pointeur vers 1er et dernier.
	accounts_t::iterator	acc_end		= accounts.end();

	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 }; // les montants a depot sur chaque compte
	size_t const		d_size( sizeof(d) / sizeof(int) ); // 8 depots
	ints_t				deposits( d, d + d_size ); // tab d int avec les depots
	ints_t::iterator	dep_begin	= deposits.begin();
	ints_t::iterator	dep_end		= deposits.end();

	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 }; // retraits.
	size_t const		w_size( sizeof(w) / sizeof(int) );
	ints_t				withdrawals( w, w + w_size );
	ints_t::iterator	wit_begin	= withdrawals.begin();
	ints_t::iterator	wit_end		= withdrawals.end();

	Account::displayAccountsInfos(); // affiche le total de compte et d argent + nb depot et retraits
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) ); // va de account 0 a 7 et applique avec mem fun ref(appel methode sur chqaue) le display de chaque compte

	for ( acc_int_t it( acc_begin, dep_begin ); // declar les deux pointeur , un pour account et 1 pour depots , on parcours les deux tab en meme temps avec chqaue.
		  it.first != acc_end && it.second != dep_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeDeposit( *(it.second) ); // pointe sur l account et applique makedeposit de la valeur du depot pointe 
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, wit_begin ); // 
		  it.first != acc_end && it.second != wit_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeWithdrawal( *(it.second) );
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	return 0;
}


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //
