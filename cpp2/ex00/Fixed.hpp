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
	Fixed& operator=(const Fixed& other); // pas generique, prototypage en soit partie de la redefinition de l operateur (aurait pu return autre type d autre facon)
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );

private:
	int value;
	static const int fractionnary_part;
};
