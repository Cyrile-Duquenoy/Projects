#pragma once
#include <iostream>

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
    if (scan2 != nullptr && scan2->item_ < scan1->item_) {
        LinkedList<T>* temp = new LinkedList<T>(scan2->item_, scan1); // Créer un nouveau maillon pour l'élément de L
        scan1 = temp;  // Placer l'élément en tête de la liste
        scan2 = scan2->next_;  // Avancer scan2
    }
    // Étape 3 : Boucle principale sur scan1
    for (; scan1->next_ != nullptr; scan1 = scan1->next_) {
        // Étape 4 : Si l'élément pointé par scan2 est égal à l'élément pointé par scan1, utiliser l'opérateur +=
        if (scan2 != nullptr && scan2->item_ == scan1->item_) {
            scan1->item_ += scan2->item_;  // Utilisation de l'opérateur += de T
            scan2 = scan2->next_;  // Avancer scan2
        }
        // Étape 5 : Boucle interne pour insérer les éléments de L entre les éléments de N
        while (scan2 != nullptr && scan2->item_ < scan1->next_->item_) {
            LinkedList<T>* temp = new LinkedList<T>(scan2->item_, scan1->next_); // Créer un nouveau maillon
            scan1->next_ = temp;  // Insérer l'élément entre scan1 et scan1->next_
            scan1 = temp;  // Avancer scan1 pour qu'il pointe sur l'élément inséré
            scan2 = scan2->next_;  // Avancer scan2
        }
    }
    // Étape 6 : Si des éléments restent dans L, les ajouter à la fin de la liste actuelle
    while (scan2 != nullptr) {
        LinkedList<T>* temp = new LinkedList<T>(scan2->item_);
        scan1->next_ = temp;
        scan1 = temp;
        scan2 = scan2->next_;
    }
    return *this;
}