/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 19:01:51 by throbert          #+#    #+#             */
/*   Updated: 2025/05/05 21:52:44 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


void ScavTrap::guardGate() 
{
	std::cout << this->name << " is now in guard mode" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap()
{
	std::cout << "Constructor has been called" << std::endl;
	this->name = name;
	this->hit_points = 100;
	this->energy_point = 100;
	this->attack_damage = 30;
}

const ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)   // & devant reference donne addresse : comme pointeur.
	{	// pourrait pas faire *this != other  car reference a reprend l objet donc ca comparerait TOUT l objet et faudrait surcharger l operateur pour tout comparer
		this->attack_damage = other.attack_damage;
		this->energy_point = other.energy_point;
		this->hit_points = other.hit_points;
		this->name = other.name;
	}
	return *this;
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
