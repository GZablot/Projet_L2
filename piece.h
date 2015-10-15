#include <SDL/SDL.h>


typedef struct Piece{
  SDL_Rect coord;
  int taille_carre; 
}Piece;

int ***alloc3D(int taille1,int taille2, int taille3);
void afficherTab(int ***tab,int taille1,int taille2, int taille3);
void chargePiece(SDL_Surface *ecran, int ***tab,int taille1,int taille2, int taille3);
void freeTab(int ***tab,int taille3,int taille2);
