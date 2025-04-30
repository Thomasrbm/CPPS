/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 22:45:55 by throbert          #+#    #+#             */
/*   Updated: 2025/04/30 22:47:26 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Harl
{

public:
	Harl();
	~Harl();
	void	complain( std::string level );


private:
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
};