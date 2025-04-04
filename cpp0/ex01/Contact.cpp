/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:24:50 by throbert          #+#    #+#             */
/*   Updated: 2025/04/04 17:17:51 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// pas besoin de return
// this modifie comme un pointeur vers la variable de l objet creer ( a partir de la classe)
// on envoit les param qu on veut donner
// on modifie direct ici pas de return;
void	Contact::setContact(std::string firstname, std::string lastname,
		std::string nickname, std::string phonenumber, std::string darksecret)
{
	this->firstname = firstname;
	this->lastname = lastname;
	this->nickname = nickname;
	this->phonenumber = phonenumber;
	this->darksecret = darksecret;
}

// setw = set width
// force largeur du champ a 10.
// affiche le truc qui vient juste apres a droite
// s applique que pour un input a la foit
void Contact::displayLine(int index)
{
	std::cout << "|" << std::setw(10) << index
			  << "|" << std::setw(10) << formatField(this->firstname)
			  << "|" << std::setw(10) << formatField(lastname)
			  << "|" << std::setw(10) << formatField(nickname)
			  << "|" << std::endl;
}
