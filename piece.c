#include "piece.h"

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

int nb_occ( char *T,char b)
{
 unsigned int i;
 int nb = 0;
 for(i = 0 ; i < strlen(T); i++)
    if(T[i] == b) 
      nb++;
 return nb;
}


int ***alloc3D(int taille1,int taille2, int taille3)
{
  int ***tab;
  int i,j,k;

  tab = malloc(taille1 * sizeof(*tab));

  if(tab == NULL){
    printf("Erreur allocation3D\n");
    return (int***)-1;
  }        
            

  for(i=0 ; i < taille1 ; i++)
  {

    tab[i] = malloc(taille2 * sizeof(**tab));

    if( tab[i] == NULL){
        printf("Erreur allocation3D\n");
      return (int***)-1;    
    }
    
  }

  for(i=0 ; i < taille1 ; i++)
  {
    for(j=0 ; j < taille2 ; j++)
    {
      tab[i][j] = malloc(taille3 * sizeof(***tab));

      if(tab[i][j] == NULL){
        printf("Erreur allocation3D\n");
        return (int***)-1;      
      }
           
    }

  }
  for(i = 0;i < taille1; i++)
  {
    for(j = 0;j < taille2; j++)
    {
      for(k = 0;k < taille3; k++)
      {
        tab[i][j][k] = 0;
      }
    }
  }

  return tab;

}

int **allocation2D(int taille1, int taille2)
{
  int **tab;
  int i,j;

  tab = malloc(taille1 * sizeof(*tab));
  if(tab == NULL){
    printf("Erreur allocation2D\n");
    return (int**)-1;
  } 

  for(i=0 ; i < taille1 ; i++)
  {

    tab[i] = malloc(taille2 * sizeof(**tab));

    if( tab[i] == NULL){
      printf("Erreur allocation2D\n");
      return (int**)-1;    
    }

  }
  for(i = 0;i < taille1; i++)
  {
    for(j = 0;j < taille2; j++)
    {     
      tab[i][j] = 0;   
    }
  }
  return tab;
}

void afficherTab2D(int **tab,int taille1,int taille2)
{
  int i,j;
  printf("\n");
  for(i = 0; i < taille1; i++)
  {
    for(j = 0; j < taille2; j++)
    {
      printf("%d ",tab[i][j]);
    }
    printf("\n");
  }
}

void afficherTab(int ***tab,int taille1,int taille2, int taille3)
{
  int i,j,k;
  for(i = 0; i < taille1; i++)
  {
    printf("piece[%d] :\n", i );
    for(j = 0; j < taille2; j++)
    {
      for(k = 0; k < taille3; k++)
      {
        printf("%d ",tab[i][j][k]);
      }
      printf("\n");
    }
  }
}


Piece* iniPiece(int taille)
{
  Piece* p = malloc(sizeof(Piece));
  p->coord.x = 10;
  p->coord.y = 10;
  p->coord.h = 0;
  p->coord.w = 0;

  p->taille_carre = taille;

  p->ligne = 0;

  p->colonne = 0;

  p->tab = NULL;

  p->id = 0;

  p->rotation = .0;
  
  return p;
}


/*void freeTab2D(int **tab,int taille 2)
{

}*/

void freeTab(int ***tab,int taille3,int taille2)
{

  int i,j,k;
  for(i=0 ; i < taille3 ; i++)
  {

    for(j=0 ; j < taille2 ; j++)
    {
      free(tab[i][j]);
    }
    free(tab[i]);
  }
  free(tab);
}
