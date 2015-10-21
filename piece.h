#ifndef PIECE_H 
#define PIECE_H 

//#include "game.h"
#include <SDL/SDL.h>
#define TAILLE_CARRE 20
#define TAILLE_MAX 500

typedef struct piece{
  SDL_Rect coord;
  int taille_carre;
  int ligne;
  int colonne;
  int **tab;
  int id;
  float rotation; 
}Piece;


int ***alloc3D(int taille1,int taille2, int taille3);
void afficherTab(int ***tab,int taille1,int taille2, int taille3);
int **allocation2D(int taille1, int taille2);
void afficherTab2D(int **tab,int taille1,int taille2);
void chargePiece(SDL_Surface *ecran, int ***tab,int taille1,int taille2, int taille3);
void freeTab(int ***tab,int taille3,int taille2);
Piece* iniPiece(int taille);
int maxNbCol(void);
int maxNbLigne(void );
int nb_occ( char *T,char b);

#endif
