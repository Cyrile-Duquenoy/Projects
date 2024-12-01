#include"class_LinkedList.hpp"

// BUBBLE SORT OPT//
template<typename T>
void LinkedList<T>::bubble_sort_opt(int length) {
    if (length<=1) cout<<"Rien à trier"<<endl; // Liste vide ou un seul élément, rien à trier.
    bool swapped;
    do {
        swapped = false;
        LinkedList<T>* current = this;
        for (int i=0; i < length-1; ++i) {
            if (current->item_ > current->next_->item_) {
                this->switch_at(i, i+1);
                swapped = true;
            }
            current = current->next_;
        }
        length--; // Réduit la plage à examiner
    } while (swapped);
}

// BUBBLE SORT //
template<typename T>
void LinkedList<T>::bubble_sort(int length) {
    if (length<=1) cout<<"Rien à trier"<<endl; // Liste vide ou un seul élément, rien à trier.
    for (int i=length-1;i>=1;--i) {
        LinkedList<T>* current = this;
        for (int j = 0; j < i; ++j) {
            if (current->item_ > current->next_->item_) {
                this->switch_at(j,j+1);
            }
            current = current->next_;
        }
    }
}

// TRI FUSION //
// CLASSIQUEMENT EN 2 FONCTIONS //

template<typename T>
LinkedList<T>* LinkedList<T>::fusion(LinkedList<T>* scan1, LinkedList<T>* scan2){
    if (scan1==NULL) return scan2;
    if (scan2==NULL) return scan1;
    LinkedList<T>* res=NULL;
    if (scan1->item_<=scan2->item_){
        res=scan1;
        res->next_=fusion(scan1->next_, scan2);
    }
    else{
        res=scan2;
        res->next_= fusion(scan1, scan2->next_);
    }
    return res;
}

template<typename T>
LinkedList<T>* LinkedList<T>::fusion_sort(int length) {
    if (length <= 1) return this;
    // Trouve le milieu de la liste
    LinkedList<T>* scan1 = this;
    LinkedList<T>* scan2 = this;
    LinkedList<T>* prev = NULL;
    for (int i = 0; i < length / 2; ++i) {
        prev=scan1;
        scan1=scan1->next_;
    }
    if(prev) prev->next_=NULL;
    scan2=scan1->next_;
    scan1->next_==NULL;
    LinkedList<T>* left = this->fusion_sort(length / 2);
    LinkedList<T>* right = scan1->fusion_sort(length - length / 2);
    return fusion(left, right);
}




