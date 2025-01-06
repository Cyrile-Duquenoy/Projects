#pragma once
#include <iostream>
#include "class_point.hpp"

#define HUMAN 2
#define ZOMBIE 3

class Player : public Point<size_t>{
    private : 
        Point<size_t> pos_;
        size_t score_;
        size_t character_;

    public:
        Player() : pos_(0,0), score_(0),character_(HUMAN) {} // Default Constructor
        Player(size_t x,size_t y) : pos_(x, y), score_(0),character_(HUMAN) {} // Constructor #1
        ~Player() {} // Destructor

        size_t get_score() const { return score_; } // get_score
        Point<size_t> get_pos() const { return pos_; } // get_pos
        size_t get_character() const { return character_; } // get_character
        void set_score(size_t score) { score_ = score; } // write score
        void set_pos(Point<size_t> pos) { pos_ = pos; } // // write pos

        void transform_to_zombie(){character_=ZOMBIE;}
        bool is_zombie(){return get_character()==ZOMBIE;}
        bool is_human(){return get_character()==HUMAN;}

        // Overloading operator ==
        bool operator==(const Player& p) const {
            return ((pos_ == p.pos_) && (score_ == p.score_) && (character_ == p.character_));
        }

};