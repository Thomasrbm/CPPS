/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:19:05 by throbert          #+#    #+#             */
/*   Updated: 2025/05/05 18:21:31 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Fixed.hpp"

class Point
{
	
public:
	Point(const float& a, const float& b);
	Point();
	Point(const Point& other);
	Point& operator=(const Point& other);
	~Point();
	int& getX(Point& a);
	int& getY(Point& a);


private:
	Fixed x;
	Fixed y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
