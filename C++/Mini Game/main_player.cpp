#include <iostream>
#include "class_player.hpp"

int main(void){

    Player p1;
    p1.get_pos().print();
    std::cout<<p1.get_character()<<std::endl;

    Point<size_t> pp(1,1);
    p1.set_pos(pp);
    p1.get_pos().print();
    p1.transform_to_zombie();
    std::cout<<p1.get_character()<<std::endl;

    return 0;
}