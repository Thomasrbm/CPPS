/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:41:03 by throbert          #+#    #+#             */
/*   Updated: 2025/05/05 21:35:34 by throbert         ###   ########.fr       */
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
	const int& getEnergy_point() const;
	const int& getAttack() const;
	void setAttack(int new_attack);

protected:
	std::string name;
	int hit_points;
	int energy_point;
	int attack_damage;
};
