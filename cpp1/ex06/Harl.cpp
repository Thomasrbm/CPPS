/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 22:01:38 by throbert          #+#    #+#             */
/*   Updated: 2025/04/30 22:44:41 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// en cpp et c les methode/fonctions ont une adresse.
// on peut faire des tableau de methode

void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"}; // Niveau acceptes.

	// pointeur de fonctions.
	void (Harl::*functions[4])() =  // tab de methode   Harl::* pas deferencement mais pointeur vers une fonction. ici plusieur.
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	int i = 0;
	while (i < 4 && levels[i] != level) // parcours les mots acceptes et compare avec celui donne (s arrete juste avant 4 car 4 mot 0, 1 , 2 ,3)
		i++;
	if (i == 4) // non trouvé (part de 0 et pas trouver la string demande au prompt)
	{
		std::cerr << "Error: level must be DEBUG, INFO, WARNING or ERROR\n";
		return;
	}

	// Appelle du début jusqu’au niveau i
	for (int j = 0; j <= i; j++)
		(this->*functions[j])(); // appel chaque fonction du tab de methode dans l ordre.
							// this car fonction membre
}


// void foo(). ft libre				--> pointeur   void (*pf)() = &foo;


// void Harl::debug() methode       --> pointeur  void (Harl::*pmf)() = &Harl::debug;



void	Harl::debug( void )
{
	std::cout << "This is a debugging message with contextual information." << std::endl;
}

void	Harl::info( void )
{
	std::cout << "This is an informational message with extensive information." << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "This is a warning indicating a potential issue." << std::endl;
}

void	Harl::error( void )
{
	std::cout << "This is an error message indicating that an unrecoverable error has occurred." << std::endl;
}

Harl::Harl()
{
}

Harl::~Harl()
{
}