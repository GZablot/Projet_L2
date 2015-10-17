#include <SDL/SDL.h>
#ifndef DEF_PIECE 
#define DEF_PIECE 
#include "piece.h"
#endif
#ifndef DEF_GAME 
#define DEF_GAME 
#include "game.h"
#endif
#ifndef DEF_LISTE_PIECE 
#define DEF_LISTE_PIECE
#include "liste_piece.h"
#endif
#include <stdlib.h>
#include <stdio.h>
#include <string.h>






int main(int argc, char *argv[])
{
  
  int c = compter_piece()-1;
  int ***tab = alloc3D(c,maxNbLigne(),maxNbCol());
  int gameover = 0;

  lecture_fichier_tab3D(tab);
  afficherTab(tab,c,maxNbLigne(),maxNbCol());

  SDL_Init(SDL_INIT_VIDEO);

  if (SDL_Init(SDL_INIT_VIDEO) == -1)
  {

    fprintf(stderr, "Erreur d'initialisation d'SDL : %s\n", SDL_GetError());

    exit(EXIT_FAILURE);
  }

  

  SDL_Surface *ecran = NULL;
  ecran = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  if (ecran == NULL)
  {

    fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());

        exit(EXIT_FAILURE);
  } 

  SDL_WM_SetCaption("Pentamino", NULL);

  SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

   //SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 17, 206, 112));

  chargePiece(ecran,tab,c,maxNbLigne(),maxNbCol());



  SDL_Flip(ecran);
  SDL_EnableKeyRepeat(10, 10);

  update_events(gameover);

  
  freeTab(tab,maxNbCol(),maxNbLigne());
  SDL_Quit();


  return EXIT_SUCCESS;

}




