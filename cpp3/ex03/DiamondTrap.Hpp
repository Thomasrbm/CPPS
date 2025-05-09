/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.Hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 03:56:00 by throbert          #+#    #+#             */
/*   Updated: 2025/05/09 03:58:13 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    
};





// HERITAGE EN DIAMANT
// on peut faire des héritage mutliple  lass D : public B, public C { };


//  ⚠️ PEUT FAIRE CONFLIT SI Deux A → conflit

// class A { public: void hello(); };
// class B : public A { };
// class C : public A, public B { };





// VIRTUAL : sorte de pragma once 

// class A { public: void hello(); };
// class B : virtual public A { };
// class C : virtual public A { };
// class D : public B, public C { }; // OK ! un seul A


	//     A 
	//    /  
	//   B   C 
	//    \ /
	//    	D

// utile si on veut des mini variantes de A 



// USAGE 


// virtual devant CLASSE heritiere

// virtual QUE dans classe de base pour les FONCTION + permet si on declare un ptr de classe d appeler la ft la plus derivee de la methode de base

// virtual sur DESTRUCTEUR permet si on fait genre , class BASE, class DERIVED. et que on call ptr sur BASE* p = new DERIVED  = le destru va call tout les destru neceassaire.
//en gros avoir un BASE*  permet de stock par exemple dns un vector tout type de derives: 
// ------>
// 
// std::vector<Animal*> zoo;
// zoo.push_back(new Dog);
// zoo.push_back(new Cat);

// for (auto a : zoo) {
//   a->speak();  // appelle Dog::speak() ou Cat::speak() dynamiquement
// }
