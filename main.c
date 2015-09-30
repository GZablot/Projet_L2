#include <SDL/SDL.h>
#ifndef DEF_SPRITE 
#define DEF_SPRITE 
#include "sprite.h"
#endif
#include <stdlib.h>
#include <stdio.h>
#define TAILLE_MAX 1000 // Tableau de taille 1000

int main(int argc, char *argv[])
{
  FILE* file = NULL;

  SDL_Surface *screen = NULL;

  int gameover = 0;

  char chaine[TAILLE_MAX] = "";

  file = fopen("Configuration.txt", "r");


  if (file != NULL)
  {
    int i=1;
    while (fgets(chaine, TAILLE_MAX, file) != NULL)
    {
  
      printf("%d ligne\n", i);
      printf("%s", chaine);
      i++;
      // On lit et on écrit dans le fichier
      // ...
    }
    fclose(file);
  }
  else{
    printf("Impossible to open Configuration.txt");
  }

   SDL_Init(SDL_INIT_VIDEO);

   if (SDL_Init(SDL_INIT_VIDEO) == -1){

     fprintf(stderr, "Initialization Error of SDL : %s\n", SDL_GetError());

     exit(EXIT_FAILURE);
   }


   screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

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




