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






int main(int argc, char *argv[])
{
  int c = compter_piece()-1;
  int ***tab = alloc3D(c,5,5);
  int gameover = 0;

  readFile(tab);
  afficherTab(tab,c,5,5);

  SDL_Init(SDL_INIT_VIDEO);

  if (SDL_Init(SDL_INIT_VIDEO) == -1)
  {

    fprintf(stderr, "Initialization Error of SDL : %s\n", SDL_GetError());

    exit(EXIT_FAILURE);
  }

  SDL_Surface *ecran = NULL;
  ecran = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF); 
  
  
  SDL_Surface *carreB = NULL;
  //carre de taille 20x20, remplir en blue
  

  if (ecran == NULL)
  {

    fprintf(stderr, "Impossible to load video mode : %s\n", SDL_GetError());

        exit(EXIT_FAILURE);
  }

  SDL_WM_SetCaption("Pentamino", NULL);

  SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

   //SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 17, 206, 112));


  SDL_Flip(ecran);
  SDL_EnableKeyRepeat(10, 10);

  update_events(gameover);

  //SDL_FreeSurface(carreR);
  SDL_Quit();

  return EXIT_SUCCESS;

}




