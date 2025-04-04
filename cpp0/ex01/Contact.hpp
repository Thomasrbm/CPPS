/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:24:52 by throbert          #+#    #+#             */
/*   Updated: 2025/04/04 17:08:45 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
public:
	void setContact(std::string firstname, std::string lastname,
		std::string nickname, std::string phonenumber, std::string darksecret);
	void display();

private:
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phonenumber;
	std::string darksecret;
}
