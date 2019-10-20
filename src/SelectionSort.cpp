#include "../include/SelectionSort.h"

using namespace std;

SelectionSort::SelectionSort()
{
    //ctor
}

SelectionSort::~SelectionSort()
{
    //dtor
}

void SelectionSort::info()
{
    cout << " Selection Sort ";
}

void SelectionSort::exe()
{
int n, vec[100];
    cout << "Citeste dimensiunea vectorului: ";
    cin >> n;
    cout << "Citeste valorile vectorului: ";
    for(int i = 0; i < n; ++i)
    {
        cin >> vec[i];
    }
    selectionSort(vec, n);

    cout << endl << "Final " << endl << "Vector: ";
    Unelte::afisareVector(vec, n);
    cout << endl;
}

void SelectionSort::selectionSort(int vec[], int& n)
{
    for(int i = 0; i < n; ++i)
    {
        swap(vec[i], vec[gasesteMinimumIndex(vec, n, i)]);
        cout << "Pass " << i << " : ";
        Unelte::afisareVector(vec, n);
        cout << endl;
    }
}

int SelectionSort::gasesteMinimumIndex(int vec[], int& n, int startIndex)
{
    int val_min = vec[startIndex];
    int index_min = startIndex;
    for(int i = startIndex + 1; i < n; ++i)
    {
        if(vec[i] < val_min)
        {
            val_min = vec[i];
            index_min = i;
        }
    }

    return index_min;
}
