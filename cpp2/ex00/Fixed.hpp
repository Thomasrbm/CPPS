/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 00:23:38 by throbert          #+#    #+#             */
/*   Updated: 2025/05/02 17:55:41 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

// constructeur et destru (meme de copie) on peut changer leurs param (pas le reste)
class Fixed
{
public:
	Fixed();
	Fixed(const Fixed& other); // TOUJOURS ce premier param mais on peut en add d autres 
	Fixed& operator=(const Fixed& other);
	~Fixed();
	int getRawBits( void ) const; // pas const au debut car on veut  pouvoir modifier la valeur mais la valeur sera dans le prive pour specifier que seul le getter peut modif.
	void setRawBits( int const raw );

private:
	int value;
	static const int fractionnary_part;// static dans class diff que dans fonction = partage a tous les objets
};

// les nombre a virgule sont des fractions potentiellement infinies.
// le fixed vise a reduire la precision mais a limiter la fraction max representee.


// mtn les pc gerent bien les gloats.
// mais pas tous de la meme facon. 


// avantage du fixed = constance = aura meme resultat qu importe la machine + rapide.  mais pas realiste mathematiquement. = deterministe
// MAIS moins de chiffre.
// ET regle pas le 2/3 + 1/3


// 8 bit pour la partie fractionnaire 
// FIXE : but = rpz des nombre a virrgule mais avec une precision constante. (on dit a l avance l approximation) = ici 8 bit. apres virgule

//  Il permet SURTOUT de faire des FRACTIONS ! 
// 
// le partie fractionnaire dit a l avance le nombre de fraction entre deux entiers. cest a dire le nombre de nombre a virgule entre les 2.

// entre 1 et 2 il y aura :  

// 1.000000
// 1.003906
// 1.007812
// 1.011719
// 1.015625
// ...
// 2.000000

// on peu faire des fraction sur 256

// tout les nombre seront des multiple de 1/256

// 8 bit = 0 a 255 donc 256 chiffres differents.

// donc on empeche les floats car les approximations seront enleves. 
