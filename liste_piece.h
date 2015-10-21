#ifndef LISTE_PIECE_H 
#define LISTE_PIECE_H

#include "piece.h"

typedef struct Liste *liste;
typedef struct Liste
{
  Piece* premier ;
  liste suivant ;
};


liste l_vide (void) ;
liste cons (Piece* x, liste L) ;
int est_vide (liste L) ;
Piece* tete (liste L) ;
liste reste (liste L) ;

void liberer_liste (liste L) ;
void ecrire_tete (Piece* x, liste L) ;
void ecrire_reste (liste R, liste L) ;
liste inserer_liste_D (unsigned int n, Piece* x, liste L);
void repeter_elements_D (liste L);
liste repeter_elements (liste L);
liste renverser (liste L);
//void afficher_liste (liste L);
unsigned int longueurI (liste L);
unsigned int longueurR (liste L);

#endif
