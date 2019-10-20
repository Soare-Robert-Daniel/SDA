//
// Created by Robert on 10/20/2019.
//

#include "../include/ShellSort.h"

using namespace std;

void ShellSort::exe() {
    int n, vec[100];
    cout << "Citeste dimensiunea vectorului: ";
    cin >> n;
    cout << "Citeste valorile vectorului: ";
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }

    shellSort(vec, n);

    cout << endl << "Final " << endl << "Vector: ";
    Unelte::afisareVector(vec, n);
    cout << endl;
}

void ShellSort::info() {
    cout << " Shell Sort ";
}

void ShellSort::shellSort(int vec[], int n) {
    for(int interval = n / 2; interval > 0; interval /= 2){
        for(int i = 0; i < n; ++i){
            for(int j = i; j < (n - interval) && vec[j + interval] < vec[j]; j += interval){
                swap(vec[j], vec[j + interval]);
            }
        }
        cout << "Pentru interval " << interval << " : ";
        Unelte::afisareVector(vec, n);
        cout << endl;
    }
}
