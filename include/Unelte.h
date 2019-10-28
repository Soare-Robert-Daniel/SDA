#ifndef UNELTE_H
#define UNELTE_H

#include <iostream>

class Unelte
{
    public:
        Unelte();
        virtual ~Unelte();
        static void afisareVector(int vec[], int n);
        static void afisareVectorInterval(int vec[], int startIndex, int endIndex);
        static void afisareMatrice(int ** mat, int n, int m);
    protected:
    private:
};

#endif // UNELTE_H
