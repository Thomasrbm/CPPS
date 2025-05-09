/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:48:06 by throbert          #+#    #+#             */
/*   Updated: 2025/05/09 04:01:54 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap // virtual ici aussi
{

public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap& other);
    const FragTrap& operator=(const FragTrap& other);
    ~FragTrap();

    void highFivesGuys(void);

    
};