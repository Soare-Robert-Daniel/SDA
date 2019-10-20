//
// Created by Robert on 10/12/2019.
//

#include "../include/MergeSort.h"

using namespace std;

void MergeSort::exe() {
    int n, vec[100];
    cout << "Citeste dimensiunea vectorului: ";
    cin >> n;
    cout << "Citeste valorile vectorului: ";
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    mergeSort(vec, 0, n - 1);

    cout << endl << "Final " << endl << "Vector: ";
    for (int i = 0; i < n; ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

void MergeSort::info() {
    cout << " Merge Sort ";
}

void MergeSort::mergeSort(int *vec, int stanga, int dreapta) {
    if (stanga < dreapta) {
        int mijloc = (dreapta + stanga) / 2;

        mergeSort(vec, stanga, mijloc);
        mergeSort(vec, mijloc + 1, dreapta);

        interclasare(vec, stanga, mijloc, dreapta);
        cout << "Rezultat interclasare pentru stanga = " << stanga << " si dreapta = " << dreapta << " => ";
        Unelte::afisareVectorInterval(vec, stanga, dreapta);
        cout << endl;
    }
}

void MergeSort::interclasare(int *vec, int stanga, int mijloc, int dreapta) {
    int auxiliar[100], k = 0;
    int i = stanga, j = mijloc + 1;

    // fac interclasarea
    while (i <= mijloc && j <= dreapta) {
        if (vec[i] < vec[j]) {
            auxiliar[k] = vec[i];
            i++;
        } else {
            auxiliar[k] = vec[j];
            j++;
        }
        k++;
    }

    // verific daca au mai ramas valori
    while (i <= mijloc) {
        auxiliar[k] = vec[i];
        i++;
        k++;
    }

    while (j <= dreapta) {
        auxiliar[k] = vec[j];
        j++;
        k++;
    }

    // copiez elementele interclasate inapoi in vectorul original
    for (int index = 0; index < k; ++index) {
        vec[index + stanga] = auxiliar[index];
    }
}


