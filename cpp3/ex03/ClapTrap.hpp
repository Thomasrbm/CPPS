/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:41:03 by throbert          #+#    #+#             */
/*   Updated: 2025/05/09 03:41:20 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class ClapTrap 
{
	
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	~ClapTrap();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	const std::string& getName() const;
	const unsigned int& getEnergy_point() const;
	const unsigned int& getAttack() const;
	const unsigned int& getLife() const;
	void setAttack(int new_attack);
	void  setEnergy(int amout);


protected:
	std::string name;
	unsigned int  hit_points;
	unsigned int energy_point;
	unsigned int attack_damage;
};
