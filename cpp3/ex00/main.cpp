/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:46:36 by throbert          #+#    #+#             */
/*   Updated: 2025/05/04 23:51:22 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap JoKo("JoKo");
    ClapTrap Koooooooooooooooooooooooooooooooooko("Koooooooooooooooooooooooooooooooooko");

    JoKo.attack(Koooooooooooooooooooooooooooooooooko.getName());
    JoKo.setAttack(1);
    
    std::cout << std::endl << std::endl;

    for (int i = 0; i < 11; i++)
    {
        JoKo.attack(Koooooooooooooooooooooooooooooooooko.getName());
        Koooooooooooooooooooooooooooooooooko.takeDamage(JoKo.getAttack()); // took 1 dmg de trop car pour l instant pas de communication entres les ClapTrap.
    }
    JoKo.beRepaired(1);
    Koooooooooooooooooooooooooooooooooko.attack(JoKo.getName());

    std::cout << std::endl << std::endl;
    
    ClapTrap TEST("TEST");
    ClapTrap OTHER_TEST("OTHER_TEST");
    TEST.attack(OTHER_TEST.getName());
    OTHER_TEST.takeDamage(TEST.getAttack());

    OTHER_TEST.beRepaired(1);
    TEST.beRepaired(1);
    
    return 0;
}