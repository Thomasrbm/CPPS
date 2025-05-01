/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 00:23:46 by throbert          #+#    #+#             */
/*   Updated: 2025/05/01 01:59:16 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"



int Fixed::getRawBits( void ) const
{
	return this->value;
}


void Fixed::setRawBits( int const raw )
{
	this->value = raw;
}


Fixed::Fixed() :
	value(0)
{
}

// pas obliger de tout copier.
// pas d appel au constructeur de base, il construit deja
// on chosit ce qu on copie (pas obliger de tout copier)
Fixed::Fixed(const Fixed& other)
{
	this->value = other.value;
}

// pour un a = a
Fixed& Fixed::operator=(const Fixed& other) // renvoit l adresse vers un objet fixe et prend adresse const d un objet fixed
{
	if (this != &other) // this = tout l objet  (pointeur vers tout l objet courrant)
		this->value = other.value;
	return *this // *this = reference de l objet (stock l adresse de l objet)  (pas comme  *ptr qui accede a la valeur)  , fallait un return
}

Fixed::~Fixed()
{
}
