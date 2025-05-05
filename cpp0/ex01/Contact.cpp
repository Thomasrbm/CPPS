/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:24:50 by throbert          #+#    #+#             */
/*   Updated: 2025/05/02 17:32:13 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// pas besoin de return
// this modifie comme un pointeur vers la variable de l objet creer ( a partir de la classe)
// on envoit les param qu on veut donner
// on modifie direct ici pas de return;

bool Contact::isSet() const  // const veut dire que cette fonction ne peut pas modifier la classe (genre this->firstname = ...), just un getter.
{
	return is_set;
}

void Contact::display_fullContact()
{
	std::cout << "firstname : " << firstname << std::endl;
	std::cout << "lastname : " << lastname << std::endl;
	std::cout << "nickname : " << nickname << std::endl;
	std::cout << "phone number : " << phonenumber << std::endl;
	std::cout << "dark secret : " << darksecret << std::endl;
}

// return un string qui sarrette a 10char et put a point 
// si plus de 10char.
static std::string	format_field(std::string input)
{
	std::string result;

	for (int i = 0; input[i];)
	{
		if (i >= 9)
		{
			result += '.';   // ajoute en fin de chaine directement sans index
			break;
		}
		result += input[i];
		i++;
	}
	return (result);
}

// setw = set width
// force largeur du champ a 10.
// affiche le truc qui vient juste apres a droite
// s applique que pour un input a la fois
//
// s ecrit par la droite 
void Contact::displayLine(int index)
{
	std::cout << "│" << std::setw(10) << index
			  << "│" << std::setw(10) << format_field(firstname)
			  << "│" << std::setw(10) << format_field(lastname) 
			  << "│" << std::setw(10) << format_field(nickname)
			  << "│" << std::endl;
}

int is_phone_number(std::string phone_number)
{
	for (int i = 0; phone_number[i]; i++)
	{
		if (isspace(phone_number[i]))
			continue; // ca cut le for la ou il est pour reprendre le for du debut pour le i++ suivant
		if (phone_number[i] < '0' || phone_number[i] > '9')
		{
			std::cout << std::endl << "/!\\ Not a phone number ! /!\\" << std::endl << std::endl;
			return 0;
		}
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

void Contact::autoSetContacts()
{
        firstname = "FirstName777";
        lastname = "LastName777";
        nickname = "NickName777";
        phonenumber = "777777777";
        darksecret = "DarkSecret777";
		is_set = 1;
}

void Contact::setContact()
{
	std::string	input;

	std::cout << "firstname: ";
	while (getline(std::cin, input) && isempty(input))
		std::cout << "firstname: ";
	this->firstname = input;
	
	std::cout << "lastname: ";
	while (getline(std::cin, input) && isempty(input))
		std::cout << "lastname: ";
	this->lastname = input;
	
	std::cout << "nickname: ";
	while (getline(std::cin, input) && isempty(input))
		std::cout << "nickname: ";
	this->nickname = input;
	
	std::cout << "phone number: ";
	while (getline(std::cin, input) && (isempty(input) || !is_phone_number(input)))
		std::cout << "phone number: ";
	this->phonenumber = input;
	
	std::cout << "dark secret: ";
	while (getline(std::cin, input) && isempty(input))
		std::cout << "dark secret: ";
	this->darksecret = input;
	
	this->is_set = true;
}


// le fait de mettre tout avant les {}, ca veut dire :
// assigne des la creation, et pas cree a valeur aleatoire puis reassigne.
// pas oublier le : et les , 
Contact::Contact() :
	firstname(""),
	lastname(""),
	nickname(""),
	phonenumber(""),
	darksecret(""),
	is_set(false)
{
}

Contact::~Contact() 
{
}
