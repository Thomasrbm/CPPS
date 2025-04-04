/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:24:44 by throbert          #+#    #+#             */
/*   Updated: 2025/04/04 09:25:26 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int	main(int ac, char **av)
{
	std::string	input;

	while (true)
	{
		std::cout << "PhoneBook :";
		if (!getline(std::cin, input))
			break;
		if (input == "ADD")
			PhoneBook.addContact();
		else if(input == "SEARCH")
			PhoneBook.searchContact();
		else if(input == "EXIT")
			break;
		else
			std::cout << std::endl;
	}
	return 0;
}
