
#include <iostream>
#include <chrono>
#include <thread>

#include <unistd.h> 

int main()
{
	// std::cout << "Hello with \\n\n";
	// sleep(2);

	// std::cout << "Hello with std::endl" << std::endl;
	// sleep(2);

	// std::cout << " [not flushed]";
	// sleep(2);


    // SEGFAULT ICI.

    // std::cout << "Avant le crash \\n\n";
	// std::cout << "Avant le crash  std::endl" << std::endl; // JUSTE LE ADD FAIT FLUSH CEUX AVANT MEME DANS PIPE.
    // std::cout << "Non flushé"; 
	// int *ptr = nullptr; // nullptr = pointe vers rien
	// *ptr = 42;                  // (crash) car ecrit dans rien
    // std::cout << "Jamais affiché" << std::endl;


	return 0;
}

// ./a.out > output.txt

// ./a.out | cat     

// endl flush meme pipe et dans fichier 
