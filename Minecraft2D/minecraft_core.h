#ifndef MINECRAFT_CORE_H
#define MINECRAFT_CORE_H
 
#include "minecraft_types.h"

/* Fonctions relatives aux materiaux */
char Materiau2char(Materiau m);
Materiau char2Materiau(char c);

/* Fonctions relatives au terrain */
void cree_terrain_vide(Terrain terrain);
void cree_terrain_par_defaut(Terrain terrain);
int lit_terrain(char* filename, Terrain terrain);

/* Sauver et lire l'etat du jeu */
int lit_etat_jeu(char* filename, Game* game);
int ecrit_etat_jeu(char* filename, Game* game);

/* Fonctions relatives aux regles */
Regle char2Regle(char entree[], char sortie[]);
int verifie_regle(Regle regle, Inventaire inventaire);
int applique_regle(Regle regle, Inventaire inventaire);

int compte_lignes(char * filename);
Regle * lit_regles(char * filename, int* num_regles);

/* Fonctions relatives a l'inventaire */
void cree_inventaire_vide(Inventaire inventaire);

/* Fonctions relatives au personnage */
Personnage positionne_personnage(Terrain terrain);
Personnage mouvement_droite(Terrain terrain, Personnage p);
Personnage mouvement_gauche(Terrain terrain, Personnage p);

#endif
