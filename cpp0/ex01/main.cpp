/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:24:44 by throbert          #+#    #+#             */
/*   Updated: 2025/04/25 23:54:22 by throbert         ###   ########.fr       */
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
		if (!getline(std::cin, input)) // flux d entree + string ou stocker le result
			break;
		if (input == "ADD")
			PhoneBook.addContact();
		else if(input == "SEARCH")
			PhoneBook.searchContact();
		else if(input == "EXIT")
			break;
		else if(input == "FILL")
			PhoneBook.autoFill();
	}
	return 0;
}
