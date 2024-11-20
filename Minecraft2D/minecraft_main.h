#ifndef MINECRAFT_MAIN_H
#define MINECRAFT_MAIN_H
 
#include "minecraft_types.h"

/* initialisation et fin du jeu */
void load_images(Game * game_parameters);
Game * create_game();
void free_game(Game * game_parameters);

/* traiter les touches en fonction de l'etat du jeu */
void state_move_process_key(Ez_event* ev);
void state_inventory_process_key(Ez_event* ev);
void state_mine_process_key(Ez_event* ev);
void state_place_process_key(Ez_event* ev);

/* traiter les evenements */
void win_on_keypress(Ez_event *ev);
void win_event (Ez_event *ev);
 
#endif
