/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:49:15 by throbert          #+#    #+#             */
/*   Updated: 2025/04/30 23:27:13 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Weapon 
{

public:
	Weapon(const std::string new_type);
	~Weapon();
	const std::string getType() const; // getter + ref constante.
	void setType(std::string new_type);

private:

	std::string type;

};
