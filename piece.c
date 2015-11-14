#include "piece.h"


int nb_occ( char *T,char b)
{
 unsigned int i;
 int nb = 0;
 for(i = 0 ; i < strlen(T); i++)
    if(T[i] == b) 
      nb++;
 return nb;
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
