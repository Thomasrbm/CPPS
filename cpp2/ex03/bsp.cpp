/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:18:54 by throbert          #+#    #+#             */
/*   Updated: 2025/05/02 19:29:53 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float	orientation(Point const A, Point const B, Point const P)
{
	return (B.x - A.x) * (P.y - A.y) - (B.y - A.y) * (P.x - A.x);
}

// determine de quel cote de chaque arrete est le point et peut dire si oui ou non est dedant.
bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	d1;
	float	d2;
	float	d3;
	bool	has_neg;
	bool	has_pos;

	d1 = orientation(a, b, point);
	d2 = orientation(b, c, point);
	d3 = orientation(c, a, point);
	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
	// Strictement à l’intérieur s’il n’y a pas de signe mixte
	// et aucun d_i n’est nul
	return !(has_neg && has_pos) // pas de mélange de signes
		&& d1 != 0.0f && d2 != 0.0f && d3 != 0.0f;
}
