#ifndef DEF_LISTE_PIECE 
#define DEF_LISTE_PIECE
#include "liste_piece.h"
#endif
#ifndef DEF_GAME 
#define DEF_GAME 
#include "game.h"
#endif
#include <SDL/SDL.h>


liste l_vide ()
{
  return NULL ;
}

liste cons (Piece* x, liste L)
{
  liste M ;
  M = malloc (sizeof (*M)) ;
  M->premier = x ; 
  M->suivant = L ;
  return M ;
}

/* Accès */
int est_vide (liste L)
{
   if(L == NULL){
    return 1;
   }else{
    return 0;
   } 
}

int tete (liste L)
{
  if (est_vide (L))
    {
      printf ("Calcul de tete sur liste vide !\n") ;
      exit (0) ;
    }
  return L->premier ;
}

liste reste (liste L)
{
  return L->suivant ;
}

/* Autres opérations primitives (hors type-abstrait) */
void liberer_liste (liste L)
{
  if (est_vide (L))
    {
      return ;
    }
  liberer_liste (reste (L)) ;
  free(L) ;
}

void ecrire_tete (Piece* x, liste L)
{
  L->premier = x ;
}

void ecrire_reste (liste R, liste L)
{
  L->suivant = R ;
}

/* OPERATIONS NON PRIMITIVES */
unsigned int longueurR (liste L)
{
  if (est_vide (L))
    return 0 ;
  return 1 + longueurR (reste (L)) ;
}

unsigned int longueurI (liste L)
{
  unsigned int lg ;
  lg = 0 ;
  while (!est_vide (L))
    {
      lg = lg + 1 ;
      L = reste (L) ;
    }
  return lg ;
}

void afficher_liste (liste L)
{
  printf ("(") ;
  while (!est_vide (L))
    {
      printf ("%d%s",
	      prem (L),
	      (est_vide (reste(L)) ? "" : " ")) ;
      L = reste (L) ;
    }
  printf (")") ;
}

liste renverser (liste L)
{
  liste R, M ;
  R = l_vide () ;
  M = L ;
  while (!est_vide(M))
    {
      R = cons (prem(M), R) ;
      M = reste (M) ;
    }
  return R ;
}

/* Opération non destructrice */
liste repeter_elements (liste L)
{
  Piece* x ;
  if (est_vide (L))
    {
      return l_vide () ;
    }
  x = prem (L) ;
  return cons (x, cons (x, repeter_elements (reste(L)))) ;
}

/* Opération destructrice */
void repeter_elements_D (liste L)
{
  Piece* x ;
  if (est_vide (L))
    {
      return ;
    }
  x = prem (L) ;
  ecrire_reste (cons (x, reste (L)), L) ;
  repeter_elements_D (reste (reste (L))) ;
}


liste inserer_liste_D (unsigned int n, Piece* x, liste L)
{
  unsigned int i ;
  liste M ;
  if (n == 0 || est_vide(L))
    {
      printf ("Utilisation d'inserer_liste_D incorrecte\n") ;
      exit(EXIT_FAILURE) ;
    }
  if (n == 1)
    {
      return cons (x, L) ;
    }
  M = L ;
  i = 1 ;
  while (!est_vide(reste(M)) && i < n - 1) {
      M = reste(M) ;
      i = i + 1 ;
  }
  ecrire_reste (cons(x, reste(M)), M) ;
  return L ;
}
