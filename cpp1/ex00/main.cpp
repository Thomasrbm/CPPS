/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:59:19 by throbert          #+#    #+#             */
/*   Updated: 2025/04/30 05:58:44 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie *Heap_Zombie = newZombie("Heap_Zombie"); // est cree dans la fonction newzombie
    Heap_Zombie->announce(); // mais use a l exterieru ( dans le main)
    
    randomChump("Stack_Zombie"); // est cree dans random chump et detruit direct apres.
    return (0);
}