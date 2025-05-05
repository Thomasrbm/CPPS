/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:18:54 by throbert          #+#    #+#             */
/*   Updated: 2025/05/05 21:16:52 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// geometrie analytique

// calcule l’aire « normale » d’un triangle ABC (avec Fixed)
Fixed	aireTriangle(Point &A, Point &B, Point &C)
{
	Fixed	det; // vaut une unite au carre mais la sous forme de fixe.

	det = (B.getX(B) - A.getX(A)) * (C.getY(C) - A.getY(A)) - (B.getY(B) - A.getY(A))  // chaque soustraction = une longueur.  calculuer avec distance horizontal et vertical
		* (C.getX(C) - A.getX(A)); // calcul deux rectangle soustrait aire de l un a l autre = l air du parrallelogramme suppos du triangle.  Celui ci divise par 2 = aire du triangle : https://excalidraw.com/#json=e_TGXlEzK0QfLzLXP64QV,fSRBFyn6X0MRB0uBRWUlpg
	if (det < Fixed(0))
		det = -det; // ajout d une autre surcharge d operateur (toujours mettre en absolue pck sinon sens de lecture doneerait taille inverse.)
	return (det / Fixed(2)); // aie parreallelograme = aire * 2 du trangle.
}

// le determinant en Valeur absolue  = air du parrallograme.

// c est = L x l 
// un longueur de 


// air triangle = moitie de celle ci.

// Vecteurd de A vers B  = coos de A - B  =  composante de deplacement    = distance parcourus selon un axe.

// vu que en coos on fait gaffe au sens de lecture. si A B C se lit en anti horaire = aire positive

bool	bsp(Point const A, Point const B, Point const C, Point const P)
{
	Fixed	aireABC;
	Fixed	airePAB;
	Fixed	airePBC;
	Fixed	airePCA;

	aireABC = aireTriangle(A, B, C);

	airePAB = aireTriangle(P, A, B);
	airePBC = aireTriangle(P, B, C);
	airePCA = aireTriangle(P, C, A);
	// si P est sur un bord ou un sommet, on rejette  . si aire == 0 = trianle en ligne droite donc 0 d aire.
	if (airePAB == Fixed(0) || airePBC == Fixed(0) || airePCA == Fixed(0))
		return (false);
	// P est à l’intérieur si la somme des trois sous-aires égale l’aire du grand
	return ((airePAB + airePBC + airePCA) == aireABC); 
}
