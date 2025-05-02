/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:19:01 by throbert          #+#    #+#             */
/*   Updated: 2025/05/02 19:18:36 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(const float &a, const float &b) :
	x(a),
	y(b)
{
}

Point::Point() :
	x(0),
	y(0)
{
}

Point::Point(const Point &other)
{
	*this = other; // L objet en lui meme devient = a other (dans toutes caracs)
}

Point &Point::operator=(const Point &other) // assigne toutes les coos d un objet Point a un autre.
{
	if (this != &other)
	{
		this->x = other.x;
		this->y = other.y;
	}
	return (*this);
}

Point::~Point()
{
}
