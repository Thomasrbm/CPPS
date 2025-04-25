/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:24:46 by throbert          #+#    #+#             */
/*   Updated: 2025/04/25 23:57:46 by throbert         ###   ########.fr       */
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
		contact[i].displayLine(i + 1); // la obliger de mettre un '.' car une methode de contact.
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
		if (input.length() != 1) // lenght c est un strlen, ou plutot ca lit une variable qui contient la taille. : c est un getter.
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
	if (!getline(std::cin, input))
		return;
	if (!is_index(input))
	{
		std::cout << std::endl << "/!\\ Not a valid index ! /!\\" << std::endl << std::endl;
		return;
	}
	index = std::atoi(input.c_str()) - 1;
	if (!contact[index].isSet())
	{
		std::cout << std::endl << "/!\\ Contact of this index is not set /!\\" << std::endl << std::endl;
		return;
	}
	else
		contact[index].displayContact();
}

void PhoneBook::addContact()
{
	if (contacts_count == 0)
		oldest_index = 1;
	if (contacts_count > 8)
	{
		contact[contacts_count].setContact();
		oldest_index++;
	}
	else
		contact[contacts_count].setContact();
	if (contacts_count < 8)
		contacts_count++;
}

// faire apres les 2 points ca evite que le programme cree d abord a null puis allou
// (c est ce qui se passe entre les accollade)
PhoneBook::PhoneBook() :
	contacts_count(0)
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
