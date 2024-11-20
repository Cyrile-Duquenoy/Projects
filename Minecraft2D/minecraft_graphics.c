#include "minecraft_types.h"
#include "minecraft_terminal.h"
#include "minecraft_core.h"

/**
 * @brief Traçage du terrain dans la fenêtre graphique
 * 
 * @param ev événement ayant déclenché l'affichage
 * */
void dessine_monde(Ez_event *ev) 
{
    Game* game = (Game*) ez_get_data(ev->win);
    /* a completer */
}

/**
 * @brief Traçage de l'inventaire dans la fenêtre graphique
 * 
 * @param ev événement ayant déclenché l'affichage
 * */
void dessine_inventaire(Ez_event *ev) 
{
    Game* game = (Game*) ez_get_data(ev->win);
    /* a completer */
}

/**
 * @brief Traçage du personnage dans la fenêtre graphique
 * 
 * @param ev événement ayant déclenché l'affichage
 * */
void dessine_personnage(Ez_event *ev) 
{
    Game* game = (Game*) ez_get_data(ev->win);
    /* a completer */
}

/**
 * @brief Traçage de la règle courante dans la fenêtre graphique
 * 
 * @param ev événement ayant déclenché l'affichage
 * */
void dessine_regle(Ez_event *ev) 
{
    Game* game = (Game*) ez_get_data(ev->win);
    /* a completer */
}

/**
 * @brief Traçage d'informations supplémentaires dans la fenêtre graphique
 * 
 * Trace les instructions à afficher à l'écran et tout texte utile
 * 
 * @param ev événement ayant déclenché l'affichage
 * */
void dessine_infos(Ez_event *ev) 
{
    Game* game = (Game*) ez_get_data(ev->win);
    /* a completer */
}

/**
 * @brief Affichage de l'ensemble de la fenêtre graphique
 * 
 * Cette fonction est appelée depuis la fonction de gestion d'événements
 * à chaque fois que la fenêtre graphique doit être redessinée. Elle 
 * retrace tous les éléments en appelant les fonctions dédiées.
 * 
 * @param ev événement ayant déclenché l'affichage
 * */
void win_on_expose(Ez_event *ev)
{
    /* a completer */
}

