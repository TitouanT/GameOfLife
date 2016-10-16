#include <stdio.h>
#include "createMode.h"


int createMode (char **argv) {
	if (verifNameOfFile(argv) == 0) return 0;
	t_cell mat[N_LINE][N_COLUMN];
	initMatrix(mat);
	TT_SDL_Init();
	while (TT_SDL_Event() != ENTER_RELEASED) {
		displayGen (mat);
	}
	TT_SDL_Quit();
	writeFile(mat, argv[2]);
	return 0;
}

void writeFile(t_cell mat[][N_COLUMN], char * fileName) {
	char * path[30] = {'m', 'y', 'C', 'r', 'e', 'a', 't', 'i', 'o', 'n', '/'};
	int i = 0, j;
	while (fileName[i] != '\0') {
		path[i + 11] = fileName[i];
		i++;
	}
	path[11 + i] = '\0';
	FILE * file = fopen (path, "w");
	
	for (i = 0; i < N_LINE; i++)
		for (j = 0; j < N_COLUMN; j++)
			if (mat[i][j] == alive) fprintf("%d %d ", i, j);

	fclose(file);
}

int verifNameOfFile (char **argv) {
	int i = 0;
	while (i < 20 && argv[2][i] != ' ' && argv[2][i] != '\0')i++;
	if (argv[2][i] != '\0') {
		printf ("USAGE: %s %s <fileName>\n The name of the file can't exceed 20 character and can't contain space\n", argv[0], argv[1]);
		return 0;
	}
	return 1;
}
