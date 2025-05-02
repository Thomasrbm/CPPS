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
	Fixed(const int const_int);
	Fixed(const float const_float);
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;

private:
	int value;
	static const int fractionnary_part; // va servir d operateur referentiel qui va tjrs decaler value de 8 bit vers la gaucher (et reserver 8 bit pour la fraction)
};




// FONCTIONS NON MEMBRES :  en dehors de la classe, lie mais ne modifie pas directement l objet (contrairement aux membres)






// Une surcharge d operateur renvoit presque toujours une reference vers le type de la classe ou tu surcharge (pour pas perdre sa ref et pouvoir les enchainer)

// Ici en dehors car : pas un type + pas ma classe

// Une surcharge n ecrase JAMAIS l ancien operateur, il lui ajoute des fonctions
std::ostream& operator<<(std::ostream& os, Fixed const& f); // reference vers flux sortie, (flux ou va ecrire, l objet a afficher de type float.),
// BESOIN DE CETTE SURCHARGE : car std::cout connait pas le type fixed, si je veux l afficher je dois explicite comment faire.

// le << de std::cout est ce base un decalage mais dans ce cadre il prend la surchage et donc il prend le comportement de redirection (mais garde le decalage binaire, par exemple entre parenthese)
