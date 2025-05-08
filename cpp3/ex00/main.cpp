/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:46:36 by throbert          #+#    #+#             */
/*   Updated: 2025/05/08 18:27:48 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap JoKo("JoKo");
	ClapTrap Koooooooooooooooooooooooooooooooooko("Koooooooooooooooooooooooooooooooooko");
	
	std::cout << std::endl << std::endl;
	std::cout << " At start no damage has been set : " << std::endl <<std::endl;;
	
	JoKo.attack(Koooooooooooooooooooooooooooooooooko.getName());
	std::cout << std::endl;
	JoKo.setAttack(1);


	std::cout << std::endl << std::endl << "=================================================================" << std::endl << std::endl;
	std::cout << std::endl << std::endl;
	std::cout << " When no energy/hit point FOR take damage(when dead) / attack(no energy): " << std::endl <<std::endl;;

	for (int i = 0; i < 11; i++)
	{
		std::cout << "i = " << i << std::endl;
		std::cout << "Energy of JoKo : " << JoKo.getEnergy_point() << std::endl;
		std::cout << "Hit_points of Koooooooooooooooooooooooooooooooooko : " << Koooooooooooooooooooooooooooooooooko.getLife() << std::endl;
		JoKo.attack(Koooooooooooooooooooooooooooooooooko.getName());
		Koooooooooooooooooooooooooooooooooko.takeDamage(JoKo.getAttack());
		std::cout << std::endl;
	}

	std::cout << std::endl << std::endl << "=================================================================" << std::endl << std::endl;
	std::cout << std::endl << std::endl;
	std::cout << " When no energy/hit point FOR repair / attack(when dead) : " << std::endl <<std::endl;;
	
	std::cout << "Joko energy = " << JoKo.getEnergy_point() << std::endl;
	std::cout << "Koooooooooooooooooooooooooooooooooko life = " << Koooooooooooooooooooooooooooooooooko.getLife() << std::endl;


	std::cout << std::endl << std::endl;
	JoKo.beRepaired(1);
	Koooooooooooooooooooooooooooooooooko.attack(JoKo.getName());

	std::cout << std::endl << std::endl << "=================================================================" << std::endl << std::endl;
	std::cout << std::endl << std::endl;
	std::cout << " When already fully alive : " << std::endl << std::endl << std::endl;


	ClapTrap TEST("TEST");
	ClapTrap OTHER_TEST("OTHER_TEST");

	std::cout << std::endl << std::endl;
	
	TEST.setAttack(1);
	OTHER_TEST.takeDamage(TEST.getAttack());

	std::cout << std::endl;
	
	OTHER_TEST.beRepaired(1);
	TEST.beRepaired(1);

	return (0);
}
