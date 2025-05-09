/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 05:59:20 by throbert          #+#    #+#             */
/*   Updated: 2025/04/30 23:19:24 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int N = 5;
	Zombie *horde = zombieHorde(N, "Zombo");

	for (int i = 0; i < N; ++i)
		horde[i].announce();

	delete[] horde; // detruit tout qq soit le nombre de cases
	return 0;
}
