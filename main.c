#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

void pause(void);

int main(int argc, char *argv[])
{
   SDL_Init(SDL_INIT_VIDEO);

   if (SDL_Init(SDL_INIT_VIDEO) == -1){

     fprintf(stderr, "Initialization Error of SDL : %s\n", SDL_GetError());

     exit(EXIT_FAILURE);
   }

   SDL_Surface *screen = NULL;

   screen = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);

   if (screen == NULL){

		fprintf(stderr, "Impossible to load video mode : %s\n", SDL_GetError());

        exit(EXIT_FAILURE);
	}

   SDL_WM_SetCaption("Football Game", NULL);

   //SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 17, 206, 112));

   SDL_Flip(screen);

   pause();

   SDL_Quit();

   return EXIT_SUCCESS;
}



void pause(void)
{
	int continuer = 1;
	SDL_Event event;

 	while (continuer)
	{
		SDL_WaitEvent(&event);
		switch(event.type)
		{
			case SDL_QUIT:
				continuer = 0;
		}
	}
}