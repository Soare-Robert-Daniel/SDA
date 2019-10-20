#include "../include/QuickSort.h"

using namespace std;

QuickSort::QuickSort()
{
    //ctor
}

QuickSort::~QuickSort()
{
    //dtor
}

void QuickSort::exe() {
    int n, vec[100];
    cout << "Citeste dimensiunea vectorului: ";
    cin >> n;
    cout << "Citeste valorile vectorului: ";
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }
    quickSort(vec, 0, n - 1);

    cout << endl << "Final " << endl << "Vector: ";
    Unelte::afisareVector(vec, n);
    cout << endl;
}

void QuickSort::info() {
    cout << " Quick Sort ";
}

void QuickSort::quickSort(int vec[], int stanga, int dreapta)
{
    if(stanga <= dreapta){
        int pivot = partitie(vec, stanga, dreapta);
        quickSort(vec, stanga, pivot-1);
        quickSort(vec, pivot + 1, dreapta);
    }
}

int QuickSort::partitie(int vec[], int stanga, int dreapta)
{
    /*

        Ultimul element din vector este considerat pivot

    */
    // Limita este pozitia de unde valorile din stanga sunt mai mice
    // decat pivotul, iar cele din drepata sunt mai mari decat pivotul
    int limita = stanga;

    for(int i = stanga; i <= dreapta - 1; ++i)
    {
        if(vec[i] < vec[dreapta])
        {
            swap(vec[limita], vec[i]);
            limita ++;
        }
    }

    swap(vec[limita], vec[dreapta]);
    // returneaza pivotul
    return limita ;
}
