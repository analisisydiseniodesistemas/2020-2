#ifndef MATRIZ_H
#define MATRIZ_H
#include <iostream>
#include "Entrada.h"
#define ROWS    3
#define COLS    3
#define MAX ROWS

class Matriz
{
    public:
        Matriz();
        //Matriz(int row,int col,double **dPt);
        Matriz(int row,int col,Entrada* dPt[ROWS][COLS]);
        Matriz(int row,int col);
        virtual ~Matriz();
        Matriz(const Matriz& other); //Constructor de copia
        Matriz& operator=(const Matriz& other);
        Matriz operator+(const Matriz& M1);
        Matriz operator-(const Matriz& M1);
        Matriz operator*(const Matriz& M1);
    friend std::ostream& operator<<(std::ostream& out,Matriz& rhs);
        Entrada* determinante(Entrada* matriz[][MAX],int orden);
        Entrada* cofactor(Entrada* matriz[][MAX], int orden, int fila, int columna);

//    friend Matriz lambdaTimesIdentity(const double lambda,
//                                      const int identitySize);
    friend void Get_mData(Matriz& M,Entrada* arr[ROWS][COLS]);
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
