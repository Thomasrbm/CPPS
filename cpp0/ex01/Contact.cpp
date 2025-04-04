/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:24:50 by throbert          #+#    #+#             */
/*   Updated: 2025/04/04 22:09:54 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// pas besoin de return
// this modifie comme un pointeur vers la variable de l objet creer ( a partir de la classe)
// on envoit les param qu on veut donner
// on modifie direct ici pas de return;

void Contact::setFirstname(std::string firstname)
{
	this->firstname = firstname;
}

void Contact::setLastname(std::string lastname)
{
	this->lastname = lastname;
}

void Contact::setNickname(std::string nickname)
{
	this->nickname = nickname;
}

void Contact::setPhonenumber(std::string phonenumber)
{
	this->phonenumber = phonenumber;	
}

void Contact::setDarksecret(std::string darksecret)
{
	this->darksecret = darksecret;	
}

// return un string qui sarrette a 10char et put a point 
// si plus de 10char.
static std::string	format_field(std::string input)
{
	std::string result;

	for (int i = 0; input[i];)
	{
		if (i > 10)
		{
			result[i] = '.';
			break;
		}
		result[i] = input[i];
		i++;
	}
	return (result);
}

// setw = set width
// force largeur du champ a 10.
// affiche le truc qui vient juste apres a droite
// s applique que pour un input a la fois
void Contact::displayLine(int index)
{
	std::cout << "│" << std::setw(10) << index
			  << "│" << std::setw(10) << format_field(this->firstname) // PAS BESOIN DE THIS ICI ???????????
			  << "│" << std::setw(10) << format_field(this->lastname) 
			  << "│" << std::setw(10) << format_field(this->nickname)
			  << "│" << std::endl;
}

// le fait de mettre tout avant les {}, ca veut dire :
// assigne des la creation, et pas cree a valeur aleatoire puis reassigne.
// pas oublier le : et les , 
Contact::Contact() :
	firstname(""),
	lastname(""),
	nickname(""),
	phonenumber(""),
	darksecret("")
{}

int is_phone_number(std::string phone_number)
{
	for (int i = 0; phone_number[i]; i++)
	{
		if (phone_number[i] < '0' || phone_number[i] > '9')
			return 0;
	}	
	return 1;
}

static int isempty(std::string input)
{
	int j = 0;
	int i = 0;

	while (input[i])
	{
		if (isspace(input[i]))
			j++;
		i++;
	}
	if (j == i)
	{
		std::cout << std::endl << "/!\\ No empty field admitted ! /!\\" << std::endl << std::endl;
		return 1;
	}
	return 0;
}

void Contact::setContact()
{
	std::string	input;

	std::cout << "firstname : ";
	if (!getline(std::cin, input))
		return;
	if (isempty(input))
		return;
	else
		this->firstname = input;
	std::cout << "lastname : ";
	if (!getline(std::cin, input))
		return;
	if (isempty(input))
		return;
	else
		this->lastname = input;
	std::cout << "nickname : ";
	if (!getline(std::cin, input))
		return;
	if (isempty(input))
		return;
	else
		this->nickname = input;
	std::cout << "phone number : ";
	if (!getline(std::cin, input))
		return;
	if (!is_phone_number(input))
		return;
	if (isempty(input))
		return;
	else
		this->phonenumber = input;
	std::cout << "dark secret : ";
	if (!getline(std::cin, input))
		return;
	if (isempty(input))
		return;
	else
		this->darksecret = input;
}

Contact::Contact(const Contact &other)
{
	*this = other;
}

Contact &Contact::operator=(const Contact &other)
{
	if (this != &other) {
		this->firstname = other.firstname;
		this->lastname = other.lastname;
		this->nickname = other.nickname;
		this->phonenumber = other.phonenumber;
		this->darksecret = other.darksecret;
	}
	return *this;
}

Contact::~Contact() 
{}
