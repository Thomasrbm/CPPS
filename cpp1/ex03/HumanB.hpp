/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:49:02 by throbert          #+#    #+#             */
/*   Updated: 2025/04/30 21:04:08 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Weapon.hpp"

class HumanB 
{

public:
	HumanB(std::string name);
	~HumanB();
	void attack();
	void setWeapon(Weapon& weapon);

private:
	Weapon		*weapon;
	std::string	name;

};
