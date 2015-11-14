#include "game.h"

void update_events(int condition, SDL_Surface *ecran, liste l)
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
      case SDL_MOUSEMOTION:
        case SDL_MOUSEBUTTONUP:
          pos_souris_sur_piece(event.motion.x,event.motion.y,l);
          break;
        break;                          
    }

    SDL_Flip(ecran);
  }
} 

int compter_piece(void )
{
  
  FILE* fichier = NULL;
  fichier = fopen("Configuration.txt", "r");
  char chaine[TAILLE_MAX] = "";
  int nbLigne = 0, nbCol = 0, maxNbCol = 0, cmp_piece = 0;

  if (fichier != NULL)
  {
    while (fgets(chaine, TAILLE_MAX, fichier) != NULL)
    {
    

      if(strcmp(chaine,"\n")) // Compare si la ligne n'est pas vide
      {
        nbLigne++;
        nbCol = nb_occ(chaine,'#');
        if(nbCol > maxNbCol)
        {
          maxNbCol = nbCol;
        }
      }

      if(!strcmp(chaine,"\n"))
      {
        cmp_piece++; 
        //printf("ligne vide, j'ai fini une piece et je commence une nouvelle\n");
        //printf("la taille de piece que j'ai lu est (%d, %d)\n",nbLigne,maxNbCol);
        nbLigne = 0;
        maxNbCol = 0;
      }  
      
      
    }
    //printf("j'ai lu %d pieces\n",cmp_piece);
    
    fclose(fichier);
  }else{
  	printf("Impossible d'ouvrir Configuration.txt\n");
  }
  return cmp_piece;
}


liste tab2D_piece(liste l)
{
  FILE* fichier = NULL;
  fichier = fopen("Configuration.txt", "r");
  char chaine[TAILLE_MAX] = "";
  int nbLigne = 0, cmp_piece = 0;
  liste l1 = l;

  if (fichier != NULL)
  {

    while (fgets(chaine, TAILLE_MAX, fichier) != NULL)
    {
      
      if(cmp_piece >= 1)
      { 
        
        if(strcmp(chaine,"\n") && strlen(chaine)>0) 
        {
          for(unsigned int i=0; i<strlen(chaine);i++)
          {
            if(chaine[i] == '#')
            {
              l1->premier->tab[nbLigne][i]=1;
            }
            if(chaine[i] == ' ')
            {
              l1->premier->tab[nbLigne][i]=0;
            }
          }
          nbLigne++;
        }   
      }
 

      if(!strcmp(chaine,"\n"))
      {
        if(cmp_piece >= 1 ){
          printf("Piece %d\n", l1->premier->id);
          afficherTab2D(l1->premier->tab,l1->premier->ligne,l1->premier->colonne);
          l1 = reste(l1);   
        }
        if(!est_vide(l1)){
          printf("l1->premier->ligne %d\n", l1->premier->ligne);
          printf("l1->premier->colonne %d\n", l1->premier->colonne);
          l1->premier->tab = allocation2D(l1->premier->ligne,l1->premier->colonne);
        }
        

        cmp_piece++; 
        nbLigne = 0;

      }


    }
    fclose(fichier);
  }else{
    printf("Impossible d'ouvrir Configuration.txt\n");
  }
  return l;
}


liste lig_col_piece(liste l)
{
  FILE* fichier = NULL;
  fichier = fopen("Configuration.txt", "r");
  char chaine[TAILLE_MAX] = "";
  int nbLigne = 0, nbCol = 0, maxNbCol = 0, cmp_piece = 0;
  Piece* p;

  if (fichier != NULL)
  {
    while (fgets(chaine, TAILLE_MAX, fichier) != NULL)
    {
      if(cmp_piece >= 1){
        if(strcmp(chaine,"\n") && strlen(chaine)>0)
        {
          
            nbLigne++;
            nbCol = nb_occ(chaine,'#') + nb_occ(chaine,' ') ;
            if(nbCol > maxNbCol)
            {
              maxNbCol = nbCol;
            }
          
        }
      }

      if(!strcmp(chaine,"\n"))
      {
        if(cmp_piece >= 1){
          p = iniPiece(20);
          p->id = cmp_piece - 1;
          p->ligne = nbLigne;
          p->colonne = maxNbCol;
          l = cons(p,l);
          nbLigne = 0;
          maxNbCol = 0; 
        }

        cmp_piece++;
      }  
      
      
    }
    
    fclose(fichier);
  }else{
    printf("Impossible d'ouvrir Configuration.txt\n");
  }
  return l;
}

void chargePiece(SDL_Surface* ecran, liste l){
  liste l1 = l;
  int i,j;
  int premier_coord_x = 10;
  int coeff_pos_y = 1;
  int coeff_pos_x = 6;
  SDL_Surface *carreR = NULL;
  
  carreR = SDL_CreateRGBSurface(SDL_HWSURFACE, TAILLE_CARRE, TAILLE_CARRE, 32, 0, 0, 0, 0);
  SDL_FillRect(carreR, NULL, SDL_MapRGB(ecran->format, 255, 0, 0));

  while(!est_vide(l1)){
  
    if(l1->premier->id >= 1){
      l1->premier->coord.y += (coeff_pos_y*l1->premier->taille_carre);
    }
    if(l1->premier->coord.y >= 720 - (l1->premier->ligne * l1->premier->taille_carre)){
      l1->premier->coord.y = 10;
      coeff_pos_y = 1;
      premier_coord_x = (coeff_pos_x* l1->premier->taille_carre);
      coeff_pos_x += 6;
    }

    for( i = 0; i < l1->premier->ligne; i++)
    {
      l1->premier->coord.y += l1->premier->taille_carre;
      l1->premier->coord.x = premier_coord_x;
      if(l1->premier->coord.x >= 1280){
        //reduire taille carré
        if(l1->premier->taille_carre -5 > 0){
          l1->premier->taille_carre -= 5;
        }

      } 
      for(j = 0; j < l1->premier->colonne; j++)
      {
        l1->premier->coord.x += l1->premier->taille_carre;
        if(l1->premier->tab[i][j] == 1){
          SDL_BlitSurface(carreR, NULL, ecran, &l1->premier->coord);
        }     
          
      }
    }
    coeff_pos_y += 5;
    l1 = reste(l1);
  }
  SDL_FreeSurface(carreR);  
}

void pos_souris_sur_piece(int pos_souris_x,int pos_souris_y, liste l){
  liste l1 = l;
  while(!est_vide(l1)){
    //printf("pos_souris_x = %d\n",pos_souris_x );
    //printf("pos_souris_y = %d\n",pos_souris_y );
    if(pos_souris_x >= l1->premier->coord.x && pos_souris_x 
      <= ((l1->premier->colonne * l1->premier->taille_carre) + 
        l1->premier->coord.x)){
      if(pos_souris_y >= l1->premier->coord.y && pos_souris_y
        <= ((l1->premier->ligne * l1->premier->taille_carre) + 
        l1->premier->coord.y)){
          printf("piece %d\n",l1->premier->id);
          l1->premier->coord.x = pos_souris_x;
          l1->premier->coord.y = pos_souris_y;
          printf("l1->premier->coord.x = %d\n", l1->premier->coord.x);
          printf("l1->premier->coord.y = %d\n", l1->premier->coord.y);
      }
    }
    l1 = reste(l1);
  }
}