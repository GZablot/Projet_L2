#include <SDL/SDL.h>
#ifndef DEF_SPRITE 
#define DEF_SPRITE 
#include "sprite.h"
#endif
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAILLE_MAX 1000 

int nb_occ( char *T,char b)
{
 unsigned int i;
 int nb = 0;
 for(i = 0 ; i < strlen(T); i++)
    if(T[i] == b) 
      nb++;
 return nb;
}






int main(int argc, char *argv[])
{
  FILE* fichier = NULL;

  SDL_Surface *screen = NULL;

  int gameover = 0;

  char chaine[TAILLE_MAX] = "";

  fichier = fopen("Configuration.txt", "r");

  int cmp_piece = 0;
  if (fichier != NULL)
  {
    
    int nbLine = 0, nbCol = 0, maxNbCol = 0;

    while (fgets(chaine, TAILLE_MAX, fichier) != NULL)
    {
    
      
      printf("%s\n", chaine);

      if(strcmp(chaine,"\n")) // Compare si la ligne n'est pas vide
      {
        nbLine++;
        nbCol = nb_occ(chaine,'#');
        if(nbCol > maxNbCol)
        {
          maxNbCol = nbCol;
        }
      }

      if(!strcmp(chaine,"\n"))
      {
        cmp_piece++; 
        printf("ligne vide, j'ai fini une piece et je commence une nouvelle\n");
        printf("la taille de piece que j'ai lu est (%d, %d)\n",nbLine,maxNbCol);
        nbLine = 0;
        maxNbCol = 0;
      }  
      
      // On lit et on écrit dans le fichier
      // ...
    }
    //cmp_piece++;
    printf("j'ai lu %d pieces\n",cmp_piece);
    fclose(fichier);
  }
  else{
    printf("Impossible to open Configuration.txt");
  }

   SDL_Init(SDL_INIT_VIDEO);

   if (SDL_Init(SDL_INIT_VIDEO) == -1){

     fprintf(stderr, "Initialization Error of SDL : %s\n", SDL_GetError());

     exit(EXIT_FAILURE);
   }


   screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);


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




