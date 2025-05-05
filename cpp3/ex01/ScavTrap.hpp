/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 19:01:54 by throbert          #+#    #+#             */
/*   Updated: 2025/05/05 21:41:47 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

public:
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& other);
	const ScavTrap& operator=(const ScavTrap& other);
	~ScavTrap();
	void guardGate();

private:
	


}

// les héritiers doivent aussi re décla les forme canoniques 


// protected : permet contrairement a private que les classes derivés aient aussi accès au var / ft.



// on peut faire des héritage mutliple  lass D : public B, public C { };


//  ⚠️ PEUT FAIRE CONFLIT SI Deux A → conflit

// class A { public: void hello(); };
// class B : public A { };
// class C : public A { };


// pour ça on fait  VIRTUAL : sorte de pragma once 

// class A { public: void hello(); };
// class B : virtual public A { };
// class C : virtual public A { };
// class D : public B, public C { }; // OK ! un seul A
