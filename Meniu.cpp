//
// Created by Robert on 10/5/2019.
//

#include "Meniu.h"

using namespace std;
void Meniu::exe() {
    int choice;
    cout << endl << "+----------------------- BEGIN -----------------------+" << endl;
    do {
        cout << "# " << nume << endl;
        cout << "Optiuni: " << endl;
        cout << "   0) Iesire!" << endl;
        for(unsigned int i = 0; i < optiuni.size(); i++){
            cout << "   " << i + 1 << ")";
            optiuni[i]->info();
            cout << endl;
        }
        cout << "Introduceti numarul optiunii: "; cin >> choice;
        if(choice != 0){
            if(choice <= optiuni.size() ){
                optiuni[choice - 1]->exe();
                cout << endl;
                system("pause");
            } else {
                cout << "Optiune invalida!";
            }
        }
    } while(choice != 0);
    cout << endl << "+----------------------- END ----------------------+" << endl;
}