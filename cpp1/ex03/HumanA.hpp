/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:49:06 by throbert          #+#    #+#             */
/*   Updated: 2025/04/30 21:00:40 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Weapon.hpp"

class HumanA
{

public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void attack();

private:
	Weapon		&weapon;
	std::string	name;

};
