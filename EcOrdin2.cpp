//
// Created by Robert on 10/5/2019.
//

#include "EcOrdin2.h"

using namespace std;

void EcOrdin2::exe() {
    constante c;
    cout << "Ecuatie de forma: ax^2 + bx + c = 0" << endl;
    cout << "Citeste a: "; cin >> c.a;
    cout << "Citeste b: "; cin >> c.b;
    cout << "Citeste c: "; cin >> c.c;

    if( c.a == 0){
        if(c.b == 0) {
            if(c.c == 0) {
                cout << "Exista o infinitate de solutii!";
            }
            else {
                cout << "Nu exista solutie!";
            }
        }
        else {
            afiseazaSolGrad1(c);
        }
    } else {
        c.delta = calcDelta(c);
        if(c.delta >= 0){
            afiseazaSolReale(c);
        }
        else {
            afiseazaSolComplexe(c);
        }
    }
}

float EcOrdin2::calcDelta(const EcOrdin2::constante &c) {
    return c.b * c.b - 4 * c.b * c.c;
}

void EcOrdin2::afiseazaSolReale(const EcOrdin2::constante &c) {
    float sol1 = (-c.b + sqrt(c.delta)) / (2 * c.a);
    cout << "Solutii reale: " << sol1;
    if(c.delta > 0){
        float sol2 = (-c.b - sqrt(c.delta)) / (2 * c.a);
        cout << " si " << sol2;
    }
    cout << endl;
}

void EcOrdin2::afiseazaSolComplexe(const EcOrdin2::constante &c) {
    complex sol(
            -c.b / (2 * c.a),
            sqrt(abs(c.delta)) / (2 * c.a)
            );


    cout << "Solutii complexe: " << sol.real << " + i * " << sol.img << " si " << sol.real << " - i * " << sol.img << endl;

}

void EcOrdin2::afiseazaSolGrad1(const EcOrdin2::constante &c) {
    float sol = - c.c / c.b;
    cout << "Solutie: " << sol;
}

void EcOrdin2::info() {
    cout << " Rezolvarea unei ecuatii de gradul 2 ";
}
