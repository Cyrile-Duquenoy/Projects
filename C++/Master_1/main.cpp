#include <iostream>
#include "class_list.hpp" // Pas besoin de l'inclure dans le main puiqu'il est appelé à partir de class_polynomial.hpp
#include "class_polynomial.hpp"
using namespace std;

/*
Diverses remarques :

    - Plusieurs méthodes ne sont pas exactement faits comme dans l'énonce a cause de blocage dans la manière dont il aurait fallu les faire.
    Je les ai donc modifiés pour que ca fonctionne.
    Notamment l'operateur ().
    L(int  n, TYPE Q) modifie la n-ième composante de la liste L et la mets à la valeur Q

    - L'operateur += aussi pour les polynomes, le second argument en const donnait une erreur. J'ai donc enlevé le const.

    - showlist mériterai d'etre renommé en show tout court pour des raisons pratiques.
    Ou bien directement faire l'opérateur <<

Remarques sur le fonctionnement des classes :

    Class List :

    - 2 données protected : int nb la taille de la liste voulue et TYPE *T un tableau de type TYPE dont la taille nb lui sera associée.
    - Initialisation d'une liste via les divers constructeurs. Il y en a 3 au total.
    - Le constructeur de copie ne fonctionne pas (il est en commentaire dans le .hpp). 
    EDIT : MAINTENANT FONCTIONNEL !!!!
    - Remarque importante sur l'operateur () :
    L(int  n, TYPE Q) modifie la n-ième composante de la liste L et la mets à la valeur Q.
    - l'operateur [] ne fait que lire la n-ième composante de la liste.

    Class Polynomial :

    - Initialisation via les divers constructeurs.
    - J'aimerai aussi faire un constructeur qui à partir d'une liste donnée, lui associera un polynome.
    Typiquement quelque chose comme Polynomial(list<TYPE> &L);
    Parce que les divers constructeurs initialisent ici uniquement des polynommes dont tout les coeff. sont égaux.

    - L'operateur *= fonctionne quand on fait P0*=P0.
    Mais ne fonctionne par pour P0*=PP quand on prends PP différent de P0.
    En gardant P0=2+2X et en prenant PP=1 + X, P0*=PP me retourne 2 + 2X.
    EDIT : C'était l'operateur * a revoir et à refaire !!!!

Pistes d'améliorations :

    - Il pourrai être interessant de mettre au point la division de 2 polynomes.
    Si il reste du temps, appliquer l'algo de division euclidienne de polynomes.

    - Pourquoi ne pas implémenter aussi la recherche des racines des polynomes du 1er, 2eme et 3eme degré. 
    Formules de Cardan.
*/

int main(){

    // TEST CLASS LIST //
    cout<<"TEST CLASS LIST !"<<endl<<endl;

    // Test Constructeur 1
    // Alloue le mémoire pour une liste à un seul élément.
    cout<<"Test constructeur 1."<<endl;
    list<int> L;
    cout<<"Initialisation d'une liste L à 1 élément dont on alloue la mémoire : "<<endl;
    L.showlist();
    cout<<endl;

    // Test constructeur 2
    // Alloue la mémoire pour une liste à nb élément.
    cout<<"Test constructeur 2."<<endl;
    list<int> L1(5);
    cout<<"Initialisation d'une liste L1 à 5 élément dont on alloue la mémoire : "<<endl;
    L1.showlist();
    cout<<endl;

    // Test constructeur 3
    // Alloue la mémoire et construit une liste à nb élmt tous égaux à TYPE Q.
    cout<<"Test constructeur 3."<<endl;
    list<int> L2(5,1);
    cout<<"Initialisation d'une liste L2 à 5 élément dont tout les éléments valent 1 : "<<endl;
    L2.showlist();
    cout<<endl;

    cout<<"Test méthode size."<<endl;
    cout<<"Taille de L2 : "<<L2.size()<<endl<<endl;
    cout<<"Test operator []."<<endl<<"Ici j'affiche L2[0] : ";
    cout<<L2[0]<<endl<<endl;
    cout<<"Test operator ()."<<endl<<"ici L(0,10) veut dire qu'a la première coord. de L je lui donne la valeur de 10."<<endl;
    L2(0,10);
    cout<<"Liste L2 : ";
    L2.showlist();
    cout<<endl;

    // TEST CLASS POLYNOMIAL //
    cout<<endl<<"TEST CLASSE POLYNOMIAL !"<<endl;

    Polynomial<int> P(2); // Initialise un polynome de degré 1 dont tout les coeff valent zéro.
    cout<<"Polynome P : ";
    P.showlist();
    cout<<endl;

    Polynomial<int> P2(2,5); // Initialise un polynome de degré 1 dont tout les coeff. valent 5.
    cout<<"Polynome P2 :";
    P2.showlist();
    cout<<endl;

    cout<<"Test operator +"<<endl;
    P=P2;
    cout<<"Polynome P qui doit être égal à P2 : ";
    P.showlist();
    cout<<endl;

    cout<<"Test de la méthode size."<<endl<<"Taille de P2 --> doit renvoyer le nombre de coeff. de P2, soit en l'occurence ici 2."<<endl;
    cout<<"nbre de coeff. de P2 : "<<P2.size()<<endl;
    cout<<endl;

    Polynomial<int> P3(2,10);
    cout<<"Polynome P3 : ";
    P3.showlist();
    cout<<endl;

    Polynomial<int> P4(8,1);
    cout<<"Polynome P4 : ";
    P4.showlist();
    cout<<endl;

    cout<<"Test de la méthode deg qui renvoie le degré d'un polynome."<<endl;
    cout<<"degré de P4 : "<<P4.deg()<<endl;
    cout<<endl;

    // Test Operator += with 2 Polynome of different degree.
    cout<<"Test Operator += with 2 Polynome of different degree."<<endl;
    cout<<"Ici P3 doit être égal à P+=P4."<<endl;
    //P3=P+=P4;
    P3=P+=P4;
    cout<<"P3=P += P4 : ";
    P3.showlist();
    cout<<endl<<"Vérification de size de P3 : "<<P3.size()<<" et de son degré : "<<P3.deg()<<endl;
    cout<<endl;

    cout<<"De même avec ici P3 qui doit être égal à P4+=P."<<endl;
    P3=P4+=P;
    cout<<"P3=P4 += P : ";
    P3.showlist();
    cout<<"On pense ici que P3 a été multiplié par 2 alors qu'en fait on a fait 2 fois la même addition, ne pas confondre avec le test de multiplication."<<endl;
    cout<<endl;
    cout<<endl<<"Vérification de size de P3 : "<<P3.size()<<" et de son degré : "<<P3.deg()<<endl;
    cout<<endl;

    // Test binary operator + with 2 Polynome of different degree.
    cout<<"Test binary opearor +"<<endl;
    cout<<"P doit etre egél à P4+P3."<<endl;
    P=(P4+P3);
    P.showlist();
    cout<<endl;

    cout<<"De meme ici P doit etre egal à P3+P4."<<endl;
    P=(P3+P4);
    P.showlist();
    cout<<endl;
    
    // Test operator *=
    cout<<"Test operator *="<<endl;
    cout<<"Polynome P : ";
    P.showlist();
    cout<<"Multiplication de P par 8 : ";
    P*=8;
    P.showlist();
    cout<<endl;

    // Test operator *
    cout<<"Test operator *"<<endl;
    P=2*P;
    cout<<"P = 2 fois P : ";
    P.showlist();
    cout<<endl;

    // Manque plus qu'a tester le produit de deux polynomes !!!!
    cout<<"Manque plus qu'a tester le produit de deux polynomes."<<endl;

    cout<<"Q(X) = X"<<endl;
    Polynomial<int> Q(2,1);
    Q(0,0);
    Q.showlist();
    cout<<endl;
    
    cout<<"R(X)=5 + 5X + 5X^2"<<endl;
    Polynomial<int> R(3,5);
    R.showlist();
    cout<<endl;

    cout<<"PQ(X)=5X + 5X^2 + 5X^3"<<endl;
    P=Q*R;
    P.showlist();
    cout<<endl;

    cout<<"Test operator *= sur 2 polynomes"<<endl;
    Polynomial<int> P0(2,2);
    cout<<"P0(X) = 2 + 2X"<<endl;
    P0.showlist();

    P0*=P0;
    cout<<"P0*=P0 doit etre égal à 4 + 4X + 4X^2"<<endl;
    P0.showlist();
    cout<<endl;

    Polynomial<int> PPP(2,1);
    Polynomial<int> PPPP(2,1);
    
    PPP(0,0);
    cout<<"PPP = X"<<endl;
    cout<<"PPPP = 1 + X"<<endl;
    cout<<"PPPP*=PPP doit donc être X + X^2"<<endl;
    PPPP*=PPP;
    PPPP.showlist();

    cout<<endl;
    Polynomial<int> RR(2,2);
    RR+=RR;
    RR.showlist();

    cout<<"Diverses remarques : "<<endl;
    cout<<"Voir commentaires au début du main"<<endl;
    cout<<endl;

    return 0;
}