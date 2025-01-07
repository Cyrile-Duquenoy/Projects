#pragma once
#include <iostream>
#include<cstdlib>
#include<ctime>
#include <utility>
#include "class_player.hpp"

#define VIDE 0
#define WALL 1
#define HUMAN 2
#define ZOMBIE 3

class Grille{
        protected:
            size_t **G_;
            const int N_;
            const int M_;
            int nb_free_pos_;
            int nb_player_;
            int nb_zombie_;
            int nb_wall_;

        public:
            Grille();
            Grille(int n, int m); // Default Constructor
            ~Grille(); // Destructor
            void print(); // Print Grille

            int getHauteur() const {return N_;};
            int getLargeur() const {return M_;};
            int get_nb_free_pos(){return nb_free_pos_;};
            void less_nb_free_pos(){nb_free_pos_--;};
            
            bool freePos(int x, int y); // Vérifie si une position est libre
            void const ajouter_mur(int x, int y);
            void ajouter_joueur(int x, int y);
            Point<int> random_free_pos(); //Retourne "aléatoirement" une position libre sous la forme d'un point
            void transform_to_zombie(Player p); // Choisis un jooueur au hasard et le transforme en zombie
            Point<int> get_pos(int x, int y){return Point<int> (x,y);}; // A ameliorer
            
};


// Default Constructor
Grille::Grille(int n, int m) : N_(n), M_(m), nb_free_pos_(n*m), nb_player_(0), nb_zombie_(0), nb_wall_(0) {
    srand(time(0));
    G_ = new size_t *[getHauteur()];
    for (size_t i = 0; i < getHauteur(); i++) {
        G_[i] = new size_t[getLargeur()];
        for (size_t j = 0; j < getLargeur(); j++) {
            G_[i][j] = VIDE;
        }
    }
}

// Destructor
Grille::~Grille(){
    for (size_t i = 0; i < getHauteur(); i++) {
        delete[] G_[i];
    }
    delete[] G_;
}

// Print Grille
void Grille::print(){
    for (size_t i = 0; i < getHauteur(); i++) {
        for (size_t j = 0; j < getLargeur(); j++) {
            std::cout << G_[i][j] << " ";
        }
    std::cout << std::endl;
    }
    std::cout<<std::endl;
}

bool Grille::freePos(int x, int y){
    if (x >= 0 && x < getLargeur() && y >= 0 && y < getHauteur()){
        if(G_[x][y]==VIDE){
            return true;
        }
        else{
            return false;
        }
    }
}

void const Grille::ajouter_mur(int x, int y){
    if (x >= 0 && x < getLargeur() && y >= 0 && y < getHauteur() && freePos(x,y)){
        G_[x-1][y-1] = WALL;
        nb_wall_++;
        less_nb_free_pos();
    }
}

void Grille::ajouter_joueur(int x, int y){
    if (x >= 0 && x < getLargeur() && y >= 0 && y < getHauteur() && freePos(x,y)){
        if(G_[x-1][y-1]==0){
            G_[x-1][y-1] = HUMAN;
            nb_player_++;
            less_nb_free_pos();
        }
        else
            std::cout<<"Position non autorisée"<<std::endl;
    }
}

// A FAIRE : Abaisser la complexité plus tard
Point<int> Grille::random_free_pos(){
    Point<int> pos;
    size_t count =0;
    size_t rr=rand()%get_nb_free_pos();
    for(size_t i=0;i<getHauteur();i++){
        for(size_t j=0;j<getLargeur();j++){
            if(G_[j][i]==VIDE){
                count++;
                if(count==rr){
                    Point<int> pos2(i+1,j+1);
                    pos=pos2;
                }
            }
        }
    }
    return pos;
}

void Grille::transform_to_zombie(Player p){
    p.transform_to_zombie();
    G_[p.get_pos().get_x()][p.get_pos().get_y()]=ZOMBIE;
}