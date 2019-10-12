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
int n, arr[100];
    cout << "Citeste dimensiunea vectorului: ";
    cin >> n;
    cout << "Citeste valorile vectorului: ";
    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    selectionSort(arr, n);

    cout << endl << "Final " << endl << "Vector: ";
    for(int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void SelectionSort::selectionSort(int arr[], int& n)
{
    for(int i = 0; i < n; ++i)
    {
        swap(arr[i], arr[gasesteMinimumIndex(arr, n, i)]);
    }
}

int SelectionSort::gasesteMinimumIndex(int arr[], int& n, int startIndex)
{
    int val_min = arr[startIndex];
    int index_min = startIndex;
    for(int i = startIndex + 1; i < n; ++i)
    {
        if(arr[i] < val_min)
        {
            val_min = arr[i];
            index_min = i;
        }
    }

    return index_min;
}
