//
// Created by Robert on 10/20/2019.
//

#include "../include/RadixSort.h"

using namespace std;

void RadixSort::exe() {
    int n, vec[100];
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

void RadixSort::info() {
    cout << " Radix Sort ";
}

void RadixSort::radixSort(int *vec, int n) {

    auto mat = new int[n][12];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 12; ++j){
            mat[i][j] = 0;
        }
    }

    int lungMax = 0;
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
        int numarator[11];
        for(int i = 0; i < 11; ++i){
            numarator[i] = 0;
        }

        // Calculez de cate ori apare fiecare cifra
        for(int i = 0; i < n; ++i){
            numarator[mat[i][pozitie]] ++;
        }

        cout << "Numarator: ";
        Unelte::afisareVector(numarator, 11);
        cout << endl;

        // Calculez noile pozitii
        /*
         *  Daca am 7 numere cu cifra 2 si 3 numere cu cifra 2
         *  Atunci primele 7 pozitii vor fi ocupate de cele cu 2 si urmatoarele de cele cu 3
         *  Deci v[1..7] pt 2 si v[8..10] pt 3
         */
         int pozitieDeStart[11];
         pozitieDeStart[0] = 0;
         for(int i = 1; i < 11; ++i){
            pozitieDeStart[i] = pozitieDeStart[i - 1] + numarator[i - 1]; // pozitia de la care incepe numarul din fata + cate numere au acea cifr
         }

        cout << "Pozitie start: ";
        Unelte::afisareVector(pozitieDeStart, 11);
        cout << endl;

        auto rezultat = new int[n][12];
         for(int i = 0; i < n; ++i){
             copiazaLinii( rezultat[  pozitieDeStart[ mat[i][pozitie]]  ], mat[i], mat[i][0] + 1);
             pozitieDeStart[mat[i][pozitie]] ++;
         }

        for(int i = 0; i < n; ++i){
            copiazaLinii( mat[i], rezultat[i],rezultat[i][0] + 1);
        }
    }

    // Recompun numerele si le adaug in vectorul original

    for(int i = 0; i < n; ++i) {
        vec[i] = recombinare(mat[i]);
    }
}

void RadixSort::schimbaLinii(int *a, int *b, int n) {
    for(int i = 0; i < n; ++i){
        swap(a[i], b[i]);
    }
}

void RadixSort::descompuneNumar(int x, int vec[]) {
    /*
     *  Pe pozitia vec[0] se va pune lungimea vectorului
     */
    int n = 0;
    while(x){
        n ++;
        vec[n] = x % 10;
        x /= 10;
    }
    vec[0] = n;
}

void RadixSort::copiazaLinii(int *a, int *b, int n) {
    for(int i = 0; i < n; ++i){
        a[i] =  b[i];
    }
}

int RadixSort::recombinare(int linie[]) {
    int x = 0;

    for(int i = linie[0]; i >= 1; i --){
        x = x*10 + linie[i];
    }

    return x;
}

