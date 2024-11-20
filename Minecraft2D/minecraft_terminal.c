#include "minecraft_types.h"
#include "minecraft_core.h"
#include "minecraft_terminal.h"

/* ************************************************ *
 * Toutes les fonctions d'affichage en mode console *
 * ************************************************ */

/**
 * @brief Affiche le nom d'un matériau dans la console
 * 
 * @param matériau à afficher
 * */
void affiche_materiau(Materiau m)
{
    switch (m)
    {
        case air:
            printf("air");
            break;
        case wood:
            printf("wood");
            break;
        case soil:
            printf("soil");
            break;
        case rock:
            printf("rock");
            break;
        case water:
            printf("water");
            break;
        case gem:
            printf("gem");
            break;
        case iron:
            printf("iron");
            break;
        case fire:
            printf("fire");
            break;
        case grass:
            printf("grass");
            break;
        case flower:
            printf("flower");
            break;
        case plank:
            printf("plank");
            break;
        case money:
            printf("money");
            break;
        case gold:
            printf("gold");
            break;
        case ashes:
            printf("ashes");
            break;
        case unknown:
        default:
            printf("Unknown material");
    }
}

/**
 * @brief Affiche un tableau d'entiers dans la console
 * 
 * @param t tableau à afficher
 * @param n taille du tableau
 * */
void affiche_tableau(int t[], int n)
{
    int i;
    if (n > 0)
    {
        for (i = 0; i < n; i++)
            printf("|%3d", t[i]);
        printf("|\n");
    }
    else
        printf("\n");
}

/**
 * @brief Affiche un inventaire comme un tableau dans la console
 * 
 * @param inventaire inventaire, sous la forme d'un tableau de quantités
 * pour chaque matériau
 * */
void affiche_inventaire_tab(int inventaire[NB_MATERIAUX])
{
    affiche_tableau(inventaire, NB_MATERIAUX);
}

/**
 * @brief Affiche un inventaire avec caractères et quantités dans la console
 * 
 * @param inventaire inventaire, sous la forme d'un tableau de quantités
 * pour chaque matériau
 * */
void affiche_inventaire_symboles(int inventaire[NB_MATERIAUX])
{
    int i;
    affiche_inventaire_tab(inventaire);
    for (i = 0; i < NB_MATERIAUX; i++)
        printf("| %c ", Materiau2char(i));
    printf("|\n");
}

/**
 * @brief Affiche un terrain et un personnage dans la console
 * 
 * @param terrain le terrain à afficher
 * @param p le personnage à afficher
 * */
void affiche_monde(Terrain terrain, Personnage p)
{
    int i, j;
    for (j = 0; j < L_TERRAIN; j++)
        printf("-");
    printf("\n");
    for (i = 0; i < H_TERRAIN; i++)
    {
        for (j = 0; j < L_TERRAIN; j++)
        {
            if (p.x == j && p.y == i)
                printf("@");
            else
                printf("%c", Materiau2char(terrain[i][j]));
        }
        printf("\n");
    }
    for (j = 0; j < L_TERRAIN; j++)
        printf("-");
    printf("\n");
}

/**
 * @brief Affiche une règle dans la console
 * 
 * @param règle à afficher
 * */
void affiche_regle(Regle regle)
{
    int i;
    printf("Entrees :");
    for(i = 0; i < NB_MATERIAUX; i++) {
        if(regle.entree[i] > 0) printf(" %c (x%d)", Materiau2char(i), regle.entree[i]);
    }
    printf("\n");
    printf("Sorties :");
    for(i = 0; i < NB_MATERIAUX; i++) {
        if(regle.sortie[i] > 0) printf(" %c (x%d)", Materiau2char(i), regle.sortie[i]);
    }
    printf("\n");
}

/**
 * @brief Affiche le numéro d'un état dans la console
 * 
 * @param game_parameters structure contenant les paramètres du jeu
 * */
void affiche_etat(Game * game_parameters)
{
    switch (game_parameters->state) {
        case state_move:
            printf("Current state: move\n");
            break;
        case state_inventory:
            printf("Current state: inventory\n");
            break;
        case state_mine:
            printf("Current state: mine\n");
            break;
        case state_place:
            printf("Current state: place\n");
            break;
        default:
            printf("Unknown state\n");
    }
}
