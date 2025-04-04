/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:24:52 by throbert          #+#    #+#             */
/*   Updated: 2025/04/04 21:47:34 by throbert         ###   ########.fr       */
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
	Contact(const Contact &);
	Contact &operator=(const Contact &);
	~Contact();
	void setFirstname(std::string firstname);
	void setLastname(std::string lastname);
	void setNickname(std::string nickname);
	void setPhonenumber(std::string phonenumber);
	void setDarksecret( std::string darksecret);
	void displayLine(int index);
	void setContact();

private:
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phonenumber;
	std::string darksecret;
};
