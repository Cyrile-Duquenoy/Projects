#pragma once
#include <iostream>
#include<cstdlib>
#include<ctime>
#include <utility>
#include"class_point.hpp"
#include "class_player.hpp"

#define VIDE 0
#define WALL 1
#define HUMAN 2
#define ZOMBIE 3

class Grille{
        protected:
            size_t **G_;
            size_t N_;
            size_t M_;
            size_t nb_free_pos_;

        public:
            
            Grille(size_t n, size_t m); // Default Constructor
            ~Grille(); // Destructor
            void print(); // Print Grille

            size_t getHauteur() const {return N_;};
            size_t getLargeur() const {return M_;};
            size_t get_nb_free_pos(){return nb_free_pos_;};
            void less_nb_free_pos(){nb_free_pos_--;};
            
            bool freePos(size_t x, size_t y); // Vérifie si une position est libre
            void ajouter_mur(size_t x, size_t y);
            void ajouter_joueur(size_t x, size_t y);
            Point<size_t> random_free_pos(); //Retourne "aléatoirement" une position libre sous la forme d'un point
            void transform_to_zombie(Player p); // Choisis un jooueur au hasard et le transforme en zombie
            Point<size_t> get_pos(size_t x, size_t y){return Point<size_t> (x,y);}; // A ameliorer
            
};


// Default Constructor
Grille::Grille(size_t n, size_t m) : N_(n), M_(m){
    srand(time(0));
    nb_free_pos_=n*m;
    G_ = new size_t *[N_];
    for (size_t i = 0; i < N_; i++) {
        G_[i] = new size_t[M_];
        for (size_t j = 0; j < M_; j++) {
            G_[i][j] = VIDE;
        }
    }
}

// Destructor
Grille::~Grille(){
    for (size_t i = 0; i < N_; i++) {
        delete[] G_[i];
    }
    delete[] G_;
}

// Print Grille
void Grille::print(){
    for (size_t i = 0; i < N_; i++) {
        for (size_t j = 0; j < M_; j++) {
            std::cout << G_[i][j] << " ";
        }
    std::cout << std::endl;
    }
    std::cout<<std::endl;
}

bool Grille::freePos(size_t x, size_t y){
    if (x >= 0 && x < getLargeur() && y >= 0 && y < getHauteur()){
        if(G_[x][y]==VIDE){
            return true;
        }
        else{
            return false;
        }
    }
}

void Grille::ajouter_mur(size_t x, size_t y){
    if (x >= 0 && x < getLargeur() && y >= 0 && y < getHauteur() && freePos(x,y)){
        G_[x-1][y-1] = WALL;
        less_nb_free_pos();
    }
}

void Grille::ajouter_joueur(size_t x, size_t y){
    if (x >= 0 && x < getLargeur() && y >= 0 && y < getHauteur() && freePos(x,y)){
        if(G_[x-1][y-1]==0){
            G_[x-1][y-1] = HUMAN;
            less_nb_free_pos();
        }
        else
            std::cout<<"Position non autorisée"<<std::endl;
    }
}

// A FAIRE : Abaisser la complexité plus tard
Point<size_t> Grille::random_free_pos(){
    Point<size_t> pos;
    size_t count =0;
    size_t rr=rand()%get_nb_free_pos();
    for(size_t i=0;i<getHauteur();i++){
        for(size_t j=0;j<getLargeur();j++){
            if(G_[j][i]==VIDE){
                count++;
                if(count==rr){
                    Point<size_t> pos2(i+1,j+1);
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