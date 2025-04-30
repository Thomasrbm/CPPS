/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 22:45:53 by throbert          #+#    #+#             */
/*   Updated: 2025/04/30 22:52:27 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	void (Harl::*functions[4])() = 
    {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	int i = 0;
	while (i < 4 && levels[i] != level)
		i++;
	if (i == 4)
	{
		std::cerr << "Error: level must be DEBUG, INFO, WARNING or ERROR\n";
		return;
	}
	(this->*functions[i])();
}

void	Harl::debug( void )
{
	std::cout << "This is a debugging message with contextual information." << std::endl;
}

void	Harl::info( void )
{
	std::cout << "This is an informational message with extensive information." << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "This is a warning indicating a potential issue." << std::endl;
}

void	Harl::error( void )
{
	std::cout << "This is an error message indicating that an unrecoverable error has occurred." << std::endl;
}

Harl::Harl()
{
}

Harl::~Harl()
{
}