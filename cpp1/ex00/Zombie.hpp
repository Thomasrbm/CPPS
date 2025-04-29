/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:59:08 by throbert          #+#    #+#             */
/*   Updated: 2025/04/29 21:41:33 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class Zombie
{

public:

	Zombie(std::string name);
	~Zombie();
	void		announce(void);
	Zombie		*newZombie(std::string name);
	void		randomChump(std::string name);

private:

	std::string name;

};
