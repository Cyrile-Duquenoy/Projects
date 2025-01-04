#include<iostream>
#include "class_grille.hpp"

using namespace std;

int main(void){

    Grille G(5,5);
    G.print();
    cout<<G.getHauteur()<<endl;

    cout<<G.freePos(1,1)<<endl;
    G.ajouter_mur(2,1);
    G.print();
    G.ajouter_joueur(1,1);
    G.print();

    Point<size_t> rr;
    rr=G.random_free_pos();
    rr.print();

    return 0;
}









