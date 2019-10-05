//
// Created by Robert on 10/5/2019.
//

#include "Matrice.h"

using namespace std;

void Matrice::exe() {
    matrice A = citesteMatrice();
    matrice B = citesteMatrice();
    if(A.row == A.col) {
        matrice C = A * B;
        cout << "Rezultat: ";
        afiseazaMatrice(C);
    } else {
        cout << "Nu se poate efectua inmultirea, verificati dimensiunile matrielor date!" << endl;
    }
}

void Matrice::info() {
    cout << " Inmultire matrice! ";
}

Matrice::matrice Matrice::citesteMatrice() {
    matrice tmp;
    cout << "Citeste nr. linii: "; cin >> tmp.row;
    cout << "Citeste nr. coloane: "; cin >> tmp.col;
    cout << "Citeste valori matrice: " << endl;
    for(int i = 0; i < tmp.row; ++i){
        for(int j = 0; j < tmp.col; ++j){
            cin >> tmp.m[i][j];
        }
    }
    return tmp;
}

void Matrice::afiseazaMatrice(const matrice& mat) {
    cout << endl;
    for(int i = 0; i < mat.row; ++i){
        for(int j = 0; j < mat.col; ++j){
            cout << mat.m[i][j] << " ";
        }
        cout << endl;
    }
}
