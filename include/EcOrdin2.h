//
// Created by Robert on 10/5/2019.
//

#ifndef SDA_ECORDIN2_H
#define SDA_ECORDIN2_H

#include "Program.h"
#include <cmath>

class EcOrdin2 : public Program {

public:
    EcOrdin2()= default;
    virtual ~EcOrdin2()= default;
    void exe() override;
    void info() override;

private:
    struct constante {
        float a = 0.0;
        float b = 0.0;
        float c = 0.0;
        float delta;

        constante(){}

        constante(float _a, float _b, float _c) : a(_a), b(_b), c(_c) {

        }
    };

    struct complex {
        float real = 0.0;
        float img = 0.0;

        complex(float _real, float _img) : real(_real), img(_img){}
    };

    static float calcDelta(const constante& c);
    static void afiseazaSolReale(const constante& c);
    static void afiseazaSolComplexe(const constante& c);
    static void afiseazaSolGrad1(const constante& c);
};


#endif //SDA_ECORDIN2_H
