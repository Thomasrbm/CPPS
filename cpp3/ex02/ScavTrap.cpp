/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 19:01:51 by throbert          #+#    #+#             */
/*   Updated: 2025/05/08 19:31:41 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


void ScavTrap::guardGate() 
{
	if (guarded_mode == false)
	{
		this->guarded_mode = true;
		std::cout << this->name << " is now in guard mode" << std::endl;
	}
	else 
	{
		this->guarded_mode = false;
		std::cout << this->name << " is not in guard mode anymore" << std::endl;
	}
}

ScavTrap::ScavTrap(std::string name) : ClapTrap()
{
	std::cout << "ScavTrap Constructor has been called for " << this->name << std::endl;
	this->name = name;
	this->hit_points = 100;
	this->energy_point = 100;
	this->attack_damage = 30;
	this->guarded_mode = false;
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
	this->guarded_mode = false;
	std::cout << "ScavTrap Copy constructor has been called for " << this->name << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor has been called for " << this->name << std::endl;
}





// 🔧 Construction et destruction avec héritage
// Quand tu crées un objet enfant, l’ordre est :

// ScavTrap scav("unit42");
// construit ClapTrap -> puis ScavTrap


// Et à la destruction :
// // détruit ScavTrap -> puis ClapTrap

// ✅ Important : le constructeur parent est toujours appelé en premier.
