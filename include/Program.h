//
// Created by Robert on 10/5/2019.
//
#include "../include/Unelte.h"
#include <iostream>
#ifndef SDA_PROGRAM_H
#define SDA_PROGRAM_H

class Program{
public:
    virtual void exe() = 0;
    virtual void info() = 0;
};

#endif //SDA_PROGRAM_H
