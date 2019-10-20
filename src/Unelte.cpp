#include "../include/Unelte.h"

Unelte::Unelte()
{
    //ctor
}

Unelte::~Unelte()
{
    //dtor
}

void Unelte::afisareVector(int vec[], int n)
{
    afisareVectorInterval(vec, 0, n - 1);
}

void Unelte::afisareVectorInterval(int vec[], int startIndex, int endIndex)
{
    std::cout << "[ ";
    for(int i = startIndex; i < endIndex; ++i){
        std::cout << vec[i] << ", ";
    }
    std::cout << vec[endIndex] << " ]";
}
