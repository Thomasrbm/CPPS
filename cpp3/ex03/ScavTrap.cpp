/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 19:01:51 by throbert          #+#    #+#             */
/*   Updated: 2025/05/09 03:48:16 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void ScavTrap::attack(const std::string& target)
{
	if (this->energy_point > 0 && this->hit_points > 0 && this->attack_damage > 0)
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage !" << std::endl;
		this->energy_point -= 1;
	}
	else if (this->energy_point <= 0)
		std::cout << "/!\\ ScavTrap " << this->name << " cannot attack " << target << " because he lacks energy points : Feniantone... /!\\" << std::endl << std::endl;
	else if (this->hit_points <= 0)
		std::cout << "/!\\ ScavTrap " << this->name << " cannot attack " << target << " because he's dead (0 hit points) : REPAIR IT ! /!\\" << std::endl << std::endl;
	else if (this->attack_damage <= 0)
		std::cout << "/!\\ ScavTrap " << this->name << " cannot attack " << target << " because he deals no damage (0 attack) :  a weak bastard ;'( /!\\" << std::endl << std::endl;
}

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
	this->name = name;
	std::cout << "ScavTrap Constructor has been called for " << this->name << std::endl;
	this->hit_points = 100;
	this->energy_point = 50;
	this->attack_damage = 20;
	this->guarded_mode = false;
}

ScavTrap::ScavTrap() :  ClapTrap()
{
	std::cout << "ScavTrap default Constructor has been called for " << this->name << std::endl;
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

ScavTrap::ScavTrap(const ScavTrap& other) :  ClapTrap(other)
{
	*this = other;
	this->guarded_mode = false;
	std::cout << "ScavTrap Copy constructor has been called for " << this->name;
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
