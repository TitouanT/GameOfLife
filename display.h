/* Titouan Teyssier, 10/14/2016 */
/*  titouan.teyssier@gmail.com  */

#ifndef DISPLAY_H
#define  DISPLAY_H

#include "structure.h"

// function prototypes
int TT_SDL_Init(void);
void TT_SDL_Quit (void);
void displayGen (t_cell mat[][N_COLUMN]);
int TT_SDL_EVENT (void);

#endif
