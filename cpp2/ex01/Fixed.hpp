/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 02:53:55 by throbert          #+#    #+#             */
/*   Updated: 2025/05/02 17:55:36 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cmath>

class Fixed
{
public:
	Fixed();
	Fixed(const int const_int);  // constructeur de conversion. modifie le constructeur de base et ajoute un conversion si param = int
	Fixed(const float const_float);
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const; // ne va pas modifier l objet. va returner une copie de la valeur de l objet convertie en float
	int toInt( void ) const;


private:
	int value; // on triche en sotkcant dans un int. donc on arondira si resultat en fraction.  =====> perf  +  sur qu on est dans une fraction.car on redivise par 256. et on aura toujours le meme resultat
	static const int fractionnary_part; // va servir d operateur referentiel qui va tjrs decaler value de 8 bit vers la gaucher (et reserver 8 bit pour la fraction)
};



// constant car sur tout les pc ca sera avec des des valeur fix : fractionnary part et arrondi = tous les meme 
// ces software side pas besion du FPU. 









// FONCTIONS NON MEMBRES :  en dehors de la classe, lie mais ne modifie pas directement l objet (contrairement aux membres)
// ici car appartient pas a la classe . modifie une autre classe mais pour une use liee a a la classe fixed. 



std::ostream& operator<<(std::ostream& os, Fixed const& f);
// BESOIN DE CETTE SURCHARGE : car std::cout connait pas le type fixed, si je veux l afficher je dois explicite comment faire.

