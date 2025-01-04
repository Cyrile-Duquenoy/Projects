#pragma once
#include <iostream>
#include<cstdlib>
#include<ctime>
#include <utility>
#include"class_grille.cpp"

class Grille{
        protected:
            size_t **G_;
            size_t N_;
            size_t M_;
            size_t nb_free_pos_;

        public:
            // Default Constructor
            Grille(size_t n, size_t m);

            // Destructor
            ~Grille();

            // Print Grille
            void print();

            // Accès en lecture
            size_t getHauteur(){return N_;};
            size_t getLargeur(){return M_;};
            size_t get_nb_free_pos(){return nb_free_pos_;};

            // Vérifie si une position est libre
            bool freePos(size_t x, size_t y);

            // Ajouter
            void ajouter_mur(size_t x, size_t y);
            void ajouter_joueur(size_t x, size_t y);

            /* Méthodes restantes à implémenter
        
            // Retourne "aléatoirement" une position libre
            std::pair<size_t,size_t> random_free_pos();

            */
};



// Default Constructor
Grille::Grille(size_t n, size_t m) : N_(n), M_(m){
    srand(time(0));
    nb_free_pos_=n*m;
    G_ = new size_t *[N_];
    for (size_t i = 0; i < N_; i++) {
        G_[i] = new size_t[M_];
        for (size_t j = 0; j < M_; j++) {
            G_[i][j] = 0;
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
        if(G_[x][y]==0){
            return true;
        }
        else{
            return false;
        }
    }
}

/*
std::pair <size_t,size_t> Grille::random_free_pos(){
    return {0,0};
}
*/

void Grille::ajouter_mur(size_t x, size_t y){
    if (x >= 0 && x < getLargeur() && y >= 0 && y < getHauteur() && freePos(x,y)){
        G_[x-1][y-1] = 1;
    }
}

void Grille::ajouter_joueur(size_t x, size_t y){
    if (x >= 0 && x < getLargeur() && y >= 0 && y < getHauteur() && freePos(x,y)){
        if(G_[x-1][y-1]==0)
            G_[x-1][y-1] = 8;
        else
            std::cout<<"Position non autorisée"<<std::endl;
    }
}
    




