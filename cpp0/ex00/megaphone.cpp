/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 22:08:32 by throbert          #+#    #+#             */
/*   Updated: 2025/04/25 22:08:46 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else if (ac > 1)
	{
		int i = 1;
		while (av[i])
		{
			int j = 0;
			while (av[i][j])
			{
				if (isalpha(av[i][j]))
					av[i][j] = toupper(av[i][j]);
				std::cout << av[i][j];
				j++;
			}
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}
