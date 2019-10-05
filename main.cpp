#include <iostream>
#include <vector>
#include "ProgramBlueprint.h"
#include "Meniu.h"
#include "EcOrdin2.h"
#include "Matrice.h"
#include "Prime.h"
using namespace std;

void exe(vector<Meniu> meniuri);

int main() {

    vector<Meniu> meniuri;

    // CREEEAZA MENIU
    Meniu diverse("Diverse");
    diverse.adaugaOptiune( new EcOrdin2());
    diverse.adaugaOptiune( new Matrice());
    diverse.adaugaOptiune( new Prime());

    // ADAUGA MENIURI
    meniuri.push_back(diverse);

    exe(meniuri);
    return 0;
}

void exe(vector<Meniu> meniuri) {
    int choice;

    do {
        cout << endl << "+----------------------- MENIU PRICIPAL -----------------------+" << endl;
        cout << "Optiuni: " << endl;
        cout << "   0) Iesire!" << endl;
        for(unsigned int i = 0; i < meniuri.size(); i++){
            cout << "   " << i + 1 << ") ";
            cout << meniuri[i].getNume();
            cout << endl;
        }
        cout << "Introduceti numarul optiunii: "; cin >> choice;
        if(choice != 0){
            if(choice <= meniuri.size() ){
                meniuri[choice - 1].exe();
            } else {
                cout << "Optiune invalida!";
            }
        }
    } while(choice != 0);
    cout << endl << "+-------------------- SFARSIT DE PROGRAM --------------------+" << endl;
}