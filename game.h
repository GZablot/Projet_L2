#ifndef GAME_H 
#define GAME_H 

#include "liste_piece.h"
#include "piece.h"
#include <SDL/SDL.h>

void update_events(int condition, SDL_Surface *ecran, liste l);
int compter_piece(void );
liste tab2D_piece(liste l);
liste lig_col_piece(liste l);
void chargePiece(SDL_Surface* ecran, liste l);
void pos_souris_sur_piece(int pos_souris_x,int pos_souris_y, liste l);

#endif