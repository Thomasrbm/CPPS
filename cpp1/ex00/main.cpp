/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:59:19 by throbert          #+#    #+#             */
/*   Updated: 2025/04/30 23:09:35 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// si on declarait un Zombie  main stack zombie serait aussi dans le scope du main
// lui pourrait etre envoye ailleurs.

int main(void)
{
	Zombie *Heap_Zombie = newZombie("Heap_Zombie"); // est cree dans la fonction newzombie
	Heap_Zombie->announce(); // mais use a l exterieru ( dans le main)  (destroy que a delete)
	
	randomChump("Stack_Zombie"); // est cree dans random chump et detruit direct apres.

	
	delete Heap_Zombie;
	return (0);
}



// void doSomething(Zombie* z) {
//     z->announce();
// }

// int main() {
//     Zombie* heapZ = newZombie("Heap");
//     doSomething(heapZ);   // OK : heapZ est toujours valide
//     delete heapZ;
// }



// int main() {
    // randomChump("Stack");
    // Impossible d’utiliser &z , z existe plus
	// doSomething(Stack); 
// }