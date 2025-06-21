/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 02:53:57 by throbert          #+#    #+#             */
/*   Updated: 2025/05/02 17:55:56 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractionnary_part = 8;

int Fixed::getRawBits(void) const
{
	return (this->value);
}





void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}






// produit en crois de conversion. ( 1 << = 256 car on par de 1 << 0 = 1 donc a 8 = 256.  8 bit = 256 car le 0 compte)
// useage de << pour modifiier facilement la fractionnary part au lieu de changer le calcul.
// plus portable car sinon on doit mettre en dure le nombre de chiffre que les bit peuvent rpz : ici hardcoder 256

// le ft ici sert a recuperer le float qui avait ete stockeren int (avec une aprroximation du a l arrondi orignel)


// permet donc de mettre 8 au lieu de 256 pour la fractionnary part.  plus simple pour reflechir
float Fixed::toFloat( void ) const
{
	return ((float)this->value / (1 << fractionnary_part));
}




// division non hard coder = diviser par 256 ici
int Fixed::toInt( void ) const
{
	return this->value >> fractionnary_part;
}




// passe de int a fixed.
Fixed::Fixed(const int const_int)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = (const_int << fractionnary_part);
}




// prend float to fixed.  donc 10 est stocker en 2560  ===> ici pas utile surment pour voir si on a compris. les fixed pas ouf pour les int
Fixed::Fixed(const float const_float)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(const_float * (1 << fractionnary_part)); // on peut par faire << avec des float, donc on simule un mult par 256 car 1 << = 256 (fait ca pour pouvoir changer fractionnary part et donc changer la partie. ainsi plus portable)
} 				 // roundf arrondi a entier le plus proche (du resultat total)





Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}





Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other; // pour faire fixed = fixed;
}





Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
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
	std::cout << "Destructor called" << std::endl;
}
