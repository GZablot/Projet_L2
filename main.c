#include <SDL/SDL.h>
#ifndef DEF_PIECE 
#define DEF_PIECE 
#include "piece.h"
#endif
#ifndef DEF_GAME 
#define DEF_GAME 
#include "game.h"
#endif
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAILLE 20




int main(int argc, char *argv[])
{
  int c = compter_piece()-1;
  int ***tab = alloc3D(c,5,5);

  readFile(tab);
  afficherTab(tab,c,5,5);

  SDL_Init(SDL_INIT_VIDEO);

  if (SDL_Init(SDL_INIT_VIDEO) == -1){

     fprintf(stderr, "Initialization Error of SDL : %s\n", SDL_GetError());

     exit(EXIT_FAILURE);
   }

  SDL_Surface *screen = NULL;
  screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF); 
  SDL_Surface *carreR = NULL;
  //carre de taille 20x20, remplir en rouge
  SDL_Surface *carreB = NULL;
  //carre de taille 20x20, remplir en blue
  return EXIT_SUCCESS;

   = NULL;

  int gameover = 0;

  compter_piece();

  

   


   


   if (screen == NULL){

		fprintf(stderr, "Impossible to load video mode : %s\n", SDL_GetError());

        exit(EXIT_FAILURE);
	}

   SDL_WM_SetCaption("Pentamino", NULL);

   SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));

   //SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 17, 206, 112));


   SDL_Flip(screen);
   SDL_EnableKeyRepeat(10, 10);

   update_events(gameover);


   SDL_Quit();

   return EXIT_SUCCESS;
}




