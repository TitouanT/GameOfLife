#include <stdio.h>
#include "structure.h"
#include "core.h"
#include "display.h"

void clear() {
	/*clear the screen*/
	printf ("\e[H\e[J");
}

void cursor(int line) {
	/*cursor place the cursor of the terminale at the begining of the line line*/
	printf ("\e[%d;1H", line);
}

int main () {
	int i, nbGeneration;
	int borderLess; 	/* a boolean to know if side cell
											have 8 possible neighbor or not */

	int neighbor[N_LINE][N_COLUMN];
	t_cell mat[N_LINE][N_COLUMN];

	clear();
	printf ("Combien de generation voulez vous afficher ? ");
	scanf ("%d", &nbGeneration);
	printf ("Voulez vous désactiver les bordures ? (oui 1, non 0) ");
	scanf ("%d", &borderLess);

	readMatrix (mat); // initialize the matrix of cell
	TT_SDL_Init (); /* initialization of the SDL who's used
											to display the generation */

	for (i = 0; i <= nbGeneration; i++) {
		cursor(4); // counter of generation always displayed on the same line
		printf("generation n°%d\n", i);
		displayGen (mat);
		fillNeighborMatrix (mat, neighbor, borderLess);
		nextGen (mat, neighbor);
		// scanf("%*c");
		/* uncommment this line if you want togo throw generation step by step
		/* by pressing enter */
	}
	TT_SDL_Quit(); /* quiting safely the SDL */
	printf("\033[32mSuccess\033[0m\n"); // end the program with a green message
	return 0;
}
