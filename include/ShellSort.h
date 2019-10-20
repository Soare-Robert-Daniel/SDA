//
// Created by Robert on 10/20/2019.
//

#ifndef SDA_SHELLSORT_H
#define SDA_SHELLSORT_H

#include "Program.h"

class ShellSort : public Program {
public:
    ShellSort(){}
    ~ShellSort(){}
    void exe() override;
    void info() override;
private:
    void shellSort(int vec[], int n);
};


#endif //SDA_SHELLSORT_H
