/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 02:53:57 by throbert          #+#    #+#             */
/*   Updated: 2025/05/05 18:31:03 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

	
const int Fixed::fractionnary_part = 8;


int& Fixed::getValue(Fixed& a)
{
	return this->value;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a.toFloat() < b.toFloat())
		return (a);
	else 
		return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.toFloat() < b.toFloat())
		return (a);
	else 
		return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a.toFloat() > b.toFloat())
		return (a);
	else 
		return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.toFloat() > b.toFloat())
		return (a);
	else 
		return (b);
}



bool Fixed::operator>(const Fixed& other)
{
	return (this->value > other.value);
}

bool Fixed::operator<(const Fixed& other)
{
	return (this->value < other.value);
}

bool Fixed::operator>=(const Fixed& other)
{
	return (this->value >= other.value);
}

bool Fixed::operator<=(const Fixed& other)
{
	return (this->value <= other.value);
}

bool Fixed::operator!=(const Fixed& other)
{
	return (this->value != other.value);
}

bool Fixed::operator==(const Fixed& other)
{
	return (this->value == other.value);
}

Fixed Fixed::operator+(const Fixed& other)
{
	return (this->value + other.value);
}

Fixed Fixed::operator-(const Fixed& other)
{
	return (this->value - other.value);
}

Fixed Fixed::operator-()
{
	return Fixed(0) - *this;  // CONVERTIT : car 0 - -1 = 1  et 0 - 1 = -1
}

Fixed Fixed::operator*(const Fixed& other)
{
	return (this->value * other.value);
}

Fixed Fixed::operator/(const Fixed& other)
{
	return (this->value / other.value);
}

Fixed& Fixed::operator++(void)
{
	this->value += 1;
	return (*this);
}

Fixed& Fixed::operator--(void)
{
	this->value -= 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    this->value += 1;
    return tmp;
}


Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
    this->value -= 1;
    return tmp;  
}

int Fixed::getRawBits(void) const
{
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float Fixed::toFloat( void ) const
{
	return ((float)this->value / (1 << fractionnary_part));
}

int Fixed::toInt( void ) const
{
	return this->value >> fractionnary_part;
}

Fixed::Fixed(const int const_int)
{
	this->value = (const_int << fractionnary_part);
}

Fixed::Fixed(const float const_float)
{
	this->value = roundf(const_float * (1 << fractionnary_part)); 
}
Fixed::Fixed() : value(0)
{
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->value = other.getRawBits();
	return (*this);
}




std::ostream& operator<<(std::ostream& os, Fixed const& f)
{
	os << f.toFloat();
	return (os);
}

Fixed::~Fixed()
{
}
