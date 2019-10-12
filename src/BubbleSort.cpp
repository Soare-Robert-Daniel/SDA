#include "../include/BubbleSort.h"

using namespace std;
BubbleSort::BubbleSort()
{
    //ctor
}

BubbleSort::~BubbleSort()
{
    //dtor
}

void BubbleSort::info()
{
    cout << " Bubble Sort ";
}

void BubbleSort::exe()
{
    int n, arr[100];
    cout << "Citeste dimensiunea vectorului: ";
    cin >> n;
    cout << "Citeste valorile vectorului: ";
    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    bubbleSort(arr, n);

    cout << endl << "Final " << endl << "Vector: ";
    for(int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void BubbleSort::bubbleSort(int arr[], int& n)
{
    cout << endl << "Initializare sortare..." << endl;
    int faza = 0;

    bool esteSortat = true;
    do
    {
        // presupun ca este sortat
        esteSortat = true;
        // verifica daca este sortat
        int i = 0;
/*
        for(int i = 0; i < n - 1; ++i)
        {
            if(arr[i] > arr[i+1])
            {
                // aflu ca nu este sortat :)
                esteSortat = false;
                break;
            }
        }


*/
        for(int i = 0; i < n - 1 - faza; ++i)
        {
            if(arr[i] > arr[i+1])
            {
                esteSortat = false;
                swap(arr[i], arr[i+1]);
            }
        }

        cout << "# Stare vector dupa faza " << faza << endl << "Vector: ";
        for(int i = 0; i < n; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        faza ++;
    }
    while(!esteSortat);
}
