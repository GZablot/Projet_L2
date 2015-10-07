#include <SDL/SDL.h>


typedef struct Object{
  SDL_Rect coord;
  
}Object;

int *** alloc3D(int taille1,int taille2, int taille3);
void afficherTab(int ***tab,int taille1,int taille2, int taille3);
