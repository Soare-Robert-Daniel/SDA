//
// Created by Robert on 10/5/2019.
//

#include "../include/Prime.h"

using namespace std;

void Prime::exe() {
    int n;
    cout << "Numarul pe care doresti sa-l descompui: "; cin >> n;
    afiseazaDescompunere(n);
}

bool Prime::estePrim(const int& n){
    // cazul 1 si 0
    if( n < 2){
        return false;
    }
    // cazul 2 si 3
    if(n < 4){
        return true;
    }

    for(int i = 2; i * i <= n; ++i){
        if(n % i == 0){
            return false;
        }
    }

    return true;
}

void Prime::afiseazaDescompunere(const int &n) {
    vector<factor> factori;

    for(int f = 2; f * f <= n; f++){
        if(n % f == 0 && estePrim(f)){
            factor x;
            x.f = f;
            x.putere = 1;

            // verificam daca f mai are multiplii care se pot impartii la n
            int copy_n = n/f;
            while(copy_n % x.f == 0){
                copy_n /= x.f;
                x.putere ++;
            }

            factori.push_back(x);
        }
    }

    if(factori.empty()){
        cout << "Numarul este prim!";
    }
    else {
        cout << "Descompunerea in factori primi pentru " << n << " este: ";
        for (unsigned int i = 0; i < factori.size() - 1; ++i) {
            cout << factori[i].f << " ^ " << factori[i].putere << " * ";
        }
        cout << factori[factori.size() - 1].f << " ^ " << factori[factori.size() - 1].putere <<endl;
    }
}

void Prime::info() {
    cout << " Descompunere in factori primi! ";
}
