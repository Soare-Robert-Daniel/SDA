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

void Unelte::afisareMatrice(int **mat, int n, int m) {

    std::cout << std::endl;
    for(int i = 0; i < n; ++i){
        afisareVector(mat[i], m);
        std::cout << std::endl;
    }
    std::cout << std::endl;

}

void Unelte::afisareVector(float *vec, int n) {
    afisareVectorInterval(vec, 0, n - 1);
}

void Unelte::afisareVectorInterval(float *vec, int startIndex, int endIndex) {
    std::cout << "[ ";
    for(int i = startIndex; i < endIndex; ++i){
        std::cout << vec[i] << ", ";
    }
    std::cout << vec[endIndex] << " ]";
}
