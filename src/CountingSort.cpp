#include "../include/CountingSort.h"

using namespace std;

CountingSort::CountingSort()
{
    //ctor
}

CountingSort::~CountingSort()
{
    //dtor
}

void CountingSort::exe() {
    int n, vec[100];
    cout << "Citeste dimensiunea vectorului: ";
    cin >> n;
    cout << "Citeste valorile vectorului (numere mai mici decat 100): ";
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }

    countingSort(vec, n);

    cout << endl << "Final " << endl << "Vector: ";
    Unelte::afisareVector(vec, n);
    cout << endl;
}

void CountingSort::info() {
    cout << " Counting Sort ";
}

void CountingSort::countingSort(int vec[], int n)
{
    // Initializare
    int numarator[101];
    for(int i = 0; i < 101; ++i)
    {
        numarator[i] = 0;
    }

    // Inumar elementele
    for(int i = 0; i < n; ++i)
    {
        numarator[vec[i]] ++;
    }
    cout << "Numarator: ";
    Unelte::afisareVector(numarator, 101);
    int k = 0;
    for(int i = 0; i < 101; ++i){
        // vad ce elemente sunt prezente in vector
        if(numarator[i] > 0){
            // pun vectorul orginal de cate ori apare valoare numarata
            for(int j = 0; j < numarator[i]; ++j){
                vec[k] = i;
                k ++;
            }
        }
    }
}
