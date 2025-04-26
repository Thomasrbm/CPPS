/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:24:46 by throbert          #+#    #+#             */
/*   Updated: 2025/04/26 00:57:49 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::display()
{
	std::cout << "┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
	std::cout << "│   Index  │First Name│ Last Name│ Nickname │" << std::endl;
	for (int i = 0; i < PhoneBook::contacts_count; i++)
	{
		std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
		contact[i].displayLine(i + 1); // la obliger de mettre un '.' car une methode de contact.    +1 car pour pas afficher le premier a 0
	}
	std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;
}

// VERIF QUE INDEX VALID ENTRE 1 ET 8.

// le . vient pour appeler les fonction de variable appartenant avec une methode.
// je cree la variable de type std::string (methode , string est la methode comme phonebook).
// j appel donc la fonction de la methode string.
static int is_index(std::string	input)
{
	for (int i = 0; i <= 2; i++)
	{
		if (input.length() != 1) // lenght c est un strlen, ou plutot ca lit une variable qui contient la taille. : c est un getter. (pour savoir si juste 1 de taille)
			return 0;
		if (input[i] >= '1' && input[i] <= '8')
			return 1;
	}
	return 0;
}

void PhoneBook::searchContact()
{
	std::string	input;
	int index;
	
	display(); // je suis deja dans une fonction de classe phonebook donc pas besoin de .
	std::cout << "Enter an index : ";
	if (!getline(std::cin, input)) // pour chopper l entree, le return sort de la recherche d index
		return;
	if (!is_index(input))
	{
		std::cout << std::endl << "/!\\ Not a valid index ! /!\\" << std::endl << std::endl;
		return;
	}
	index = std::atoi(input.c_str()) - 1; // c str = cast en const en gros (pour le atoi)
	if (!contact[index].isSet())
	{
		std::cout << std::endl << "/!\\ Contact of this index is not set /!\\" << std::endl << std::endl;
		return;
	}
	else
		contact[index].display_fullContact(); // besoin d index car tableau
}

void PhoneBook::addContact()
{
    // On écrit dans la case oldest_index
    contact[oldest_index].setContact();

    // On avance oldest_index en boucle [0..7]
    this->oldest_index = (oldest_index + 1) % 8; // avance l oldest au suivant et mod 8 garde entre 0 et 7 + 1 pour avoir le bon index.

    // On compte jusqu’à 8 max
    if (contacts_count < 8)
        contacts_count++;
}

// faire apres les 2 points ca evite que le programme cree d abord a null puis allou
// (c est ce qui se passe entre les accollade)
PhoneBook::PhoneBook() :
	contacts_count(0),  // mit a 0 car tableau de contact
	oldest_index(0)
{
}

PhoneBook::~PhoneBook() 
{
}

void PhoneBook::autoFill()
{
	for (int i = 0; i < 8; i++)
	{
		contact[i].autoSetContacts();  // Remplir chaque contact avec les valeurs définies dans autoSetContacts
	}
	this->contacts_count = 8;  // Indique que tous les contacts sont remplis
}
