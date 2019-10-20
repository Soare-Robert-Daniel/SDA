//
// Created by Robert on 10/5/2019.
//

#ifndef SDA_MATRICE_H
#define SDA_MATRICE_H

#include "Program.h"

class Matrice : public Program {
public:
    Matrice()= default;
    ~Matrice()= default;
    void exe() override;
    void info() override;

private:
    struct matrice{
        int row;
        int col;
        float m[10][10];

        matrice()= default;

        matrice(int _row, int _col) : row(_row), col(_col){
            for(int i = 0; i < _row; ++i){
                for(int j = 0; j < _col; ++j){
                    m[i][j] = 0;
                }
            }
        }

        matrice(int _row, int _col, float _m[10][10]) : row(_row), col(_col){
            for(int i = 0; i < _row; ++i){
                for(int j = 0; j < _col; ++j){
                    m[i][j] = _m[i][j];
                }
            }
        }

        matrice operator *(const matrice& mat){
            matrice tmp(row, col);

            for(int i = 0; i < tmp.row; ++i){
                for(int j = 0; j < mat.col; ++j){
                    for(int k = 0; k < mat.col; ++k){
                        tmp.m[i][j] += m[i][k] * mat.m[k][j];
                    }
                }
            }
            return tmp;
        }
    };

    static matrice citesteMatrice();
    static void afiseazaMatrice(const matrice& mat);
};


#endif //SDA_MATRICE_H
