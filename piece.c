#ifndef DEF_PIECE 
#define DEF_PIECE 
#include "piece.h"
#endif
#ifndef DEF_GAME 
#define DEF_GAME 
#include "game.h"
#endif
#include <SDL/SDL.h>
#define TAILLE_CARRE 20


int ***alloc3D(int taille1,int taille2, int taille3)
{
  int ***tab;
  int i,j,k;

  tab = malloc(taille1 * sizeof(*tab));

  if(tab == NULL)          //Pas de libération de mémoire à ce niveau

    return (int ***)-1;          //Exemple de code d'erreur

  for(i=0 ; i < taille1 ; i++)
  {

    tab[i] = malloc(taille2 * sizeof(**tab));

    if( tab[i] == NULL) //Pensez à libérer la mémoire déjà allouée et fermer le programme.

      return (int ***)-1;     //Exemple de code d'erreur
  }

  for(i=0 ; i < taille1 ; i++)
  {
    for(j=0 ; j < taille2 ; j++)
    {
      tab[i][j] = malloc(taille3 * sizeof(***tab));

      if(tab[i][j] == NULL)   //Pensez à libérer correctement la mémoire déjà allouée

        return (int ***)-1;          
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

void chargePiece(SDL_Surface *ecran, int ***tab,int taille1,int taille2, int taille3)
{
  SDL_Rect posCarreR;
  posCarreR.x = 10;
  posCarreR.y = 10;

  SDL_Surface *carreR = NULL;

  carreR = SDL_CreateRGBSurface(SDL_HWSURFACE, TAILLE_CARRE, TAILLE_CARRE, 32, 0, 0, 0, 0);
  SDL_FillRect(carreR, NULL, SDL_MapRGB(ecran->format, 255, 0, 0));
  

  int i,j,k,posCarreR_x;
  /*SDL_Rect *p_posCarreR = NULL;
  p_posCarreR = &posCarreR;*/
  
  posCarreR_x = 10;

  for( i = 0; i < taille1; i++)
  { 
    //printf("\nPIECE %d\n\n",i);
    if(i >= 1){
      posCarreR.y += ((1 + maxNbLigne())*TAILLE_CARRE);

    }
    if(posCarreR.y >= 720 - ((maxNbLigne())*TAILLE_CARRE) ){
      //printf("dans le if posCarreR.y = %d\n",posCarreR.y);
      posCarreR.y = 10;
      posCarreR_x = posCarreR_x + (1 + maxNbCol())*TAILLE_CARRE;

    }
    if(posCarreR.x >= 1280){
      //reduire taille carré

    }  
    for(j = 0; j < taille2; j++)
    {
      //printf("boucle for posCarreR.y = %d\n",posCarreR.y);

      posCarreR.y += TAILLE_CARRE;
      posCarreR.x = posCarreR_x;

      for(k = 0; k < taille3; k++)
      {
        posCarreR.x += TAILLE_CARRE;

        if(tab[i][j][k] == 1){   
          SDL_BlitSurface(carreR, NULL, ecran, &posCarreR);
        }
      }
     
    }
  }
  SDL_FreeSurface(carreR);
}

Piece* iniPiece(int taille)
{
  Piece* p = malloc(sizeof(Piece));
  p->coord.x = 0;
  p->coord.y = 0;
  p->coord.h = 0;
  p->coord.w = 0;

  p->taille_carre = taille;

  p->ligne = 0;

  p->colonne

  p->tab=NULL;

  p->id = 0;

  p->rotation = .0;
  
  return p;
}




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
