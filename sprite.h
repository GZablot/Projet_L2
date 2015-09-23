#include <SDL/SDL.h>


typedef struct Object{
  SDL_Rect coord;
  int lifetime;
}Object;

void update_events(int condition); 