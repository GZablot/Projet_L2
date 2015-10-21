#include "game.h"

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
        //printf("ligne vide, j'ai fini une piece et je commence une nouvelle\n");
        //printf("la taille de piece que j'ai lu est (%d, %d)\n",nbLigne,maxNbCol);
        nbLigne = 0;
        maxNbCol = 0;
      }  
      
      
    }
    //printf("j'ai lu %d pieces\n",cmp_piece);
    
    fclose(fichier);
  }else{
  	printf("Impossible d'ouvrir Configuration.txt\n");
  }
  return cmp_piece;
}

void lecture_fichier_tab3D(int ***tableau)
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
        if(strcmp(chaine,"\n") && strlen(chaine)>0) 
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
  } else{
    printf("Impossible d'ouvrir Configuration.txt\n");
  }
}

void lecture_fichier_tab2D(liste l)
{
  FILE* fichier = NULL;
  fichier = fopen("Configuration.txt", "r");
  char chaine[TAILLE_MAX] = "";
  int nbLigne = 0, nbCol = 0, maxNbCol = 0, cmp_piece = 0;
  Piece* p;

  if (fichier != NULL)
  {
    while (fgets(chaine, TAILLE_MAX, fichier) != NULL)
    {
      if(cmp_piece >= 1)
      { 
            
        if(strcmp(chaine,"\n") && strlen(chaine)>0) 
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
 

      if(!strcmp(chaine,"\n"))
        {
          if(cmp_piece >= 1){
            afficherTab2D(p->tab,5,5);
          }
          
          p = iniPiece(20);
          cons(p,l);
          p->id = cmp_piece;
          int taille_lig = 5, taille_col = 5;
          p->tab = allocation2D(taille_lig,taille_col);
          cmp_piece++; 
          nbLigne = 0;
        }
    }
    fclose(fichier);
  }else{
    printf("Impossible d'ouvrir Configuration.txt\n");
  }
}


void lig_col_piece(Piece *p, liste l)
{
  FILE* fichier = NULL;
  fichier = fopen("Configuration.txt", "r");
  char chaine[TAILLE_MAX] = "";
  int nbLigne = 0, nbCol = 0, maxNbCol = 0, cmp_piece = 0;

  if (fichier != NULL)
  {
    while (fgets(chaine, TAILLE_MAX, fichier) != NULL)
    {

      if(strcmp(chaine,"\n"))
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
        p->ligne = nbLigne;
        p->colonne = maxNbCol;
        //modifier valeur des pieces dans la liste , là ça modifie qu'un piece pas dans la liste 
        nbLigne = 0;
        maxNbCol = 0;

      }  
      
      
    }
    
    fclose(fichier);
  }else{
    printf("Impossible d'ouvrir Configuration.txt\n");
  }
}