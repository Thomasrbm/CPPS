/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 05:59:45 by throbert          #+#    #+#             */
/*   Updated: 2025/04/30 13:49:52 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class Zombie
{

public:

	Zombie(std::string name);
	Zombie();
	~Zombie();
	void	announce(void);
	void	setName(std::string &name);

private:

	std::string name;

};

Zombie* zombieHorde(int N, std::string name);
