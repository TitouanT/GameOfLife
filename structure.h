/*

strucuture.h contain global constant, and type definition who are used in most
part of the code.

*/

#ifndef STRUCTURE_H
#define STRUCTURE_H

// parameter of the grid
#define N_LINE 46
#define N_COLUMN 49
#define SIZE_CELL 10 // cell are squared with a side of SIZE_CELL
#define GENERATION_TIME 200 // time in ms between each generation.

// definition of the enumeration
typedef enum {dead, alive} t_cell;

#endif


/* for heart.txt 22 23 22 25 23 23 23 24 23 25 24 24
#define N_LINE 46
#define N_COLUMN 49
#define SIZE_CELL 10
// this is the best setup to watch this world
*/
