/* Titouan Teyssier, 10/14/2016 */
/*  titouan.teyssier@gmail.com  */

#include <stdio.h>
#include <string.h>

#include "structure.h"
#include "core.h"
#include "display.h"
#include "main.h"
#include "createMode.h"

int main (int argc, char ** argv) {

	if (argc == 3 && strcmp("--createMode", argv[1]) == 0) createMode(argv);
	else normalMode();

	printf("\033[32mSuccess\033[0m\n"); // end the program with a green message
	return 0;
}

void normalMode () {
	int i, nbGeneration;
	int borderLess; 	/* a boolean to know if side cell
											have 8 possible neighbor or not */

	int neighbor[N_LINE][N_COLUMN];
	t_cell mat[N_LINE][N_COLUMN];

	clear();
	printf ("Voulez vous désactiver les bordures ? (oui 1, non 0) ");
	scanf ("%d", &borderLess);

	readMatrix (mat); // initialize the matrix of cell
	TT_SDL_Init (); /* initialization of the SDL who's used
											to display the generation */

	for (i = 0; TT_SDL_Event (); i++) {
		cursor(4); // counter of generation always displayed on the same line
		printf("generation n°%d\n", i);
		displayGen (mat);
		fillNeighborMatrix (mat, neighbor, borderLess);
		nextGen (mat, neighbor);
		TT_SDL_Delay(GENERATION_TIME);
		// scanf("%*c");
		/* uncommment this line if you want to go throw generation step by step
		/* by pressing enter */
	}
	TT_SDL_Quit(); /* quiting safely the SDL */
}

void clear() {
	/*clear the screen*/
	printf ("\e[H\e[J");
}

void cursor(int line) {
	/*cursor place the cursor of the terminale at the begining of the line line*/
	printf ("\e[%d;1H", line);
}
