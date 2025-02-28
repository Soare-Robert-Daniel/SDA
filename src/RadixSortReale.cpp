//
// Created by Robert on 28-Oct-19.
//

#include "../include/RadixSortReale.h"
#include <cmath>
using namespace std;

void RadixSortReale::exe() {
    int n;
    float vec[100];
    cout << "Citeste dimensiunea vectorului: ";
    cin >> n;
    cout << "Citeste valorile vectorului: ";
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }

    radixSort(vec, n);

    cout << endl << "Final " << endl << "Vector: ";
    Unelte::afisareVector(vec, n);
    cout << endl;
}

void RadixSortReale::info() {
    cout << " Radix Sort Reale";
}

void RadixSortReale::radixSort(float *vec, int n) {

    int** mat = new int* [n];
    for(int i = 0; i < n; ++i){
        mat[i] = new int[12];
        for(int j = 0; j < 12; ++j){
            mat[i][j] = 0;
        }
    }


    int lungMax = 0;
    int nrMaxZecimale = 0;

    for(int i = 0; i < n; ++i){
        nrMaxZecimale = fmax(nrMaxZecimale, (numarDeZecimale  (abs(vec[i]))));
    }

    for(int i = 0; i < n; ++i){
        vec[i] *= pow(10, nrMaxZecimale);
    }

    // Descompun numerele si le pun in matrice
    for(int i = 0; i < n; ++i){
        descompuneNumar(vec[i], mat[i]);
        // Inregistrez lungimea celui mai mare numar
        if(mat[i][0] > lungMax){
            lungMax = mat[i][0];
        }
    }

    cout << "-> Lungime maxima: " << lungMax << endl;

    // Compar numerele
    for(int pozitie = 1; pozitie <= lungMax; pozitie ++){
        cout << "Pozitie: " << pozitie << endl;

        // Aplic counting sort pe coloana "pozitie"


        /*
         *  -9  -8  -7  -6  -5  -4  -3  -2  -1  0  1  2  3  4  5  6  7  8  9  - CIFRA
         *   0   1   2   3   4   5   6   7  8  9  10 11 12 13 14 15 16 17 18  - POZITIE
         */

        int numarator[19];
        int OFFSET = 9;

        for(int i = 0; i < 19; ++i){
            numarator[i] = 0;
        }

        cout << endl;
        // Calculez de cate ori apare fiecare cifra
        for(int i = 0; i < n; ++i){
            cout << i  << "-" << mat[i][pozitie] + OFFSET << " ";
            numarator[mat[i][pozitie] + OFFSET ] ++;
        }

        cout << endl;

        cout << "Numarator: ";
        Unelte::afisareVector(numarator, 19);
        cout << endl;

        // Calculez noile pozitii
        /*
         *  Daca am 7 numere cu cifra 2 si 3 numere cu cifra 2
         *  Atunci primele 7 pozitii vor fi ocupate de cele cu 2 si urmatoarele de cele cu 3
         *  Deci v[1..7] pt 2 si v[8..10] pt 3
         */
        int pozitieDeStart[19];
        pozitieDeStart[0] = 0;
        for(int i = 1; i < 19; ++i){
            pozitieDeStart[i] = pozitieDeStart[i - 1] + numarator[i - 1]; // pozitia de la care incepe numarul din fata + cate numere au acea cifr
        }

        cout << "Pozitie start: ";
        Unelte::afisareVector(pozitieDeStart, 19);
        cout << endl;


        int** rezultat = new int* [n];
        for(int i = 0; i < n; ++i){
            rezultat[i] = new int[12];
            for(int j = 0; j < 12; ++j){
                rezultat[i][j] = 0;
            }
        }


        for(int i = 0; i < n; ++i){
            copiazaLinii( rezultat[  pozitieDeStart[ mat[i][pozitie] + OFFSET ]  ], mat[i], lungMax + 1);
            pozitieDeStart[mat[i][pozitie] + OFFSET] ++;
        }



        for(int i = 0; i < n; ++i){
            copiazaLinii( mat[i], rezultat[i],lungMax + 1);
        }

        Unelte::afisareMatrice(mat, n, 12);
    }

    // Recompun numerele si le adaug in vectorul original

    for(int i = 0; i < n; ++i) {
        vec[i] = recombinare(mat[i]) * pow(10, -nrMaxZecimale);
    }
}

void RadixSortReale::descompuneNumar(float x, int linie[]) {
    /*
     *  Pe pozitia vec[0] se va pune lungimea vectorului
     */

    int semn = (x >= 0) ? 1 : -1 ;
    x = abs(x);

    long int x_intreg = int(x);

    int n = 0;
    while(x_intreg){
        n ++;
        linie[n] = x_intreg % 10 * semn;
        x_intreg /= 10;
    }
    linie[0] = n;
}

void RadixSortReale::copiazaLinii(int *a, int *b, int n) {
    for(int i = 0; i < n; ++i){
        a[i] =  b[i];
    }
}

float RadixSortReale::recombinare(int linie[]) {
    float x = 0.0;
    bool negativ = false;
    for(int i = linie[0]; i >= 1; i --){
        if(linie[i] < 0){
            negativ = true;
        }
        x = x * 10 + abs(linie[i]) * 1.0;
    }

    if(negativ){
        x *= -1;
    }

    return x;
}

int RadixSortReale::numarDeZecimale(float x) {

    int nrZeciamele = 0;

    // Aflu numarul de zecimale si transforma numarul in numar intreg prin alipirea zecimalele
    while (x - int(x) > 0){
        nrZeciamele ++;
        x *= 10;
    }

    return nrZeciamele;
}
