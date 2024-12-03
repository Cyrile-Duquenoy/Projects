#include "class_LinkedList.hpp"
#include "sort.hpp"

using namespace std;

int main(void){
   int mode = 1;  // Change la valeur pour choisir quel bloc exécuter
   int sort = 3; // {1:bubble sort, 2:bubble sort op, 3:fusion sort}

    // Switch case pour run uniquement certains blocs de test.
    // Pour eviter de commenter manuellement les blocs qu'on veut bypass.
    switch (mode) {
        case 1:
        // Test élémentaires
            {
                LinkedList<int> list2(1);
                cout << "longueur de list2 : " << list2.length() << endl;
                list2.print();

                int x = 2;
                list2.insert_first_item(x);
                cout << "longueur de list2 : " << list2.length() << endl;
                list2.print();

                list2.append(x);
                list2.print();

                LinkedList<int> list3 = list2;
                list3.print();

                list3.truncateItems(2);
                list3.print();

                LinkedList<int> list4(list3);
                cout<<"Test Copy Constructor"<<endl;
                list4.print();
                list4.append(5);
                list4.print();
                list4.last()=6;
                list4.print();
                cout<<list4.length()<<endl;


            }
            break;

        case 2:
        // Test de diverses méthodes
            {
                LinkedList<int> list1(5);
                for (int ii = 4; ii >= 0; ii--) {
                    list1.insert_first_item(ii);
                }
                list1.print();

                LinkedList<int> list2(10);
                for (int ii = 9; ii >= 6; ii--) {
                    list2.insert_first_item(ii);
                }
                list2.print();

                list1 += list2;
                list1.print();

                LinkedList<int> list3(2);
                list3.print();
                list3.drop_first_item();
            }
            break;

        case 3:
        // Sort test
            {
                // On change la seed de rand par rapport au temps actuel (de l'ordinateur)
                // Permet de changer de seed à chaque run
                // Et donc ne pas avoir le même rand à chaque run
                srand(time(0)); 
                LinkedList<int> list1;
                for(int ii=10;ii>=1;ii--){
                    list1.append(rand()%10);
                }
                cout<<"Liste à trier : "<<endl;
                list1.print();
                switch(sort){
                    case 1:
                    {
                        list1.bubble_sort(list1.length());
                        cout<<"Bubble Sort : "<<endl;
                        list1.print();
                    }break;

                    case 2:
                    {
                        list1.bubble_sort_opt(list1.length());
                        cout<<"Bubble Sort Opt : "<<endl;
                        list1.print();
                    }break;

                    case 3:
                    {
                        list1.fusion_sort(list1.length());
                        cout<<"Fusion Sort : "<<endl;
                        list1.print();
                    }break;
                }
            }
            break;
        default:
            cout << "Mode non valide." << endl;
            break;
    }
    return 0;
}