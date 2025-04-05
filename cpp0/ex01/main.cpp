/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:24:44 by throbert          #+#    #+#             */
/*   Updated: 2025/04/05 10:37:26 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int	main(int ac, char **av)
{
	std::string	input;
	PhoneBook PhoneBook;
	(void) av;

	if (ac != 1)
		return 0;
	std::cout << std::endl  << "	Welcome to the PhoneBook" << std::endl  << std::endl;
	while (true)
	{
		std::cout << ">> ";
		if (!getline(std::cin, input))
			break;
		if (input == "ADD")
			PhoneBook.addContact();
		else if(input == "SEARCH")
			PhoneBook.searchContact();
		else if(input == "EXIT")
			break;
	}
	return 0;
}
