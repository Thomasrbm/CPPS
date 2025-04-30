/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: throbert <throbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:20:28 by throbert          #+#    #+#             */
/*   Updated: 2025/04/30 21:59:46 by throbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Wrong format ! need 3 arguments" << std::endl;
		return 0;
	}

	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	// c str converti en constant string.
	std::ifstream infile(filename.c_str());  // donne un flux de lecture qui va lire ligne par ligne a chqaue iteration (gnl)
	if (!infile)
	{
	    std::cerr << "Error: can't open file " << filename << std::endl;
	    return 1;
	}
	
	std::ofstream outfile((filename + ".replace").c_str());  // fichier de sortie cree

	std::string line_read;
	while (std::getline(infile, line_read)) // va lire chqaue ligne et remplacer les mot en mettant newline dans nouveau fichier.replace.
	{
		std::string new_line;
		size_t  pos = 0;
		while ((pos = line_read.find(s1, pos)) != std::string::npos) // find renvoit position du mot trouve, des que trouve plus = npos et sort.
		{
			new_line += line_read.substr(0, pos); // extrait ligne du debut jusqu a mot trouver (avant) et l ajoute a newline
			new_line += s2; // le mot qui remplace
			line_read = line_read.substr(pos + s1.length()); // reprend la partie restante
			pos = 0; // recommence au debut avec partie restante
		}
		new_line += line_read; // ce qui reste a la fin des remplacement

		outfile << new_line << std::endl; // ajoute la ligne modif ou non dans outfile
	}
	
	return 0;
}
