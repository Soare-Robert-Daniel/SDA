#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "Program.h"


class BubbleSort : public Program
{
    public:
        BubbleSort();
        virtual ~BubbleSort();
        void exe() override;
        void info() override;
    protected:
        void bubbleSort(int vec[], int& n);
};

#endif // BUBBLESORT_H
