//
// Created by Robert on 10/12/2019.
//

#ifndef SDA_MERGESORT_H
#define SDA_MERGESORT_H

#include <iostream>
#include "Program.h"

class MergeSort : public Program {
public:
    MergeSort()= default;
    ~MergeSort()= default;
    void exe() override;
    void info() override;

private:
    void mergeSort(int vec[], int stanga, int dreapta);
    void interclasare(int vec[], int stanga, int mijloc, int dreapta);
};


#endif //SDA_MERGESORT_H
