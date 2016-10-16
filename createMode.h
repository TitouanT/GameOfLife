#ifndef CREATEMODE_H
#define CREATEMODE_H

#include "structure.h"
#include "core.h"
#include "display.h"

int verifNameOfFile (char **argv);
int createMode (char **argv);
void writeFile(t_cell mat[][N_COLUMN], char * fileName);

#endif
