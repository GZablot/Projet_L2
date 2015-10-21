#ifndef GAME_H 
#define GAME_H 

#include "liste_piece.h"
#include "piece.h"
#include <SDL/SDL.h>

void update_events(int condition);
int compter_piece(void );
void lecture_fichier_tab3D(int ***tableau);
void lecture_fichier_tab2D(liste l);
void lig_col_piece(Piece *p, liste l);

#endif