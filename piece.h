#ifndef PIECE_H 
#define PIECE_H 

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


int **allocation2D(int taille1, int taille2);
void afficherTab2D(int **tab,int taille1,int taille2);
void freeTab(int ***tab,int taille3,int taille2);
Piece* iniPiece(int taille);
int nb_occ( char *T,char b);

#endif
