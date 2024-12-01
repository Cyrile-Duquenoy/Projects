#include"class_LinkedList.hpp"
using namespace std;

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

//Destructor
template<typename T>
LinkedList<T>::~LinkedList(){
    delete next_;
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
    return (next_ == NULL) ? *this : next_->last();
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
    return (this == NULL) ? 0 : 1 + (next_ ? next_->length() : 0);
}

// Insere un elmt juste àprès le premier
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

