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

// pas obliger de tout copier.
// pas d appel au constructeur de base, il construit deja
// on chosit ce qu on copie (pas obliger de tout copier)
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = other.getRawBits();
}


// Tu ajoute une fonctionnalit qui depend du proto.  des que tu va donner ces param a ton operateur il va comprendre qu il doit switcher sur ce comportement.

// pour un a = b
// this = a
// b = other 
Fixed& Fixed::operator=(const Fixed& other) // renvoit l adresse vers un objet fixe et prend adresse const d un objet fixed
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) // this = tout l objet  (pointeur vers tout l objet courrant)
		this->value = other.getRawBits();
	return *this; // *this = reference de l objet (stock l adresse de l objet)  (pas comme  *ptr qui accede a la valeur)  , fallait un return
} // renvoit la reference de a a a lui meme
// permet a = b = c , car specifi que chacun reste bien qui il est.

// si on return rien alors b = c se fait en premier 

// b = void
// a = void
// c = c. pb.

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
