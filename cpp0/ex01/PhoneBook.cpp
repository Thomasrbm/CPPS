/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:24:46 by throbert          #+#    #+#             */
/*   Updated: 2025/04/05 13:40:00 by throbert         ###   ########.fr       */
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
		contact[i].displayLine(i + 1);
	}
	std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;

}

static int is_index(std::string	input)
{
	for (int i = 0; i <= 2; i++)
	{
		if (input[i] >= '1' && input[i] <= '8')
			return 1;
	}
	return 0;
}

void PhoneBook::searchContact()
{
	std::string	input;
	int index;
	
	display();
	std::cout << "Enter an index : ";
	if (!getline(std::cin, input))
		return;
	index = std::atoi(input.c_str()) - 1;
	if (!is_index(input))
	{
		std::cout << std::endl << "/!\\ Not an index ! /!\\" << std::endl << std::endl;
		return;
	}
	else if (!contact[index].isSet())
	{
		std::cout << std::endl << "/!\\ Contact of this index is not set /!\\" << std::endl << std::endl;
		return;
	}
	else
		contact[index].displayContact();
}
void PhoneBook::addContact()
{
	contact[contacts_count].setContact();
	
	this->contacts_count++;
}

PhoneBook::PhoneBook() :
	contacts_count(0)
{}


PhoneBook &PhoneBook::operator=(const PhoneBook &other)
{
	if (this != &other) {
		this->contact[8] = other.contact[8];
		this->contacts_count = other.contacts_count;
	}
	return *this;
}

PhoneBook::~PhoneBook() 
{}
