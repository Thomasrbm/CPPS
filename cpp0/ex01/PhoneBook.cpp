/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:24:46 by throbert          #+#    #+#             */
/*   Updated: 2025/04/04 22:06:25 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::display()
{
	std::cout << "┌──────────┬──────────┬──────────┬──────────┐\n";
	std::cout << "│   Index  │First Name│ Last Name│ Nickname │\n";
	std::cout << "├──────────┼──────────┼──────────┼──────────┤\n";
	for (int i = 0; i < PhoneBook::contacts_count; i++)
		contact[i].displayLine(i);
	std::cout << "└──────────┴──────────┴──────────┴──────────┘\n";

}

void PhoneBook::searchContact()
{
	std::string	input;

	display();
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
