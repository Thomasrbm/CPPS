/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 05:59:45 by throbert          #+#    #+#             */
/*   Updated: 2025/04/30 06:12:22 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class Zombie
{

public:

	Zombie(std::string name);
	Zombie();
	~Zombie();
	void		announce(void);

private:

	std::string name;

};

Zombie* zombieHorde(int N, std::string name);
