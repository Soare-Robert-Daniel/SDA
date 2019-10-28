//
// Created by Robert on 28-Oct-19.
//

#ifndef SDA_RADIXSORTREALE_H
#define SDA_RADIXSORTREALE_H


#include "Program.h"
class RadixSortReale: public Program {
public:
    RadixSortReale(){}
    ~RadixSortReale(){}
    void exe() override;
    void info() override;

private:

    void radixSort(float vec[], int n);
    void copiazaLinii(int a[], int b[], int n);
    void descompuneNumar(float x, int linie[]);
    float recombinare(int linie[]);
    int numarDeZecimale(float x);
};


#endif //SDA_RADIXSORTREALE_H
