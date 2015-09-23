#include <SDL/SDL.h>
#ifndef DEF_SPRITE 
#define DEF_SPRITE 
#include "sprite.h"
#endif
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  SDL_Surface *screen = NULL, *background = NULL, *ball = NULL;
  SDL_Rect backgroundPosition, ballPosition;
  int gameover = 0;

  backgroundPosition.x = 0;
  backgroundPosition.y = 0;
  ballPosition.x = 365 ;
  ballPosition.y = 150;

   SDL_Init(SDL_INIT_VIDEO);

   if (SDL_Init(SDL_INIT_VIDEO) == -1){

     fprintf(stderr, "Initialization Error of SDL : %s\n", SDL_GetError());

     exit(EXIT_FAILURE);
   }


   screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

   if (screen == NULL){

		fprintf(stderr, "Impossible to load video mode : %s\n", SDL_GetError());

        exit(EXIT_FAILURE);
	}

   SDL_WM_SetCaption("Football Game", NULL);

   background = SDL_LoadBMP("background.bmp");
   SDL_BlitSurface(background, NULL, screen, &backgroundPosition);

   //SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 17, 206, 112));

   ball = SDL_LoadBMP("ball.bmp");
   SDL_SetColorKey(ball, SDL_SRCCOLORKEY, SDL_MapRGB(ball->format, 255, 255, 255));
   SDL_BlitSurface(ball, NULL, screen, &ballPosition);

   SDL_Flip(screen);
   SDL_EnableKeyRepeat(10, 10);

   update_events(gameover);

   SDL_FreeSurface(background);
   SDL_FreeSurface(ball);
   SDL_Quit();

   return EXIT_SUCCESS;
}




