#ifndef MATRIZ_H
#define MATRIZ_H
#include <iostream>
#include "Entrada.h"
#define ROWS    4
#define COLS    4

class Matriz
{
    public:
        //Matriz(int row,int col,double **dPt);
        Matriz(int row,int col,Entrada* dPt[ROWS][COLS]);
        Matriz(int row,int col);
        virtual ~Matriz();
        Matriz(const Matriz& other); //Constructor de copia
        Matriz& operator=(const Matriz& other);
        Matriz operator+(const Matriz& M1);
        Matriz operator-(const Matriz& M1);
    friend std::ostream& operator<<(std::ostream& out,Matriz& rhs);

//    friend Matriz lambdaTimesIdentity(const double lambda,
//                                      const int identitySize);
    protected:

    private:
        //Entrada **mData;  //Matrix data
        Entrada* mData[ROWS][COLS];
        int Row;         //Number of rows of the Matrix
        int Col;         //Number of cols of the matrix
};/*end class Matriz*/

//Matriz lambdaTimesIdentity(const double lambda,
//                           const int identitySize);
#endif // MATRIZ_H
