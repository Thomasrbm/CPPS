/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:49:13 by throbert          #+#    #+#             */
/*   Updated: 2025/04/30 23:27:21 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string Weapon::getType() const
{
	return type;
}

void Weapon::setType(std::string new_type)
{
	this->type = new_type;
} 

Weapon::Weapon(std::string new_type)
{
	setType(new_type);
}

Weapon::~Weapon()
{
}