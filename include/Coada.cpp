//
// Created by Robert on 26-Nov-19.
//

#include "Coada.h"

void Coada::adauga(Coada::Nod nod) {
    if(inceput == nullptr) {
        inceput = new Nod(nod);
        sfarsit = inceput;
    } else {
        sfarsit->urm = new Nod(nod);
        sfarsit = sfarsit->urm;
    }
}

Coada::Nod Coada::scoate() {
    Nod * nodDeSters = inceput;
    Nod copie(*nodDeSters);

    inceput = inceput->urm;
    delete nodDeSters;
    nodDeSters = nullptr;

    return copie;
}

bool Coada::esteGoala() {
    return inceput == nullptr && sfarsit == nullptr;
}
