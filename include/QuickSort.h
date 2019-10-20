#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "Program.h"

class QuickSort : public Program
{
    public:
        QuickSort();
        virtual ~QuickSort();
        void exe() override;
        void info() override;
    protected:
        void quickSort(int vec[], int stanga, int dreapta);
        int partitie(int vec[], int stanga, int dreapta);
    private:
};

#endif // QUICKSORT_H
