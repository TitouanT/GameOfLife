/* Titouan Teyssier, 10/14/2016 */
/*  titouan.teyssier@gmail.com  */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "core.h"

void readMatrix (t_cell mat[][N_COLUMN]) {
	/*fill the matrix according to coordinate of alive cell stored in a file */
	FILE * file = NULL;
	char fileName[50];
	int i, j, etat, isRandom = 0;

	for (i = 0; i < N_LINE; i++)
		for (j = 0; j < N_COLUMN; j++)
			mat[i][j] = dead; /*first all the cells are dead*/

	while (file == NULL && isRandom == 0) { // the user have the choice to open an
																					// existent file or to create a random
																					// world.
		printf ("Quel est le fichier à ouvrir ? ");
		scanf ("%s", fileName);
		if (strcmp ("random", fileName) == 0) isRandom = 1;
		else file = fopen (fileName, "r");
	}

	if (isRandom) { // then create a random world
		srand(time(NULL));
		for (i = 0; i < N_LINE; i++)
			for (j = 0; j < N_COLUMN; j++)
				mat[i][j] = rand()%2; // 0 is dead, 1 is alive.
				// each cell have 50% chance to be either dead or alive
	}
	else { // every cell described in the file became alive.
		fscanf(file, "%d%d", &i, &j);
		while (!feof(file)) {
			mat[i][j] = alive;
			fscanf(file, "%d%d", &i, &j);
		}
		fclose (file);
	}
}

void nextGen (t_cell mat[][N_COLUMN], int neighbor[][N_COLUMN]) {
	/* every cell are tested according to the
	rules to know if she have to toggle state*/
	int i, j, count;
	for (i = 0; i < N_LINE; i++) for (j = 0; j < N_COLUMN; j++) {
		count = neighbor[i][j];
		if (mat[i][j] == alive && (count < DEATH_INF || count > DEATH_SUP)) mat[i][j] = dead;
		else if (mat[i][j] == dead && count == BIRTH) mat[i][j] = alive;
	}
}

void fillNeighborMatrix (t_cell mat[][N_COLUMN], int neighbor[][N_COLUMN], int borderLess) {
	/*for each cell of mat, the number of alive
	neighbors is write in the neighbor matrix*/
	int i, j;
	for (i = 0; i < N_LINE; i++) for (j = 0; j < N_COLUMN; j++) {
		/* choose the right function according to the
		decision of the user to set or unset the border*/
		if (borderLess) neighbor[i][j] = nbNeighborBorderLess (mat, i, j);
		else neighbor[i][j] = nbNeighbor (mat, i, j);
	}
}

int nbNeighbor (t_cell mat[][N_COLUMN], int ligne, int colonne) {
	int nb = 0;

	if (ligne + 1 < N_LINE) {
		if (colonne + 1 <  N_COLUMN && mat[ligne + 1][colonne + 1] == alive) nb++;
		if (colonne - 1 >= 0        && mat[ligne + 1][colonne - 1] == alive) nb++;
		if                            (mat[ligne + 1][colonne]     == alive) nb++;
	}

	if (ligne - 1 >= 0) {
		if (colonne + 1 <  N_COLUMN && mat[ligne - 1][colonne + 1] == alive) nb++;
		if (colonne - 1 >= 0        && mat[ligne - 1][colonne - 1] == alive) nb++;
		if                            (mat[ligne - 1][colonne]     == alive) nb++;
	}

	if (colonne + 1 <  N_COLUMN && mat[ligne][colonne + 1] == alive) nb++;
	if (colonne - 1 >= 0        && mat[ligne][colonne - 1] == alive) nb++;

	return nb;
}

int nbNeighborBorderLess (t_cell mat[][N_COLUMN], int ligne, int colonne) {
	int nb = 0;
	int ligneDessus	  = (ligne   + 1 <  N_LINE)   ? ligne   + 1 : 0;
	int ligneDessous  = (ligne   - 1 >= 0)        ? ligne   - 1 : N_LINE - 1;
	int colonneDroite = (colonne + 1 <  N_COLUMN) ? colonne + 1 : 0;
	int colonneGauche = (colonne - 1 >= 0)        ? colonne - 1 : N_COLUMN - 1;

	/* the expression ((TEST) ? A : B) mean:
				if TEST is true then the expression value is A, else its B
	*/

	if (mat[ligneDessus][colonneDroite] == alive) nb++;
	if (mat[ligneDessus][colonneGauche] == alive) nb++;
	if (mat[ligneDessus][colonne]       == alive) nb++;

	if (mat[ligneDessous][colonneDroite] == alive) nb++;
	if (mat[ligneDessous][colonneGauche] == alive) nb++;
	if (mat[ligneDessous][colonne]       == alive) nb++;

	if (mat[ligne][colonneDroite] == alive) nb++;
	if (mat[ligne][colonneGauche] == alive) nb++;

	// for each alive neighbor, nb is incremented

	return nb;
}
