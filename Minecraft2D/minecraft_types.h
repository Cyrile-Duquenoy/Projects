#ifndef MINECRAFT_TYPES_H
#define MINECRAFT_TYPES_H

#include "ez-draw.h"
#include "ez-image.h"

/* ********** *
 * Dimensions *
 * ********** */
#define H_ECRAN 800
#define L_ECRAN 1280
#define TILE_SIZE 64

#define H_TERRAIN 7
#define L_TERRAIN 20

/* ********* *
 * Matériaux *
 * ********* */
#define NB_MATERIAUX 15
#define SYMBOLES_MATERIAUX " T=#~+(&w*!$g.u"

typedef enum
{
    air, wood, soil, rock, water, gem, iron, fire, grass, flower, plank,
    money, gold, ashes, unknown
} Materiau;

/* ********** *
 * Inventaire *
 * ********** */
 /** @brief Inventaire contenant les quantités des matériaux  */
typedef int Inventaire[NB_MATERIAUX];

/* ********************* *
 * Terrain et personnage *
 * ********************* */
typedef Materiau Terrain[H_TERRAIN][L_TERRAIN];

/** @brief Position du personnage */
typedef struct
{
    /** @brief Abscisse dans le terrain */
    int x;
    /** @brief Ordonnée dans le terrain */
    int y;
} Personnage;

/* ****************** *
 * Règles de crafting *
 * ****************** */
/** @brief Règle de crafting */
typedef struct {
    /** @brief tableau des ingrédients */
    int entree[NB_MATERIAUX]; 
    /** @brief tableau des matériaux produits */
    int sortie[NB_MATERIAUX]; 
} Regle;

/* ************************** *
 * Etats et paramètres du jeu *
 * ************************** */
/** @brief États du jeu */
typedef enum {
    /** État où le personnage se déplace et  peut creuser */
    state_move, 
    /** État où il faut choisir une direction pour creuser */
    state_mine, 
    /** État où l'on navigue dans l'inventaire */
    state_inventory,
    /** État où il faut choisir une direction pour poser un matériau de l'inventaire */ 
    state_place 
} State;

/** @brief Paramètres du jeu */
typedef struct {
    /** @brief État courant */
    State state; 
    /** @brief Inventaire */
    Inventaire inventaire;
    /** @brief Indice du matériau courant dans l'inventaire */ 
    int selection; 
    /** @brief Tableau des règles de crafting */
    Regle * regles; 
    /** @brief Taille du tableau de règles */
    int num_regles; 
    /** @brief Indice de la règle courante */
    int regle_selectionnee;
    /** @brief Terrain de jeu */ 
    Terrain terrain; 
    /** @brief Position du personnage */
    Personnage personnage; 
    /** @brief Tableau des images des matériaux */
    Ez_image* tiles[NB_MATERIAUX];
    /** @brief Image du personnage */ 
    Ez_image* character; 
} Game;

#endif
