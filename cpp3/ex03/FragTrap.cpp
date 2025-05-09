/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:48:16 by throbert          #+#    #+#             */
/*   Updated: 2025/05/09 03:44:48 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void FragTrap::highFivesGuys(void)
{
	std::cout << "Iiiiiiiiiiiiiiiiiiiiiit's A HIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIGH FIIIIVE GUYS !" << std::endl;
}

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default Constructor has been called for " << this->name << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap()
{
	this->name = name; // reattribut car d abord init a defaut par classe mere construct par defaut
	std::cout << "FragTrap Constructor has been called for " << this->name << std::endl;
	this->hit_points = 100;
	this->energy_point = 100;
	this->attack_damage = 30;
}

const FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other) // permet de comparere les adresse pour etre sur que different SI ON FAISAIT avec ref on comparerait lobjet et faudrait surcharger l operateur !=
	{
		this->name = other.name;
		this->energy_point = other.energy_point;
		this->attack_damage = other.attack_damage;
		this->hit_points = other.hit_points;
	}
	return *this;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) // copier l heritage, renvoit const FragTrap& other ici.
{
	*this = other; // *this = reference donc objet.  on appel donc operateur = surcharge du dessus.
	std::cout << "FragTrap Copy constructor has been called for " << this->name << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor has been called for " << this->name << std::endl;
}

