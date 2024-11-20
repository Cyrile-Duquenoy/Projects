#ifndef MINECRAFT_TERMINAL_H
#define MINECRAFT_TERMINAL_H
 
#include "minecraft_types.h"

/* Toutes les fonctions d'affichage en mode console */

void affiche_materiau(Materiau m);
void affiche_inventaire_symboles(int inventaire[NB_MATERIAUX]);
void affiche_monde(Terrain terrain, Personnage p);
void affiche_regle(Regle regle);
void affiche_etat(Game * game_parameters);


#endif
