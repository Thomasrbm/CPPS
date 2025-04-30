/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 22:45:57 by throbert          #+#    #+#             */
/*   Updated: 2025/04/30 22:47:17 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: ./Harl_2.0 <DEBUG|INFO|WARNING|ERROR>" << std::endl;
        return 1;
    }

    Harl harl;
    harl.complain(av[1]);
    return 0;
}