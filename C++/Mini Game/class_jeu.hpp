#pragma once
#include <iostream>
#include "class_grille.hpp"

#define ENDGAME 1000


class Jeu : public Grille,Player{
    private:
        size_t *players_;
        int current_turn_;

    public:
        Jeu():current_turn_(0){
            players_=new size_t [nb_player_];
        };
        ~Jeu();
        void new_game();
        bool end_game();
        int next_turn(){current_turn_++;}
};