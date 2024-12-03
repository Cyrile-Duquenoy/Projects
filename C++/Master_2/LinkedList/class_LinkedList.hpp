#pragma once
#include <iostream>

using namespace std;

template<typename T>
class LinkedList{
    protected :
        T item_;
        LinkedList* next_;

    public:
        LinkedList(); // Default Constructor
        LinkedList(const T&t, LinkedList* N=0); // Constructor #1

        LinkedList*& next(); // Lecture/ecriture seule de next
        LinkedList* next()const; //Lecture seule de next
        const T& item() const{return item_;}; // Lecture seule de l'item
        T& item() {return item_;}; // Lecture/ecriture de l'item

        LinkedList(const LinkedList<T>& L); // Copy Constructor
        ~LinkedList(); // Destructor

        LinkedList& last(); // Retourne le dernier element de la liste
        int length() const; // Retourne la longueur de la liste

        void insert_next_item(T&t); // Places new item right after the first
        void insert_first_item(T&t); //Place a new item in first position (Pile Principle)

        void insert_at(int position, const T& value); // Insert un nouveau maillon à la positoin voulue
        void delete_at(int position); // Supprime un maillon à la position voulue
        void switch_at(int pos1, int pos2); // Echange les valeurs de 2 maillons
        // N.B : pour Switch_at, 
        // l'idée de départ était d'échanger directement les lien qui lient les maillons
        // i.e : travailler sur les pointeurs.
        //Sauf que trop d'erreurs possibles et une méthode beaucoup trop complexe à mettre en place pour son utilité.
        //D'où le switch des valeurs

        void append(const T&t );

        void print();

        void drop_next_item();
        void drop_first_item();

        T getValue()const{
            return item_;
        }

        void truncateItems(double threshold);

        LinkedList& operator=(const LinkedList&);
        const LinkedList& operator+=(LinkedList&L);

        // Méthode pour Tri Fusion //
        void bubble_sort_opt(int length);
        void bubble_sort(int length);
        LinkedList* fusion_sort(int length);
        LinkedList* fusion(LinkedList<T>* scan1, LinkedList<T>* scan2);
};

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& ll) {
    if (this == &ll) {
        return *this;
    }
    delete next_;
    item_ = ll.item_;
    next_ = ll.next_ ? new LinkedList<T>(*ll.next_) : NULL;
    return *this;
}

template <class T>
const LinkedList<T>& LinkedList<T>::operator+=(LinkedList<T>& L) {
    LinkedList<T>* scan1 = this;  // Pointeur sur la liste actuelle (this)
    LinkedList<T>* scan2 = &L;    // Pointeur sur la liste à fusionner (L)
    // Étape 2 : Vérifier si l'élément de L doit être placé au début de la liste actuelle
    if (scan2 != NULL && scan2->item_ < scan1->item_) {
        LinkedList<T>* temp = new LinkedList<T>(scan2->item_, scan1); // Créer un nouveau maillon pour l'élément de L
        scan1 = temp;  // Placer l'élément en tête de la liste
        scan2 = scan2->next_;  // Avancer scan2
    }
    // Étape 3 : Boucle principale sur scan1
    for (; scan1->next_ != NULL; scan1 = scan1->next_) {
        // Étape 4 : Si l'élément pointé par scan2 est égal à l'élément pointé par scan1, utiliser l'opérateur +=
        if (scan2 != NULL && scan2->item_ == scan1->item_) {
            scan1->item_ += scan2->item_;  // Utilisation de l'opérateur += de T
            scan2 = scan2->next_;  // Avancer scan2
        }
        // Étape 5 : Boucle interne pour insérer les éléments de L entre les éléments de N
        while (scan2 != NULL && scan2->item_ < scan1->next_->item_) {
            LinkedList<T>* temp = new LinkedList<T>(scan2->item_, scan1->next_); // Créer un nouveau maillon
            scan1->next_ = temp;  // Insérer l'élément entre scan1 et scan1->next_
            scan1 = temp;  // Avancer scan1 pour qu'il pointe sur l'élément inséré
            scan2 = scan2->next_;  // Avancer scan2
        }
    }
    // Étape 6 : Si des éléments restent dans L, les ajouter à la fin de la liste actuelle
    while (scan2 != NULL) {
        LinkedList<T>* temp = new LinkedList<T>(scan2->item_);
        scan1->next_ = temp;
        scan1 = temp;
        scan2 = scan2->next_;
    }
    return *this;
}

// Default Constructor
template<typename T>
LinkedList<T>::LinkedList():item_(),next_(NULL){}

//Constructor #1
template<typename T>
LinkedList<T>::LinkedList(const T&t, LinkedList* N):item_(t),next_(N){}

// Lecture seule de next
template<typename T>
LinkedList<T>* LinkedList<T>::next() const{
    return next_;
}

// Lecture/ecriture de next
template<typename T>
LinkedList<T>*& LinkedList<T>::next(){
    return next_;
}

// Copy Constructor
template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& L):
    item_(L.item()), next_(L.next() ? new LinkedList(*L.next()) : 0) {}

// Destructor
// On supprime tout les next de liste.
// Dans l'ancienne version du destructeur je supprimais juste le premier next
//et donc je supprimais juste l'accès.
template<typename T>
LinkedList<T>::~LinkedList(){
    if (next_) next_->~LinkedList();
}

// retourne le dernier element de la liste
template<typename T>
LinkedList<T>& LinkedList<T>::last(){
    /*
    if(next_==NULL){
        return *this;
    }
    else{
        return next_->last();
    }
    */

    // Ligne équivalente à ce qu'il ya au dessus,
    // J'apprends à compacter la syntaxe.
    // Condition Ternaire
    return next_ ? next_->last() : *this;
}

// Retourne la longueur de la liste
template<typename T>
int LinkedList<T>::length() const{
    /*
    if(this==NULL){
        return 0;
    }
    return 1 + (next_ ? next_->length():0);
    */

    // Ligne équivalente à ce qu'il ya au dessus,
    // J'apprends à compacter la syntaxe.
    return 1 + (next_ ? next_->length() : 0);
}

// Insere un elmt juste après le premier
template<typename T>
void LinkedList<T>::insert_next_item(T& t) {
    LinkedList* new_node = new LinkedList<T>(t, next_);
    next_ = new_node;
}

template<typename T>
void LinkedList<T>::insert_first_item(T& t) {
    // Crée un nouveau maillon temporaire contenant l'élément courant
    LinkedList* temp = new LinkedList(item_, next_);
    
    // Met à jour le maillon courant avec le nouvel élément
    item_ = t;
    next_ = temp; // Le nouveau maillon devient le suivant
}

template<typename T>
void LinkedList<T>::print(){
    const LinkedList* current = this;
    while (current) {
        cout << current->item_;
        if (current->next_) cout << " -> ";
        current = current->next_;
    }
    cout<<endl;
}

// Append some new item
template<typename T>
void LinkedList<T>::append(const T&t ){
    last().next_=new LinkedList(t);
}

// Supprime le maillon juste après celui courant
template <typename T>
void LinkedList<T>::drop_next_item(){
    if (next_ != NULL){
        LinkedList<T>* temp = next_;
        next_ = next_->next_;
        temp->next_ = NULL;
        delete temp;
    }
}

template<typename T>
void LinkedList<T>::drop_first_item() {
    /*
    if (next_ ==  NULL){
        cout<<"Error: Cannot drop the only item in the list!"<<endl;
    } 
    else{
        drop_next_item();
    }
    */
    return next_ ? drop_next_item() : (std::cerr<<"Cannot drop the only item in the list!"<<endl,void());
    // Condition ternaire toujours,
    // On oblige la troisième condition à être de même type que la deuxième, sinon : erreur.
}

template<typename T>
void LinkedList<T>::truncateItems(double threshold) {
    LinkedList<T>* current = this;
    LinkedList<T>* prev = NULL;

    while (current != NULL) {
        // Utilise getValue() pour obtenir la valeur de l'élément
        T value = abs(current->getValue());  // Utilisation de getValue() pour obtenir la valeur absolue

        // Vérifie si la valeur absolue de l'élément est inférieure au seuil
        if (value < threshold) {
            LinkedList<T>* temp = current;
            if (prev != NULL) {
                // Si l'élément courant n'est pas le premier, met à jour le pointeur du précédent
                prev->next_ = current->next_;
            }
            current = current->next_;  // Passe au maillon suivant
            temp->next_ = NULL;
            delete temp;
        } else {
            prev = current;  // Si l'élément n'est pas supprimé, le maillon courant devient le précédent
            current = current->next_;  // Passe au maillon suivant
        }
    }
}

// Insere un nouvel element à la position voulue.
template<typename T>
void LinkedList<T>::insert_at(int position, const T& value) {
    if (position < 0) {
        std::cerr << "Position invalide"<<endl;
        return;
    }
    LinkedList<T>* new_node = new LinkedList<T>(value);
    if (position == 0) {
        // Insertion en tête
        new_node->next_ = this;  // Le nouvel élément pointe sur l'ancien premier élément
        *this = *new_node;  // On met à jour la liste pour pointer sur le nouvel élément
        return;
    }
    // Recherche de la position pour insérer l'élément
    LinkedList<T>* current = this;
    for (int i = 0; current != NULL && i < position - 1; i++) {
        current = current->next_;
    }
    if (current == NULL) {
        std::cerr << "Position hors de portée." <<endl;
        // std::cerr très utile !
        // Permet de se faire comporter un affichage de sortie comme un warning !
        delete new_node;
        return;
    }
    // Insertion de l'élément
    new_node->next_ = current->next_;
    current->next_ = new_node;
}

// Supprime un élément à une certaine position.
template<typename T>
void LinkedList<T>::delete_at(int position) {
    if (position < 0) {
        std::cerr << "Position invalide." <<endl;
        return;
    }
    if (position == 0) {
        // Suppression en tête
        LinkedList<T>* temp = this;
        *this = *this->next_;  // Le premier élément devient le second
        delete temp;  // Supprimer l'ancien premier élément
        return;
    }
    // Recherche de la position avant l'élément à supprimer
    LinkedList<T>* current = this;
    for (int i = 0; current != NULL && i < position - 1; ++i) {
        current = current->next_;
    }
    if (current == NULL || current->next_ == NULL) {
        std::cerr << "Position hors de portée." << std::endl;
        return;
    }
    // Suppression de l'élément à la position donnée
    LinkedList<T>* temp = current->next_;
    current->next_ = current->next_->next_;  // On saute l'élément à supprimer
    delete temp;  // Libérer la mémoire de l'élément supprimé
}

template<typename T>
void LinkedList<T>::switch_at(int pos1, int pos2) {
    if (pos1 < 0 || pos2 < 0 || pos1 >=this->length() || pos2>=this->length()) {
        std::cerr<<"Positions invalides."<<endl;
    }
    if (pos1 == pos2) {
        cout<<"Positions identiques, aucun échange nécessaire"<<endl;
    }
    // Récupération des nœuds à échanger
    LinkedList<T>* node1 = this;
    LinkedList<T>* node2 = this;
    for (int i = 0; i < pos1; ++i) {
        node1 = node1->next_;
    }
    for (int i = 0; i < pos2; ++i) {
        node2 = node2->next_;
    }
    // Échange des valeurs
    swap(node1->item_, node2->item_);
    // J'utilise ici std::swap
    // Utilise la technique de swap classique avec une valeur temporaire.
}