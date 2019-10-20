//
// Created by Robert on 10/20/2019.
//

#ifndef SDA_RADIXSORT_H
#define SDA_RADIXSORT_H

#include "Program.h"
class RadixSort: public Program {
public:
    RadixSort(){}
    ~RadixSort(){}
    void exe() override;
    void info() override;

private:
    void radixSort(int vec[], int n);
    void schimbaLinii(int a[], int b[], int n);
    void copiazaLinii(int a[], int b[], int n);
    void descompuneNumar(int x, int vec[]);
    int recombinare(int linie[]);
};


#endif //SDA_RADIXSORT_H
