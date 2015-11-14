#include <SDL/SDL.h>
#include "piece.h"
#include "game.h"
#include "liste_piece.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
  
  /*int c = compter_piece()-1;
  int ***tab = alloc3D(c,maxNbLigne(),maxNbCol());

  lecture_fichier_tab3D(tab);*/
  //afficherTab(tab,c,maxNbLigne(),maxNbCol());

  int gameover = 0;
  liste l = ConsVide();
  l = lig_col_piece(l);
  l = renverser(l);
  l = tab2D_piece(l);
  


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

  chargePiece(ecran,l);


  //SDL_Flip(ecran);
  SDL_EnableKeyRepeat(10, 10);

  update_events(gameover,ecran,l);

  
  SDL_Quit();


  return EXIT_SUCCESS;

}




