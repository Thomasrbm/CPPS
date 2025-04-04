
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	// printf("Hello ");
	// sleep(1);
	// printf("World\n");


	// printf("Hello\n");
	// sleep(1);
	// printf("World\n");

	// printf("Hello ");
	// fflush(stdout);
	// sleep(1);
	// printf("World\n");

	// write(1, "Hello ", 7);
	// sleep(1);
	// write(1, "World\n", 7);
}

// Flush = vider le buffer stdout

// \n flush automatique sauf dans pipe et fichier.
// sert a ignorer les sleep et afficher direct.
// si y a un crash ca ecrirait pas sans flush.

// write ne flush meme pas car il appel direct le systene

// y a un buffer de base qui stock
