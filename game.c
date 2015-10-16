#ifndef DEF_PIECE 
#define DEF_PIECE 
#include "piece.h"
#endif
#include <SDL/SDL.h>
#ifndef DEF_GAME 
#define DEF_GAME 
#include "game.h"
#endif
#define TAILLE_MAX 500

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



int compter_piece(void )
{
  
  FILE* fichier = NULL;
  fichier = fopen("Configuration.txt", "r");
  char chaine[TAILLE_MAX] = "";
  int nbLigne = 0, nbCol = 0, maxNbCol = 0, cmp_piece = 0;

  if (fichier != NULL)
  {
    while (fgets(chaine, TAILLE_MAX, fichier) != NULL)
    {
    
      
      printf("%s\n", chaine);

      if(strcmp(chaine,"\n")) // Compare si la ligne n'est pas vide
      {
        nbLigne++;
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
        printf("la taille de piece que j'ai lu est (%d, %d)\n",nbLigne,maxNbCol);
        nbLigne = 0;
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
  	printf("Impossible d'ouvrir Configuration.txt\n");
  }
  return cmp_piece;
}

int readFile(int ***tableau)
{
  
  FILE* fichier = NULL;
  fichier = fopen("Configuration.txt", "r");
  char chaine[TAILLE_MAX] = "";
  int nbLigne = 0, nbCol = 0, maxNbCol = 0, cmp_piece = 0;

  if (fichier != NULL)
  {
    while (fgets(chaine, TAILLE_MAX, fichier) != NULL)
    {
    
      if(cmp_piece>=1)
      { 
        if(strcmp(chaine,"\n") && strlen(chaine)>0) // Compare si la ligne n'est pas vide
        {
          for(unsigned int i=0; i<strlen(chaine);i++)
          {
            if(chaine[i] == '#')
            {
              tableau[cmp_piece-1][nbLigne][i]=1;
            }
            if(chaine[i] == ' ')
            {
              tableau[cmp_piece-1][nbLigne][i]=0;
            }
          }
          nbLigne++;
        }
      }
      if(!strcmp(chaine,"\n"))
        {
          cmp_piece++; 
          nbLigne = 0;
        }
    }
    fclose(fichier);
  } 
  else
  {
    printf("Impossible d'ouvrir Configuration.txt\n");
  }
  return cmp_piece;
}

int readFile(Liste l)
{
  FILE* fichier = NULL;
  fichier = fopen("Configuration.txt", "r");
  char chaine[TAILLE_MAX] = "";
  int nbLigne = 0, nbCol = 0, maxNbCol = 0, cmp_piece = 0;

  if (fichier != NULL)
  {
    while (fgets(chaine, TAILLE_MAX, fichier) != NULL)
    {
      if(cmp_piece>=1)
      { 
        Piece* p = iniPiece(20);
        p->id = cmp_piece-1; //cmp_piece
        int taille_lig=5, taille_col=5;
        p->tab = allocation2D(taille_lig,taille_col);
        
        if(strcmp(chaine,"\n") && strlen(chaine)>0) // Compare si la ligne n'est pas vide
        {
          for(unsigned int i=0; i<strlen(chaine);i++)
          {
            if(chaine[i] == '#')
            {
              p->tab[nbLigne][i]=1;
            }
            if(chaine[i] == ' ')
            {
              p->tab[nbLigne][i]=0;
            }
          }
          nbLigne++;
        }
      }

      cons(p,l);
      if(!strcmp(chaine,"\n"))
        {
          cmp_piece++; 
          nbLigne = 0;
        }
    }
    fclose(fichier);
  } 
  else
  {
    printf("Impossible d'ouvrir Configuration.txt\n");
  }
  return cmp_piece;
}

int maxNbCol(void)
{
  FILE* fichier = NULL;
  fichier = fopen("Configuration.txt", "r");
  char chaine[TAILLE_MAX] = "";
  int nbCol = 0, maxNbCol = 0, cmp_piece = 0;

  if (fichier != NULL)
  {
    while (fgets(chaine, TAILLE_MAX, fichier) != NULL)
    {

      if(strcmp(chaine,"\n") && cmp_piece > 0) 
      {
        nbCol = nb_occ(chaine,'#');
        if(nbCol > maxNbCol)
        {
          maxNbCol = nbCol;
        }
      }

      if(!strcmp(chaine,"\n"))
      {
        cmp_piece++; 
      }  
      
    
    }
    
    fclose(fichier);
  } 
  else
  {
    printf("Impossible d'ouvrir Configuration.txt\n");
  }
 
  return maxNbCol;
}


int maxNbLigne(void )
{
  
  FILE* fichier = NULL;
  fichier = fopen("Configuration.txt", "r");
  char chaine[TAILLE_MAX] = "";
  int nbLigne = 0, cmp_piece = 0, maxNbLigne = 0;

  if (fichier != NULL)
  {
    while (fgets(chaine, TAILLE_MAX, fichier) != NULL)
    {

      if(strcmp(chaine,"\n") && cmp_piece > 0) 
      {
        nbLigne++;
        if(nbLigne > maxNbLigne)
        {
          maxNbLigne = nbLigne;
        }
      }
  
      if(!strcmp(chaine,"\n"))
      {
        cmp_piece++; 
        nbLigne = 0;
      }  
      
  
    } 
    fclose(fichier);
  } 
  else
  {
    printf("Impossible d'ouvrir Configuration.txt\n");
  }

  return maxNbLigne;
}

