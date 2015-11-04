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

liste tab2D_piece(liste l)
{
  FILE* fichier = NULL;
  fichier = fopen("Configuration.txt", "r");
  char chaine[TAILLE_MAX] = "";
  int nbLigne = 0, cmp_piece = 0;
  liste l1 = l;

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
              l1->premier->tab[nbLigne][i]=1;
            }
            if(chaine[i] == ' ')
            {
              l1->premier->tab[nbLigne][i]=0;
            }
          }
          nbLigne++;
        }   
      }
 

      if(!strcmp(chaine,"\n"))
      {
        if(cmp_piece >= 1 ){
          printf("Piece %d\n", l1->premier->id);
          afficherTab2D(l1->premier->tab,l1->premier->ligne,l1->premier->colonne);
          l1 = reste(l1);   
        }
        if(!est_vide(l1)){
          printf("l1->premier->ligne %d\n", l1->premier->ligne);
          printf("l1->premier->colonne %d\n", l1->premier->colonne);
          l1->premier->tab = allocation2D(l1->premier->ligne,l1->premier->colonne);
        }
        

        cmp_piece++; 
        nbLigne = 0;

      }


    }
    fclose(fichier);
  }else{
    printf("Impossible d'ouvrir Configuration.txt\n");
  }
  return l;
}


liste lig_col_piece(liste l)
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
      if(cmp_piece >= 1){
        if(strcmp(chaine,"\n") && strlen(chaine)>0)
        {
          
            nbLigne++;
            nbCol = nb_occ(chaine,'#') + nb_occ(chaine,' ') ;
            if(nbCol > maxNbCol)
            {
              maxNbCol = nbCol;
            }
          
        }
      }

      if(!strcmp(chaine,"\n"))
      {
        if(cmp_piece >= 1){
          p = iniPiece(20);
          p->id = cmp_piece - 1;
          //printf("\np->id %d\n",p->id );
          p->ligne = nbLigne;
          p->colonne = maxNbCol;
          //printf("p->ligne %d\n",p->ligne );
          //printf("p->colonne %d\n",p->colonne );
          l = cons(p,l);
          nbLigne = 0;
          maxNbCol = 0; 
        }

        cmp_piece++;
      }  
      
      
    }
    
    fclose(fichier);
  }else{
    printf("Impossible d'ouvrir Configuration.txt\n");
  }
  return l;
}