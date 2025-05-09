/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 19:01:47 by throbert          #+#    #+#             */
/*   Updated: 2025/05/09 03:54:07 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap test("test");
	ClapTrap other_test("other_test");
	ScavTrap Kash("Kash");
	ScavTrap Johny("Johny");

	std::cout << std::endl << std::endl << "=================================================================" << std::endl << std::endl;
	std::cout << std::endl << std::endl;
	std::cout << "See the overload of attack function : " << std::endl <<std::endl;;
	
	std::cout  << std::endl << "current attack of Kash : " << Kash.getAttack() << std::endl;
	std::cout  << "current life of Johny : " << Kash.getLife() << std::endl  << std::endl;

	std::cout << "====> ";
	Kash.attack(Johny.getName());
	Johny.takeDamage(Kash.getAttack());
	Kash.setEnergy(50);
	Johny.setEnergy(50);

	std::cout << std::endl << std::endl;

	test.setAttack(1);
	std::cout << "====> ";
	test.attack(other_test.getName());
	other_test.takeDamage(test.getAttack());
	test.setEnergy(10);
	other_test.setEnergy(10);
	

	std::cout << std::endl << std::endl << "=================================================================" << std::endl << std::endl;
	std::cout << std::endl << std::endl;
	std::cout << "See that 50 energy max : " << std::endl <<std::endl;;


	for (int i = 1; i <= 51; i++)
	{
		std::cout << "i = " << i << std::endl;
		std::cout << "Energy of Kash : " << Kash.getEnergy_point() << std::endl;
		Kash.attack(Johny.getName());
		Johny.takeDamage(Kash.getAttack());
		Johny.beRepaired(30);
		std::cout << std::endl;
	}
	
	std::cout << std::endl << std::endl << "=================================================================" << std::endl << std::endl;
	std::cout << std::endl << std::endl;
	test.setAttack(1);
	std::cout << "See that claptrap still has 10 energy point : " << std::endl <<std::endl;;

	
	
	for (int i = 1; i <= 11; i++)
	{
		std::cout << "i = " << i << std::endl;
		std::cout << "Energy of test : " << test.getEnergy_point() << std::endl;
		test.attack(other_test.getName());
		other_test.takeDamage(test.getAttack());
		other_test.beRepaired(1);
		std::cout << std::endl;
	}

	std::cout  << std::endl << "=================================================================" << std::endl << std::endl;
	std::cout << std::endl << std::endl;
	std::cout << "See that beRepaired only set to max health and no more : " << std::endl <<std::endl;
	Kash.setEnergy(100);
	Johny.setEnergy(100);
	std::cout << std::endl;
	std::cout  << "current life of Johny : " << Johny.getLife() << std::endl  << std::endl;
	std::cout << "try to repair 100 lp.  80 + 100 = 180. Here just recover 20 lp." << std::endl << std::endl;
	Johny.beRepaired(100);

	std::cout  << std::endl << "=================================================================" << std::endl << std::endl;
	std::cout << std::endl << std::endl;
	std::cout  << "current life of Johny : " << Johny.getLife() << std::endl  << std::endl;
	std::cout << "See that cannot go below 0 HP: " << std::endl << std::endl << std::endl;

	

	for (int i = 1; i <= 6; i++)
	{
		std::cout << "i = " << i << std::endl;
		std::cout << "Life of Johny : " << Johny.getLife() << std::endl;
		Kash.attack(Johny.getName());
		Johny.takeDamage(Kash.getAttack());
		std::cout << "Life of Johny is now of : " << Johny.getLife() << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl;

	std::cout  << std::endl << "=================================================================" << std::endl << std::endl;
	std::cout << std::endl << std::endl;
	std::cout << "See the guarded mode : " << std::endl <<std::endl;

	Kash.guardGate();
	Kash.guardGate();
	std::cout << std::endl << std::endl;
	// test.guardGate();
	
	return 0;
}
