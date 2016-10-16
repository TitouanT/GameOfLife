/* Titouan Teyssier, 10/14/2016 */
/*  titouan.teyssier@gmail.com  */

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "display.h"

/* global variables are used because i don't want to manipulate things of
the SDL outside of this file. This way, function described below have
no argument */

SDL_Texture *aliveTexture, *deadTexture; // textures are like image variables
SDL_Renderer *renderer; // we can stick them on a renderer
SDL_Window *lifeWindow; // then we push the renderer
												// in the window so we can see it

int TT_SDL_Event () {
	SDL_Event event;
	while (SDL_PollEvent (&event)) {
		switch (event.type) {
			case SDL_WINDOWEVENT:
				if (event.window.event == SDL_WINDOWEVENT_CLOSE) {
					int rep;
					printf("are you sure ? (0: yes) ");
					scanf("%d", &rep);
					return (rep == 0) ? 0 : 1;
				}
				break;
			case SDL_KEYUP:
				if (event.key.keysym.sym == SDLK_RETURN) return ENTER_RELEASED;
				break;
		}
	}
	return 1;
}


void TT_SDL_Quit () {
	// destroying all the data used.
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(deadTexture);
	SDL_DestroyTexture(aliveTexture);
	SDL_DestroyWindow(lifeWindow);
	SDL_Quit();
}

int TT_SDL_Init() {
	if (SDL_Init (SDL_INIT_VIDEO) != 0) {
		printf ("\033[41mERROR:\033[0m unable to load the SDL\n");
		printf ("\t\033[31m%s:\033[0m\n", SDL_GetError());
		return -1;
	}

	//argument are title, x, y, width, height, Uint32 flags
	lifeWindow = SDL_CreateWindow ("Game Of Life", 	SDL_WINDOWPOS_CENTERED,
																									SDL_WINDOWPOS_CENTERED,
																									N_COLUMN * SIZE_CELL,
																									N_LINE * SIZE_CELL, 0);

	if (lifeWindow == NULL) {
		printf ("\033[41mERROR:\033[0m unable to open a window\n");
		printf ("\t\033[31m%s:\033[0m\n", SDL_GetError());
		return -1;
	}

	renderer = SDL_CreateRenderer (lifeWindow,-1,SDL_RENDERER_ACCELERATED);

	if (renderer == NULL) {
		printf ("\033[41mERROR:\033[0m unable to create the renderer\n");
		printf ("\t\033[31m%s:\033[0m\n", SDL_GetError());
		return -1;
	}

	SDL_Surface * deadSurface = IMG_Load("media/dead.png");
	SDL_Surface * aliveSurface = IMG_Load("media/alive.png");
	SDL_Surface * icone = IMG_Load("media/icone.png");

	if (aliveSurface == NULL || deadSurface == NULL || icone == NULL) {
		printf ("\033[41mERROR:\033[0m unable to create a surface\n");
		printf ("\t\033[31m%s:\033[0m\n", SDL_GetError());
		return -1;
	}

	deadTexture = SDL_CreateTextureFromSurface(renderer, deadSurface);
	aliveTexture = SDL_CreateTextureFromSurface(renderer, aliveSurface);
	SDL_SetWindowIcon (lifeWindow, icone);

	SDL_FreeSurface (deadSurface);
	SDL_FreeSurface (aliveSurface);
	SDL_FreeSurface (icone);
	// we don't need the surface anymore so we free the space

	if (deadTexture == NULL || aliveTexture == NULL) {
		printf ("\033[41mERROR:\033[0m unable to create a texture\n");
		printf ("\t\033[31m%s:\033[0m\n", SDL_GetError());
		return -1;
	}

	//SDL_SetRenderDrawColor(renderer, 72, 72, 72, 255); // donne la couleur de nettoyage
	//SDL_RenderClear(renderer); // nettoie
	return 0;
}

void displayGen (t_cell mat[][N_COLUMN]) {
	int i, j, mouseX, mouseY;
	Uint32 button;
	//SDL_QueryTexture(deadTexture, NULL, NULL, &largeur, &hauteur);
	for (i = 0; i < N_LINE; i++) {
		for (j = 0; j < N_COLUMN; j++){
			SDL_Rect dest = { j * SIZE_CELL, i * SIZE_CELL, SIZE_CELL, SIZE_CELL};
			// the sdl rect is a rectangle in the renderer where we put our texture.
			if (mat[i][j]) SDL_RenderCopy (renderer, aliveTexture, NULL, &dest);
			else SDL_RenderCopy (renderer, deadTexture, NULL, &dest);
		}
	}

	SDL_PumpEvents();
	button = SDL_GetMouseState(&mouseX, &mouseY);
	SDL_Rect dest = { mouseX - (mouseX % SIZE_CELL), mouseY - (mouseY % SIZE_CELL), SIZE_CELL, SIZE_CELL};
	SDL_RenderCopy (renderer, aliveTexture, NULL, &dest);

	if (button & SDL_BUTTON(1)) {
		mat[mouseY / SIZE_CELL][mouseX / SIZE_CELL] = alive;
	}
	else if (button & SDL_BUTTON(3)) {
		mat[mouseY / SIZE_CELL][mouseX / SIZE_CELL] = dead;
	}

	SDL_RenderPresent (renderer);
	// when finished processing all the matrix, the renderer is shown.
}

void TT_SDL_Delay (int time) {
	SDL_Delay (time);
}
