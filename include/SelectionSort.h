#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "Program.h"

#include <iostream>

class SelectionSort : public Program
{
    public:
        SelectionSort();
        virtual ~SelectionSort();
        void exe() override;
        void info() override;
    private:
        void selectionSort(int arr[], int& n);
        int gasesteMinimumIndex(int arr[], int& n, int startIndex);
};

#endif // SELECTIONSORT_H
