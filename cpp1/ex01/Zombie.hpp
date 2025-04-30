/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 05:59:45 by throbert          #+#    #+#             */
/*   Updated: 2025/04/30 23:14:09 by throbert         ###   ########.fr       */
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

Zombie* zombieHorde(int N, std::string name); // hors car cree un groupe de zombie, pas besoin que la classe y ait acces
