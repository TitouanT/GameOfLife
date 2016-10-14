/* Titouan Teyssier, 10/14/2016 */
/*  titouan.teyssier@gmail.com  */

#ifndef MAIN_H
#define  MAIN_H

#include "structure.h"


// parameter of the Game Of Life
#define BIRTH 3
#define DEATH_INF 2
#define DEATH_SUP 3

/* game of life rules:
			if a cell is alive AND she have 	less than 2 alive neighbor
																				OR
																				more than 3 alive neighbor
			then she dies at the next generation respectively by under/over-population

			else (if she is dead), if she have exactly 3 alive neighbor
			then she became alive at the next generation.
*/


// function prototype
int nbNeighbor (t_cell mat[][N_COLUMN], int ligne, int colonne);
int nbNeighborBorderLess (t_cell mat[][N_COLUMN], int ligne, int colonne);
void fillNeighborMatrix (t_cell mat[][N_COLUMN], int neighbor[][N_COLUMN], int borderLess);
void nextGen (t_cell mat[][N_COLUMN], int neighbor[][N_COLUMN]);
void readMatrix (t_cell mat[][N_COLUMN]);

#endif
