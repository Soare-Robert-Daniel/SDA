//
// Created by Robert on 10/5/2019.
//

#ifndef SDA_PRIME_H
#define SDA_PRIME_H

#include <iostream>
#include "vector"
#include "ProgramBlueprint.h"

class Prime : public Program {
public:
    Prime()= default;
    ~Prime()= default;
    void exe() override;
    void info() override;

private:
    struct factor{
        int f;
        int putere;
    };

    static bool estePrim(const int& n);
    void afiseazaDescompunere(const int& n);

};


#endif //SDA_PRIME_H
