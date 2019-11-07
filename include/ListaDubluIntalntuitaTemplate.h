//
// Created by Robert on 01-Nov-19.
//

#ifndef SDA_LISTADUBLUINTALNTUITATEMPLATE_H
#define SDA_LISTADUBLUINTALNTUITATEMPLATE_H


#include "Program.h"

class ListaDubluIntalntuitaTemplate : public Program {
public:
    void exe() override ;
    void info() override ;

private:
    typedef int Valoare;

    struct Nod {
        Valoare val;
        Nod* urm;
        Nod* anter;

        Nod() {
            val = 0;
            urm = NULL;
            anter = NULL;
        }

        Nod(Valoare _val) {
            val = _val;
            urm = NULL;
            anter = NULL;
        }

        Nod(Nod const &nod){
            val = nod.val;
            urm = nod.urm;
            anter = nod.anter;
        }

        bool operator ==(const Nod& other);
    };

    void inserareNod(Nod* &cap, Nod nodDeInserat, int pozitie);
    void stergeNod(Nod* &cap, int pozitie);

    void afisare(Nod* &cap);

    void adaugaInFata(Nod* &cap, Nod nodDeAdaugat);
    void adaugaLaFinal(Nod* &cap, Nod nodDeAdaugat);
};


#endif //SDA_LISTADUBLUINTALNTUITATEMPLATE_H
