#include <SDL/SDL.h>

typedef struct Liste
{
  Piece* premier ;
  liste suivant ;
}*liste;


liste l_vide () ;
liste cons (Piece* x, liste L) ;
bool est_vide (liste L) ;
int tete (liste L) ;
liste reste (liste L) ;

void liberer_liste (liste L) ;
void ecrire_tete (Piece* x, liste L) ;
void ecrire_reste (liste R, liste L) ;