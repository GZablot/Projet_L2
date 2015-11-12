#ifndef GAME_H 
#define GAME_H 

#include "liste_piece.h"
#include "piece.h"
#include <SDL/SDL.h>

void update_events(int condition);
int compter_piece(void );
void lecture_fichier_tab3D(int ***tableau);
liste tab2D_piece(liste l);
liste lig_col_piece(liste l);
void chargePiece(SDL_Surface* ecran, liste l);

#endif