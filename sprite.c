#ifndef DEF_SPRITE 
#define DEF_SPRITE 
#include "sprite.h"
#endif
#include <SDL/SDL.h>







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