/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:05:43 by throbert          #+#    #+#             */
/*   Updated: 2025/04/04 21:45:32 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"

// les publique : vont modif le private selon des regles etablit par moi donc pas 
// de pb.
//
// les private ne doivent pas etre modif sans passer par les publique
// si non private on pourrait modif la taille de contact, ou alouer contact count
// alors que seul le fait d add un contact l incremente et rien d autre. 
class PhoneBook
{
public:
	PhoneBook();
	PhoneBook(const PhoneBook &other); 
	PhoneBook &operator=(const PhoneBook &other);
	~PhoneBook();
	void	searchContact();
	void	addContact();
	void	display();

private:
	Contact contact[8];
	int		contacts_count;
};
