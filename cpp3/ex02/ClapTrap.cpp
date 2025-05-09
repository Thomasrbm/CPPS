/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:44:41 by throbert          #+#    #+#             */
/*   Updated: 2025/05/09 03:05:25 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void  ClapTrap::setEnergy(int amout)
{
	std::cout << "energy of " << this->name <<" has been set to " << amout << std::endl;
	this->energy_point = amout;
}

void ClapTrap::setAttack(int new_attack)
{
	std::cout << "attack of " << this->name <<" has been set to " << new_attack << std::endl;
	this->attack_damage = new_attack;
}

const unsigned int& ClapTrap::getLife() const
{
	return this->hit_points;
}

const unsigned int& ClapTrap::getAttack() const
{
	return this->attack_damage;
}

const std::string& ClapTrap::getName() const
{
	return this->name;    
}

const unsigned int& ClapTrap::getEnergy_point() const
{
	return this->energy_point;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energy_point > 0 && this->hit_points > 0 && this->attack_damage > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage !" << std::endl;
		this->energy_point -= 1;
	}
	else if (this->energy_point <= 0)
		std::cout << "/!\\ ClapTrap " << this->name << " cannot attack " << target << " because he lacks energy points : Feniantone... /!\\" << std::endl << std::endl;
	else if (this->hit_points <= 0)
		std::cout << "/!\\ ClapTrap " << this->name << " cannot attack " << target << " because he's dead (0 hit points) : REPAIR IT ! /!\\" << std::endl << std::endl;
	else if (this->attack_damage <= 0)
		std::cout << "/!\\ ClapTrap " << this->name << " cannot attack " << target << " because he deals no damage (0 attack) :  a weak bastard ;'( /!\\" << std::endl << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points > 0)
	{
			if (amount <= hit_points)
			{
				std::cout << "ClapTrap " << this->name << " took "  << amount << " points of damage !" << std::endl;
				this->hit_points -= amount;
			}
			else 
			{
				amount = this->hit_points;
				std::cout << "ClapTrap " << this->name << " took "  << amount << " points of damage !" << std::endl;
				this->hit_points -= amount;
			}	
	}
	else 
	{
		std::cout << "/!\\ ClapTrap " << this->name << " cannot take any more damage, the guy is already down, STOP IT ! /!\\" << std::endl << std::endl;
	}

}

	
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_point > 0 && (this->hit_points + amount) < 100)
	{
		std::cout << "ClapTrap " << this->name << " has been repaired, and regained : "  << amount << " hit points !" << std::endl;    
		this->hit_points += amount;
		this->energy_point -= 1;
	}
	else if (this->energy_point == 0)
		std::cout << "/!\\ ClapTrap " << this->name << " cannot be repaired because he lacks energy points : Feniantone... /!\\" << std::endl << std::endl;
	else if (this->hit_points == 100)
		std::cout << "/!\\ ClapTrap " << this->name << " cannot be repaired because he already is fully alive (100 hit points) /!\\" << std::endl << std::endl;
	else
	{
		amount =  (100 - this->hit_points);
		std::cout << "ClapTrap " << this->name << " has been repaired, and regained : "  << amount << " hit points !" << std::endl;    
		this->hit_points += amount;
		this->energy_point -= 1;
	}
}

ClapTrap::ClapTrap(std::string name) :
	name(name),
	hit_points(10),
	energy_point(10),
	attack_damage(0)
{
	std::cout << "ClapTrap Constructor has been called for " << this->name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->energy_point = other.energy_point;
		this->attack_damage = other.attack_damage;
	}
	return *this;
}
	
ClapTrap::ClapTrap(const ClapTrap& other)
{
	*this = other;
	std::cout << "ClapTrap Copy constructor has been called for " << this->name << std::endl;
}

ClapTrap::ClapTrap() :
	name("default"),
	hit_points(0),
	energy_point(0),
	attack_damage(0)
{
	std::cout << "ClapTrap default Constructor has been called for " << this->name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor has been called for " << this->name << std::endl;
}
