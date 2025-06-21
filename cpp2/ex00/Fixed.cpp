/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 00:23:46 by throbert          #+#    #+#             */
/*   Updated: 2025/05/02 18:20:33 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractionnary_part = 8;

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}


void Fixed::setRawBits( int const raw )
{
	this->value = raw;
}


Fixed::Fixed() :
	value(0)
{
	std::cout << "Default constructor called" << std::endl;
}


Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = other.getRawBits();
}


// representation reelle =  a.operator=(b)
// donc le this est pour a qui appel sa fonction membre avec en param b. 
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->value = other.getRawBits();
	// std::cout << this << std::endl;  ==> prouve que adreese. autre aurait print valeure 
	return *this; // *this = reference de l objet (stock l adresse de l objet)
} // renvoit la reference de a a a lui meme
// pour que a s affete lui meme pour qu il s attribue la valeur. sinon indefini.


// permet a = b = c , car specifi que chacun reste bien qui il est.

// si on return rien alors b = c se fait en premier 

// b = void
// a = void
// c = c. pb.



Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


