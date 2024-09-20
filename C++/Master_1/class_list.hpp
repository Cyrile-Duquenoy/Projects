#pragma once
#include <iostream>

using namespace std;

template<typename TYPE>
class list{
    protected :
        int nb;
        TYPE *T;

    public :
        list(); // Constructor 1
        list(int nb); // Constructor 2
        list(int nb, TYPE Q); // Constructor 3

        inline int size(){return this->nb;}; // Renvoie la taille d'une liste

        ~list(){}; // Destrutor

        
        list(list<TYPE>& L){ // Copy Constructor // Le const en argyment donnait une erreur sur la méthode size().
            this->nb=L.size();
            T=new TYPE[nb];
            for(int ii=0;ii<L.size();ii++){
                this->T[ii]=L[ii];
            }
        };
        
        
        const list operator=(const list& L){ // Operator =
            this->nb=L.nb;
            for(int ii=0;ii<nb;ii++){
                this->T[ii]=L[ii];
            }
            return *this;
        };

        TYPE operator[](int ii) const{
            return this->T[ii];
        };

        TYPE operator()(int ii, const TYPE& Q){
            if(ii<nb){
                //cout<<"Je modifie la "<<ii+1<<"-ème composant de la liste."<<endl;
                T[ii]=Q;
            }
            return this->T[ii];
        };
        
        void showlist(){ // To Show List
            cout<<"[ ";
            for(int ii=0;ii<nb-1;ii++){
                cout<<T[ii]<<" , ";
            }
            cout<<T[nb-1]<<" ]"<<endl;
        };
};

// Constructeur 1
// Alloue la mémoire pour une liste à un seul élément.
template<typename TYPE>
list<TYPE>::list(){
    this->nb=0;
    T=new TYPE[0];
    T[0]=0;
};

// Constructeur 2
// Alloue la mémoire pour une liste à nb élément.
template<typename TYPE>
list<TYPE>::list(int nb){
    this->nb=nb;
    T=new TYPE[nb];
};

// Constructeur 3
// Alloue la mémoire et construit une liste à nb élmt tous égaux à TYPE Q.
template<typename TYPE>
list<TYPE>::list(int nb, TYPE Q){
    this->nb=nb;
    T=new TYPE[nb];
    for(int ii=0;ii<this->nb;ii++){
        T[ii]=Q;
    }
};