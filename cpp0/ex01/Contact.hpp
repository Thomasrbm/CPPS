/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:24:52 by throbert          #+#    #+#             */
/*   Updated: 2025/04/26 00:44:03 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
public:
	Contact();
	~Contact();
	void displayLine(int index);
	void setContact();
	void display_fullContact();
	bool isSet() const;
	void autoSetContacts();

private:
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phonenumber;
	std::string darksecret;
	bool 		is_set;
};
