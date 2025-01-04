#pragma once
#include <iostream>
#include"class_point.hpp"

class Element{
    private:
        Point<size_t> pos_;
    public:
        Element() : pos_(0, 0){}; // Default constructor
        ~Element() {} //Destructor
};

class Player : public Element{
    private :
        size_t score_;
    public:
        Player() : Element(), score_(0) {};
        ~Player() {}
        // tranform player to zombie
        Zombie human_to_zombie();
};

class Zombie : public Element{
    private :
        size_t score_;
    public:
    Zombie() : Element(), score_(0) {};
    ~Zombie() {}
};

/*
    A FAIRE :
    Convert human to zombie
*/
