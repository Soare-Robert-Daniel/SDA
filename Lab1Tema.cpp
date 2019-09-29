//
// Created by Robert on 9/29/2019.
//

#include "Lab1Tema.h"
bool isPrime(const int & x){
    for(int i = 0; i <= x/2; ++i) {
        if( x % i == 0){
            return false;
        }
    }
    return true;
}

/*
 * Returneaza o lista cu factorii primi ai unui un numar dat.
 * Return a list with the prime factors of a given number.
 */
std::vector<int> primeFactors(const int & x) {
    std::vector<int> list;
    for(int factor = 0; factor <= x / 2; ++factor) {
        if(x % factor == 0 && isPrime(factor)){
            list.push_back(factor);
        }
    }
    return list;
}

