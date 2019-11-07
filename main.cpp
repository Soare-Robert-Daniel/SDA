#include <iostream>
#include <vector>

#include "include/Meniu.h"
#include "include/Diverse.h"
#include "include/Sortari.h"
#include "include/Lista.h"

using namespace std;

void exe(vector<Meniu> meniuri);

int main() {

    vector<Meniu> meniuri;

    // CREEEAZA MENIU
    Meniu diverse("Diverse");
    diverse.adaugaOptiune(new EcOrdin2());
    diverse.adaugaOptiune(new Matrice());
    diverse.adaugaOptiune(new Prime());


    Meniu sortare("Algoritmi de sortare");
    sortare.adaugaOptiune(new BubbleSort());
    sortare.adaugaOptiune(new CountingSort());
    sortare.adaugaOptiune(new SelectionSort());
    sortare.adaugaOptiune(new MergeSort());
    sortare.adaugaOptiune(new QuickSort());
    sortare.adaugaOptiune(new ShellSort());
    sortare.adaugaOptiune(new RadixSort());
    sortare.adaugaOptiune(new RadixSortReale());


    Meniu liste("Liste");
    liste.adaugaOptiune(new ListaDubluIntalntuitaTemplate());

    // ADAUGA MENIURIdreapta
    meniuri.push_back(diverse);
    meniuri.push_back(sortare);
    meniuri.push_back(liste);

    exe(meniuri);
    return 0;
}

void exe(vector<Meniu> meniuri) {

    cout << "          _                                    \r\n  ___  __| | __ _                              \r\n / __|/ _` |/ _` |                             \r\n \\__ \\ (_| | (_| |                             \r\n |___/\\__,_|\\__,_|         _               _   \r\n | |__  _   _    _ __ ___ | |__   ___ _ __| |_ \r\n | '_ \\| | | |  | '__/ _ \\| '_ \\ / _ \\ '__| __|\r\n | |_) | |_| |  | | | (_) | |_) |  __/ |  | |_ \r\n |_.__/ \\__, |  |_|  \\___/|_.__/ \\___|_|   \\__|\r\n        |___/";

    int choice;

    do {
        cout << endl << "+----------------------- MENIU PRICIPAL -----------------------+" << endl;
        cout << "Optiuni: " << endl;
        cout << "   0) Iesire!" << endl;
        for (unsigned int i = 0; i < meniuri.size(); i++) {
            cout << "   " << i + 1 << ") ";
            cout << meniuri[i].getNume();
            cout << endl;
        }
        cout << "Introduceti numarul optiunii: ";
        cin >> choice;
        if (choice != 0) {
            if (choice <= meniuri.size()) {
                meniuri[choice - 1].exe();
            } else {
                cout << "Optiune invalida!";
            }
        }
    } while (choice != 0);
    cout << endl << "+-------------------- SFARSIT DE PROGRAM --------------------+" << endl;
}
