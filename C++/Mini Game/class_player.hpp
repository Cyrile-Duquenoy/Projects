#pragma once
#include <iostream>
#include "class_point.hpp"

#define HUMAN 2
#define ZOMBIE 3

#define HAUT 8
#define BAS 5
#define GAUCHE 4
#define DROITE 6

class Player : public Point<int>{
    private : 
        Point<int> pos_;
        int score_;
        int character_;

    public:
        Player() : pos_(0,0), score_(0),character_(HUMAN) {} // Default Constructor
        Player(int x,int y) : pos_(x, y), score_(0),character_(HUMAN) {} // Constructor #1
        ~Player() {} // Destructor

        int get_score() const { return score_; } // get_score
        Point<int> get_pos() const { return pos_; } // get_pos
        int get_character() const { return character_; } // get_character
        void set_score(int score) { score_ = score; } // write score
        void set_pos(Point<int> pos) { pos_ = pos; } // // write pos

        void transform_to_zombie(){character_=ZOMBIE;}
        bool is_zombie(){return get_character()==ZOMBIE;}
        bool is_human(){return get_character()==HUMAN;}

        // WARNING !
        // Pour les deux méthodes suivantes, l'idée est bonne
        // Mais possibilité de triche / glitch en jeu en rentrant dans le code
        // A voir comment modifier les classes pour une interaction moins défaillante
        Point<int> want_to_move(int mvt);
        Point<int> move_to(Point<int> pp);

        // Overloading operator ==
        bool operator==(const Player& p) const {
            return ((pos_ == p.pos_) && (score_ == p.score_) && (character_ == p.character_));
        }
};

Point<int> Player::want_to_move(int mvt){
    Point<int> pp;
    switch(mvt){   
        case HAUT:
            pp.set_x(this->get_x());
            pp.set_y(this->get_y() +1);
            break;
        case BAS:
            pp.set_x(this->get_x());
            pp.set_y(this->get_y() -1);
            break;
        case GAUCHE:
            pp.set_x(this->get_x()-1);
            pp.set_y(this->get_y());
            break;
        case DROITE:
            pp.set_x(this->get_x()+1);
            pp.set_y(this->get_y());
            break;
    }
    return pp;
}   