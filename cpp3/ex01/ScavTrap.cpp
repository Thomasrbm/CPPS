/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 19:01:51 by throbert          #+#    #+#             */
/*   Updated: 2025/05/04 22:19:59 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


ScavTrap::ScavTrap(std::string name) :
    name(name),
    hit_points(100),
    energy_point(50),
    attack_damage(20)
{
    std::cout << "Constructor has been called" << std::endl;
}


ScavTrap::ScavTrap(const ScavTrap& other)
{
    *this = other;
    std::cout << "Copy constructor has been called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Destructor has been called" << std::endl;
}





// 🔧 Construction et destruction avec héritage
// Quand tu crées un objet enfant, l’ordre est :

// ScavTrap scav("unit42");
// construit ClapTrap -> puis ScavTrap


// Et à la destruction :
// // détruit ScavTrap -> puis ClapTrap

// ✅ Important : le constructeur parent est toujours appelé en premier.