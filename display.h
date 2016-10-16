/* Titouan Teyssier, 10/14/2016 */
/*  titouan.teyssier@gmail.com  */

#ifndef DISPLAY_H
#define  DISPLAY_H

#include "structure.h"
#define ENTER_RELEASED 2

// function prototypes
int TT_SDL_Init(void);
void TT_SDL_Quit (void);
void displayGen (t_cell mat[][N_COLUMN]);
int TT_SDL_Event (void);
void TT_SDL_Delay (int time);

#endif
