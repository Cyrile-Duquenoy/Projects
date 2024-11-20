#include "minecraft_types.h"

/* ********************************* *
 * Fonctions relatives aux materiaux *
 * ********************************* */

/** 
 * @brief Convertit un matériau un caractère qui le symbolise
 * 
 * @param m le matériau à convertir
 * @return le caractère qui symbolise le matériau ('u' si matériau inconnu)
 * */
char Materiau2char(Materiau m)
{
    char t[] = SYMBOLES_MATERIAUX;
    if (m > 0 && m < NB_MATERIAUX-1)
    {
        return t[m];
    }
    else
    {
        return SYMBOLES_MATERIAUX[NB_MATERIAUX-1];
    }
}

/** 
 * @brief Convertit un caractère symbolisant un matériau en matériau
 * 
 * @param c caractère à convertir
 * @return matériau obtenu
 * */
Materiau char2Materiau(char c)
{
    char t[] = SYMBOLES_MATERIAUX;
    int i;
    
    for (i = 0; i < NB_MATERIAUX; i++)
        if (t[i] == c)
            return i;
    return unknown;
}

/* ****************************** *
 * Fonctions relatives au terrain *
 * ****************************** */

/**
 * @brief Initialise un terrain avec de l'air partout
 * 
 * @param terrain le terrain à initialiser
 * */
void cree_terrain_vide(Terrain terrain)
{
    /* a completer */
}

/** 
 * @brief Modifie un terrain en insérant un terrain exemple
 * 
 * @param terrain le terrain à modifier
 * */
void cree_terrain_par_defaut(Terrain terrain)
{
    int i,j;
    char t[7][21] =
    {
        "       TTT          ",
        "       TTT         #",
        "        !         ##",
        "==~~~~===========###",
        "===~~==========###+#",
        "=========#+#==#g#+##",
        "#####g##############"
    };
    for (i = 0; i < H_TERRAIN; i++)
        for (j = 0; j < L_TERRAIN; j++)
            terrain[i][j] = char2Materiau(t[i][j]);
}

/**
 * @brief Charge un terrain depuis un fichier
 * 
 * @param filename nom du fichier contenant le terrain
 * @param terrain terrain où écrire les données lues
 * @return 1 en cas de réussite, 0 en cas de problème
 * */
int lit_terrain(char* filename, Terrain terrain) 
{
    /* a completer */
    return 0;
}

/* **************************** *
 * Sauver et lire l'etat du jeu
 * **************************** */
/**
 * @brief Charge tous les paramètres d'un jeu depuis un fichier
 * 
 * @param filename nom du fichier contenant les paramètres du jeu
 * @param game structure où charger les paramètres
 * @return 1 en cas de réussite, 0 en cas de problème
 * */
int lit_etat_jeu(char* filename, Game* game) 
{
    /* a completer */
    return 0;
}

/**
 * @brief Sauvegarde tous les paramètres d'un jeu dans un fichier
 * 
 * @param filename nom du fichier où sauvegarder les paramètres du jeu
 * @param game structure du jeu contenant les paramètres à sauvegarder
 * @return 1 en cas de réussite, 0 en cas de problème
 * */
int ecrit_etat_jeu(char* filename, Game* game) 
{
    /* a completer */
    return 0;
}

/* ****************************** *
 * Fonctions relatives aux regles *
 * ****************************** */
/**
 * @brief Vérifie si une règle peut être appliquée sur un inventaire
 * 
 * @param regle règle à vérifier
 * @param inventaire inventaire sur lequel la règle doit être vérifiée
 * @return 1 si la règle peut être appliquée, 0 sinon
 * */
int verifie_regle(Regle regle, Inventaire inventaire) 
{
    /* a completer */
    return 0;
}

/**
 * @brief Applique une règle sur un inventaire
 * 
 * @param regle règle à appliquer
 * @param inventaire inventaire sur lequel la règle doit être appliquée
 * @return 1 si la règle a bien été appliquée, 0 sinon
 * */
int applique_regle(Regle regle, Inventaire inventaire) 
{
    /* a completer */
    return 0;
}

/** 
 * @brief Convertit deux chaines de caractères entrées/sorties en une règle
 * 
 * @param entree chaîne contenant les ingrédients sous forme de caractères
 * @param sortie chaîne contenant les matériaux produits sous forme de caractères
 * @return la regle obtenue
 * */
Regle char2Regle(char* entree, char* sortie) 
{
    Regle regle;
    /* a completer */
    return regle;
}

/** 
 * @brief Compte le nombre de lignes dans un fichier
 * 
 * @param filename nom du fichier à analyser
 * @return nombre de lignes obtenues
 * */
int compte_lignes(char * filename) 
{
    /* a completer */
    return 0;
}

/**
 * @brief Lit un fichier contenant des règles
 * 
 * 
 * @param filename fichier à lire
 * @param num_regles pointeur vers un entier où le nombre de règles lues
 * est écrit par la fonction
 * @return tableau des règles lues
 * */
Regle * lit_regles(char * filename, int *num_regles) 
{
    /* a completer */
    return NULL;
}

/* ********************************** *
 * Fonctions relatives a l'inventaire *
 * ********************************** */
 
/**
 * @brief Initialise un inventaire en mettant à 0 les quantités de chaque matériau
 * 
 * @param inventaire inventaire à initialiser
 * */
void cree_inventaire_vide(Inventaire inventaire) 
{
    /* a completer */
}

/* ********************************* *
 * Fonctions relatives au personnage *
 * ********************************* */
/** 
 * @brief Place le personnage dans un terrain à une position possible
 * 
 * Le personnage est placé à un endroit où il y a de l'air et qui repose
 * sur un matériau autre que l'air.
 * @param le terrain où placer le personnage
 * @return le personnage avec la position obtenue
 * */
Personnage positionne_personnage(Terrain terrain) 
{
    Personnage p;
    /* a completer */
    return p;
}

/**
 * @brief Mouvement d'un personnage vers la droite
 * 
 * Le personnage est déplacé vers la droite selon la configuration du
 * terrain
 * @param terrain terrain où evolue le personnage
 * @param p personnage à déplacer
 * return le personnage après déplacement
 * */
Personnage mouvement_droite(Terrain terrain, Personnage p)
{
    /* a completer */
    return p;
}

/**
 * @brief Mouvement d'un personnage vers la gauche
 * 
 * Le personnage est déplacé vers la gauche selon la configuration du
 * terrain
 * @param terrain terrain où evolue le personnage
 * @param p personnage à déplacer
 * return le personnage après déplacement
 * */
Personnage mouvement_gauche(Terrain terrain, Personnage p)
{
    /* a completer */
    return p;
}

