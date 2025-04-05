/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:24:46 by throbert          #+#    #+#             */
/*   Updated: 2025/04/05 10:28:08 by throbert         ###   ########.fr       */
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
		contact[i].displayLine(i);
	}
	std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;

}

void PhoneBook::searchContact()
{
	std::string	input;

	display();
	std::cout << "Enter an index : ";
	if (!getline(std::cin, input))
		return; 
	
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
