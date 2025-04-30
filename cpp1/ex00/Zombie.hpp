/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:59:08 by throbert          #+#    #+#             */
/*   Updated: 2025/04/30 05:55:35 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class Zombie
{

public:

	Zombie(std::string name);
	~Zombie();
	void		announce(void);

private:

	std::string name;

};

Zombie* newZombie(std::string name);
void randomChump(std::string name);