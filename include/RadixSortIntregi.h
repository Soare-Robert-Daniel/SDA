//
// Created by Robert on 28-Oct-19.
//

#ifndef SDA_RADIXSORTINTREGI_H
#define SDA_RADIXSORTINTREGI_H


#include "Program.h"
class RadixSortIntregi: public Program {
public:
    RadixSortIntregi(){}
    ~RadixSortIntregi(){}
    void exe() override;
    void info() override;

private:
    void radixSort(int vec[], int n);
    void copiazaLinii(int a[], int b[], int n);
    void descompuneNumar(int x, int vec[]);
    int recombinare(int linie[]);
};


#endif //SDA_RADIXSORTINTREGI_H
