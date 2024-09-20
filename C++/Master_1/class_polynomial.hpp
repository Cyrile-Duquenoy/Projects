#pragma once
#include <iostream>
#include "class_list.hpp"

using namespace std;

template<typename TYPE>
class Polynomial : public list<TYPE>{

    protected :
        int degree;

    public :
        inline int deg()const{return degree;}; // Retourne le degré d'un polynome.

        // Constructeur 1
        // Initialise un polynome de degré n-1 à zéro
        Polynomial(int n);

        // Constructeur 2
        // Initialise un polynome de degré n-1 dont tout les coeff. valent a
        Polynomial(int n, const TYPE & a);

        template <typename T>
        friend const Polynomial<T> operator+(const Polynomial<T>& P, const Polynomial<T>& Q );

        template<typename T>
        friend const Polynomial<T> operator*=(Polynomial<T>& p, const T&a);      
        
};

// Constructeur 2
template<typename TYPE>
Polynomial<TYPE>::Polynomial(int n, const TYPE & a){
    this->nb=n;
    this->degree=n-1;
    for(int ii=0;ii<n;ii++){
        this->T[ii]=a;
    }
};

// Constructeur 1
template<typename TYPE>
Polynomial<TYPE>::Polynomial(int n){
    this->nb=n;
    this->degree=0;
    for(int ii=0;ii<n;ii++){
        this->T[ii]=0;
    }
};


// Operator +=
// Version modifiée par rapport à l'énoncé mais qui fonctionne !
template<typename TYPE> // add polynomial
const Polynomial<TYPE>& operator+=(Polynomial<TYPE>& p, Polynomial<TYPE>&q) { // C'est le const sur q qui donnait une erreur.
    if(p.deg()+1 >=q.deg()+1 )
        for( int i =0; i<q.deg()+1 ; i++){
            p(i, p[i]+q[i]);
        }
    else{
        Polynomial<TYPE> keepQ = q;
        p = keepQ += p;
    }
    return p;
};



// Binomial Operator +
template<typename T>
const Polynomial<T> operator+(const Polynomial<T> & P, const Polynomial<T> & Q){
    int s=max(P.deg(),Q.deg())+1;
    int s1=min(P.deg(),Q.deg())+1;
    Polynomial<T> R(s, 0);
    for(int ii=0;ii<s1;ii++){
        R(ii,P[ii]+Q[ii]);
    }
    if(s1==P.deg()+1){
        for(int ii=s1;ii<s;ii++){
            R(ii,Q[ii]);
        }
    }
    else{ 
        if(s1==Q.deg()+1){
            for(int ii=s1;ii<s;ii++){
            R(ii,P[ii]);
            }
        }
    }
    return R;
};

template<class T> // multiplication by scalar
const Polynomial<T> operator*=(Polynomial<T>& p, const T&a) {
    for (int i=0; i<p.deg()+1 ; i++){
        p(i, p[i]*a);
    }
    return p;
};

template<class T>
const Polynomial<T> operator*(const T&a, const Polynomial<T>&P){
    Polynomial<T> Q(P.deg()+1);
    for(int ii=0;ii<P.deg()+1;ii++){
        Q(ii,P[ii]*a);
    }
    return Q;
};

/*  // Ancien opérateur *
// Produit de deux polynomes // Fonctionne anormalement !!!! 
template<class T>
Polynomial<T> operator*(const Polynomial<T>& P, const Polynomial<T>& Q){
    int n=P.deg();
    int k=Q.deg();
    Polynomial<T> R(n+k+1);
    for(int i=0;i<n+1;i++){
        for(int j=0;j<k+1;j++){
            R(i+j, P[i]*Q[j]);
        }
    }
    return R;
};
*/

// retour sur l'operateur * qui fonctionne cette fois-ci.
template<typename T>
Polynomial<T> operator*(const Polynomial<T>& P, const Polynomial<T>& Q){
    int n=P.deg();
    int k=Q.deg();
    Polynomial<T> R(n+k+1,0);
    for(int i=0;i<=R.size();i++){
        int m=max(0,i-n);
        int M=min(i, k);
        for(int j=m;j<= M;j++){
            R(i, P[i-j]*Q[j]);
        }
    }
    return R;
};

// Operateur *=
template<typename T>
Polynomial<T> operator*=(Polynomial<T>&P, const Polynomial<T>&Q){
    P=P*Q;
    return P;
};