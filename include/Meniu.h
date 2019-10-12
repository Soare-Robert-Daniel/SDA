//
// Created by Robert on 10/5/2019.
//

#ifndef SDA_MENIU_H
#define SDA_MENIU_H

#include <vector>
#include <string>
#include "Program.h"
#include <iostream>

class Meniu {
public:
    Meniu(const std::string &nume) : nume(nume) {}

    void exe();
    void adaugaOptiune(Program* p){
        optiuni.push_back(p);
    }

private:
    std::vector<Program *> optiuni;
    std::string nume;
public:
    const std::vector<Program *> &getOptiuni() const {
        return optiuni;
    }

    void setOptiuni(const std::vector<Program *> &optiuni) {
        Meniu::optiuni = optiuni;
    }

    const std::string &getNume() const {
        return nume;
    }

    void setNume(const std::string &nume) {
        Meniu::nume = nume;
    }
};


#endif //SDA_MENIU_H
