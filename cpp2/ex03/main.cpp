/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:18:49 by throbert          #+#    #+#             */
/*   Updated: 2025/05/02 19:25:28 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
	Point a(0, 0);
	Point b(0, 10);
	Point c(10, 0);

	Point in_point(2, 2);
	Point out_point(15, 15);

	std::cout << "in_point is : " << (bsp(a,b,c,in_point) ? "inside" : "outside") << std::endl;
	std::cout << "out_point is :  " << (bsp(a,b,c,out_point) ? "inside" : "outside") << std::endl;
	return 0;
}
