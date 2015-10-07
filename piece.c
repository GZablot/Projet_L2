#ifndef DEF_PIECE 
#define DEF_PIECE 
#include "piece.h"
#endif
#include <SDL/SDL.h>


/*void tabPieceStocke()
{
  
}*/

int *** alloc3D(int taille1,int taille2, int taille3)
{
  int ***ptr;

  int i,j,k;


ptr = malloc(taille1 * sizeof(*ptr));

if(ptr == NULL)          //Pas de libération de mémoire à ce niveau

     return -1;          //Exemple de code d'erreur


for(i=0 ; i < taille1 ; i++){

     ptr[i] = malloc(taille2 * sizeof(**ptr));

     if( ptr[i] == NULL) //Pensez à libérer la mémoire déjà allouée et fermer le programme.

          return -1;     //Exemple de code d'erreur

}

for(i=0 ; i < taille1 ; i++){

     for(j=0 ; j < taille2 ; j++){

           ptr[i][j] = malloc(taille3 * sizeof(***ptr));

           if(ptr[i][j] == NULL)   //Pensez à libérer correctement la mémoire déjà allouée

                return -1;           //Exemple de code d'erreur

     }

}

  for(i=0;i<taille1;i++)
  {
    for(j=0;j<taille2;j++)
    {
      for(k=0;k<taille3;k++)
      {
        ptr[i][j][k] = 0;
      }
    }
  }
return ptr;
}

void afficherTab(int ***tab,int taille1,int taille2, int taille3)
{
  int i,j,k;
  for(i=0;i<taille1;i++)
  {
    printf("piece[%d] :\n", i );
    for(j=0;j<taille2;j++)
    {
      for(k=0;k<taille3;k++)
      {
        printf("%d ",tab[i][j][k]);
      }
      printf("\n");
    }
  }
}