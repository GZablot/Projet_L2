#ifndef DEF_PIECE 
#define DEF_PIECE 
#include "piece.h"
#endif
#include <SDL/SDL.h>
#ifndef DEF_GAME 
#define DEF_GAME 
#include "game.h"
#endif
#define TAILLE_MAX 1000

void update_events(int condition)
{
  SDL_Event event;
  int gameover;
  while(!gameover)
  {
    SDL_PollEvent(&event);
    switch (event.type) 
    {
      case SDL_QUIT:
        gameover = 1;
        break;
      case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {
          case SDLK_ESCAPE:
            gameover = 1;
            break;
          
        }                          
    }
  }
} 


int nb_occ( char *T,char b)
{
 unsigned int i;
 int nb = 0;
 for(i = 0 ; i < strlen(T); i++)
    if(T[i] == b) 
      nb++;
 return nb;
}



void readFile(void)
{
  
  FILE* fichier = NULL;
  fichier = fopen("Configuration.txt", "r");

  if (fichier != NULL)
  {
  char chaine[TAILLE_MAX] = "";
  int nbLine = 0, nbCol = 0, maxNbCol = 0, cmp_piece = 0;

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
  else
  {
  	printf("Impossible to open Configuration.txt\n");
  }
}



