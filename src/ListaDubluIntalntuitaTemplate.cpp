//
// Created by Robert on 01-Nov-19.
//

#include "../include/ListaDubluIntalntuitaTemplate.h"

using namespace std;

void ListaDubluIntalntuitaTemplate::info() {
    cout << " Template Lista Dublue Inlantuita ";
}

void ListaDubluIntalntuitaTemplate::exe() {

    Nod* cap = NULL;

    int n = 0, valoareCitita = 0, pozitieCitita = 0;
    cout << "Cate elemente doriti sa introduceti: "; cin >> n;
    cout <<"Introduceti elementele: ";
    for(int i = 0; i < n; ++i){
        cin >> valoareCitita;
        adaugaLaFinal(cap, Nod(valoareCitita));
        afisare(cap);
    }

    afisare(cap);
}

void ListaDubluIntalntuitaTemplate::inserareNod(Nod *&cap, Nod nodDeInserat, int pozitie) {
    if (cap == NULL) {
        // initializez lista
        cout << "Initializare\n";
        cap = new Nod(nodDeInserat);
    } else {
        Nod* noulNod = new Nod(nodDeInserat);

        if(pozitie == 0){
            noulNod->urm = cap;
            noulNod->anter = NULL;

            cap->anter = noulNod;
        }
        else {
            Nod* iter = cap;
            int pozitieCurenta = 0;

            while(iter->urm != NULL && (pozitieCurenta + 1) != pozitie) {
                iter = iter->urm;
                pozitieCurenta ++;
            }

            Nod* nodAnterior = iter;
            Nod* nodUrmator = iter->urm;

            nodAnterior->urm = noulNod;
            if(nodUrmator != NULL) {
                nodUrmator->anter = noulNod;
            }

            noulNod->anter = nodAnterior;
            noulNod->urm = nodUrmator;

        }
    }
}

void ListaDubluIntalntuitaTemplate::stergeNod(Nod *&cap, int pozitie) {
    if(cap != NULL) {
        Nod* iter = cap;
        int pozitieCurenta = 0;

        while(iter->urm != NULL && pozitieCurenta != pozitie) {
            iter = iter->urm;
            pozitieCurenta ++;
        }

        Nod* nodDeSters = iter;
        Nod* nodAnterior = nodDeSters->anter;
        Nod* nodUrmator = nodDeSters->urm;

        nodAnterior->urm = nodUrmator;
        nodUrmator->anter = nodAnterior;

        delete nodDeSters;
        nodDeSters = NULL;
    }
}

void ListaDubluIntalntuitaTemplate::afisare(Nod *&cap) {
    if(cap != NULL) {
        Nod* iter = cap;
        cout << "Afisare Lista: ";
        while(iter->urm != NULL ) {
            cout << iter->val << " <-> ";
            iter = iter->urm;
        }
        cout << iter->val << endl;
    } else {
        cout << "Lista goala" << endl;
    }
}

void ListaDubluIntalntuitaTemplate::adaugaInFata (Nod* &cap, Nod nodDeAdaugat) {
    inserareNod(cap, nodDeAdaugat, 0);
}

void ListaDubluIntalntuitaTemplate::adaugaLaFinal(Nod *&cap, Nod nodDeAdaugat) {
    inserareNod(cap, nodDeAdaugat, -1);
}

bool ListaDubluIntalntuitaTemplate::Nod::operator==(const Nod &other) {
    return val == other.val;
}
