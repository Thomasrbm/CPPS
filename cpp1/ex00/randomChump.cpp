/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:59:15 by throbert          #+#    #+#             */
/*   Updated: 2025/04/30 23:24:31 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// allouer sur la stack car son usage est uniquement ici dans ce scope je men sert plus apres.
// pas besoin que cette ft renvoit un malloc

void	randomChump(std::string name)
{
	Zombie zombie(name); // cree un objet de type zombie nom de variable zombie (nom reel name)
	zombie.announce(); // avec cet objet appel methode (donc va call le nom de CE zombie)
}

// existe que la ou est use, pas en dehors.