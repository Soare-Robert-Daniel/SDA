#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H

#include "Program.h"
#include <iostream>

class CountingSort : public Program
{
    public:
        CountingSort();
        virtual ~CountingSort();
        void exe() override;
        void info() override;
        void countingSort(int vec[], int n);
};

#endif // COUNTINGSORT_H
