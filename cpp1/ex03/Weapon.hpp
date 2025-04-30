/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:49:15 by throbert          #+#    #+#             */
/*   Updated: 2025/04/30 19:58:12 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Weapon 
{

public:
	Weapon(const std::string new_type);
	~Weapon();
	std::string getType() const;
	void setType(std::string new_type);

private:

	std::string type;

};
