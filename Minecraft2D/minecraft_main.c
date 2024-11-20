#include <stdio.h>
#include <stdlib.h>
#include "ez-draw.h"
#include "minecraft_types.h"
#include "minecraft_core.h"
#include "minecraft_terminal.h"
#include "minecraft_graphics.h"

/**
 * @brief Charge les images des matériaux et du personnage en mémoire
 * 
 * Les images de matériaux sont chargés dans un tableau stocké dans le  
 * champ tiles de la structure des paramètres du jeu. L'image du
 * personnage est chargée dans le champ character de la structure.
 * 
 * @param game_parameters structure où charger les images
 * */
void load_images(Game * game_parameters)
{
    char* images[] = {
        "images/air.png", "images/wood.png", "images/soil.png", "images/rock.png", "images/water.png", 
        "images/gem.png", "images/iron.png", "images/fire.png", "images/grass.png", "images/flower.png", 
        "images/plank.png", "images/money.png", "images/gold.png", "images/ashes.png", "images/unknown.png"
    };
    for(int i = 0; i < NB_MATERIAUX; i++) {
        game_parameters->tiles[i] = ez_image_load(images[i]);
    }
    game_parameters->character = ez_image_load("images/steve.png");
}

/**
 * @brief Alloue la mémoire et initialise la structure des paramètres du jeu
 * 
 * @return la structure initialisée obtenue
 * */
Game * create_game()
{
    Game* game_parameters = malloc(sizeof(Game));

    /* À completer:
     * allouer la mémoire pour les paramètres du jeu et initialiser
     * les différents paramètres pour préparer le lancement du jeu. */

    load_images(game_parameters);
    return game_parameters;
}

/** 
 * @brief Libère la mémoire occupéé par la structure des paramètres du jeu
 * 
 * La structure doit avoir été créée par la fonction create_game
 * 
 * @param game_parameters la structure à détruire
 * */
void free_game(Game * game_parameters)
{
    /* À completer: libérer la mémoire allouée dans create_game */
    free(game_parameters);
}

/**
 * @brief Réaction à l'appui d'une touche dans l'état state_move
 * 
 * @param ev événement généré par l'appui de la touche
 * */
void state_move_process_key(Ez_event* ev) 
{
    Game *game_param = ez_get_data (ev->win);

    /* code ci-dessous à completer */
    switch (ev->key_sym) {
        case XK_Left:
            printf("Move left\n"); 
            break;
        case XK_Right:
            printf("Move right\n"); 
            break;
        case XK_m:
            printf("Mine?\n"); 
            game_param->state = state_mine;
            break;
        case XK_i:
            printf("Enter inventory\n"); 
            game_param->state = state_inventory;
            break;
        case XK_q:
            ez_quit ();
            break;
        default:
            printf("Unknown key in state move\n"); 
    }
}

/**
 * @brief Réaction à l'appui d'une touche dans l'état state_inventory
 * 
 * @param ev événement généré par l'appui de la touche
 * */
void state_inventory_process_key(Ez_event* ev) 
{
    Game *game_param = ez_get_data (ev->win);
    /* code ci-dessous à completer */
    switch (ev->key_sym) {
        case XK_Left:
            printf("Inventory -> left\n"); 
            break;
        case XK_Right:
            printf("Inventory -> right\n"); 
            break;
        case XK_Up:
            printf("Rules -> previous\n"); 
            break;
        case XK_Down:
            printf("Rules -> next\n"); 
            break;
        case XK_c:
            printf("Craft\n"); 
            break;
        case XK_p:
            printf("Place current item?\n"); 
            game_param->state = state_place;
            break;
        case XK_Escape:
            printf("Exit inventory\n"); 
            game_param->state = state_move;
            break;
        default:
            printf("Unknown key in state inventory\n"); 
    }
}

/**
 * @brief Réaction à l'appui d'une touche dans l'état state_mine
 * 
 * @param ev événement généré par l'appui de la touche
 * */
void state_mine_process_key(Ez_event* ev) 
{
    Game *game_param = ez_get_data (ev->win);
    /* code ci-dessous à completer */
    switch (ev->key_sym) {
        case XK_Left:
            printf("Mine left\n"); 
            game_param->state = state_move;
            break;
        case XK_Right:
            printf("Mine right\n"); 
            game_param->state = state_move;
            break;
        case XK_Up:
            printf("Mine up\n"); 
            game_param->state = state_move;
            break;
        case XK_Down:
            printf("Mine down\n"); 
            game_param->state = state_move;
            break;
        case XK_Escape:
            printf("Exit inventory\n"); 
            game_param->state = state_move;
            break;
        default:
            printf("Unknown key in state mine\n"); 
    }
}

/**
 * @brief Réaction à l'appui d'une touche dans l'état state_place
 * 
 * @param ev événement généré par l'appui de la touche
 * */
void state_place_process_key(Ez_event* ev) 
{
    Game *game_param = ez_get_data (ev->win);
    /* code ci-dessous à completer */
    switch (ev->key_sym) {
        case XK_Left:
            printf("Place left\n"); 
            game_param->state = state_move;
            break;
        case XK_Right:
            printf("Place right\n"); 
            game_param->state = state_move;
            break;
        case XK_Up:
            printf("Place uo\n"); 
            game_param->state = state_move;
            break;
        case XK_Down:
            printf("Place down\n"); 
            game_param->state = state_move;
            break;
        case XK_Escape:
            printf("Exit state place\n"); 
            game_param->state = state_move;
            break;
        default:
            printf("Unknown key in state place\n"); 
    }
}

/**
 * @brief Réaction à l'appui d'une touche
 * 
 * En fonction de l'état, la fonction appropriée est appelée
 * 
 * @param ev événement généré par l'appui de la touche
 * */
void win_on_keypress(Ez_event *ev)
{
    Game *game_param = ez_get_data (ev->win);
    printf("Key pressed: %ld\n", ev->key_sym);
    switch (game_param->state) {
        case state_move:
            state_move_process_key(ev);
            break;
        case state_inventory:
            state_inventory_process_key(ev);
            break;
        case state_mine:
            state_mine_process_key(ev);
            break;
        case state_place:
            state_place_process_key(ev);
            break;
        default:
            printf("Unknown state\n");
    }
}

/**
 * @brief Le gestionnaire d'événement du jeu
 * 
 * @param ev événement à gérer
 * */
void win_event (Ez_event *ev)
{
    switch (ev->type) {
        case Expose : /* We must redraw everything */
            win_on_expose(ev);
            break;
        case KeyPress : /* A key was pressed */
            win_on_keypress(ev);
            ez_send_expose(ev->win);
            break;
    }
}

/**
 * @brief Programme principal
 * 
 * @return 0 en cas de fin normale
 * */
int main()
{
    Ez_window win;
    Game * game_parameters = NULL;
    
    if (ez_init() < 0)
        exit(1);

    game_parameters = create_game();

    win = ez_window_create(L_ECRAN, H_ECRAN, "Minecraft 2D", win_event);
    ez_window_dbuf(win, 1);
    ez_set_data (win, game_parameters);
    
    ez_main_loop();

    free_game(game_parameters);
    return 0;
}
