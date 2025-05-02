/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 02:53:57 by throbert          #+#    #+#             */
/*   Updated: 2025/05/02 18:15:40 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

	
const int Fixed::fractionnary_part = 8;


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



bool Fixed::operator>(const Fixed& other)  // false / true
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

bool Fixed::operator==(const Fixed& other) // si ref = modifie directement l objet
{
	return (this->value == other.value);
}

Fixed Fixed::operator+(const Fixed& other) // renvoit un nouvel objet donc Fixed
{
	return (this->value + other.value);
}

Fixed Fixed::operator-(const Fixed& other)
{
	return (this->value - other.value);
}

Fixed Fixed::operator*(const Fixed& other)
{
	return (this->value * other.value);
}

Fixed Fixed::operator/(const Fixed& other)
{
	return (this->value / other.value);
}

Fixed& Fixed::operator++(void) // pas d assignation, no need assignation
{
	this->value += 1;
	return (*this);
}

Fixed& Fixed::operator--(void)
{
	this->value -= 1;
	return (*this);
}

Fixed Fixed::operator++(int)  // pre incrementation.
{
    Fixed tmp(*this);   // copie de l’état actuel. copie de la reference.
    this->value += 1;        // utilise le ++ pré‑incrément  . sur la vrai reference 
    return tmp;         // renvoit la copie 
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
	if (this != &other) // la protection que pour les operateur d assignation (= += , ++ --etc) qui modifie this
		this->value = other.getRawBits(); // pour copier l eta brut ( sans conversion )
	return (*this); // donne la reference (alias = autre nom pour meme objet,  on veut ca et pas ptr.)
}// le ptr peut changer, pas la ref.

// a  = b = c 	return un ref car a = b marcherais,  mais a = b = c  ferait  a = (b = c ) qui lui renvoit void. donc erreur.



std::ostream& operator<<(std::ostream& os, Fixed const& f)
{
	os << f.toFloat();
	return (os);
}

Fixed::~Fixed()
{
}
