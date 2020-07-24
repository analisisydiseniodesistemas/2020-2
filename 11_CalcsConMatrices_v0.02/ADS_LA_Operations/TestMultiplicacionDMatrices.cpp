#include <iostream>
#include <typeinfo>/*Información de tipos de dato en tiempo ejecucion*/
#include "./include/Vector.h"
#include "./include/Entrada.h"
#include "./include/Escalar.h"
#include "./include/Polinomio.h"
#include "./include/Matriz.h"
#define SUMA_DE_MATRICES
//#define MULTIPLICACION_DE_MATRICES_A
//#define MULTIPLICACION_DE_MATRICES_B
//#define MULTIPLICACION_DE_MATRICES_C
//#define MULTIPLICACION_DE_MATRICES_D
//#define MULTIPLICACION_DE_MATRICES_E
//#define MULTIPLICACION_DE_MATRICES_F




int main()
{
    std::cout << "CALCULOS con MATRICES" << std::endl;
    Entrada* Mat1[ROWS][COLS]={
      {new Escalar(1),new Escalar(12)},     // 1, 12
      {new Escalar(3),new Escalar(1)}       // 3, 1
    };
    Entrada* Mat2[ROWS][COLS]={
      {new Escalar(4),new Escalar(3)},     // 4, 3
      {new Escalar(2),new Escalar(1)}      // 2, 1
    };
    std::vector<int> cp1;cp1.push_back(0);cp1.push_back(-1);
    std::vector<int> cp2;cp2.push_back(0);cp2.push_back(-1);
    Entrada* Mat3[ROWS][COLS]={
      {new Polinomio(cp1),new Escalar(0)},  // -s,  0
      {new Escalar(0),new Polinomio(cp2)}   //  0, -s
    };
    Entrada* Mat4[ROWS][COLS]={
      {new Polinomio(cp2),new Polinomio(cp2)},
      {new Polinomio(cp1),new Polinomio(cp1)}
    };
    Entrada* Mat5[ROWS][COLS]={
      {new Escalar(0),new Escalar(0)},
      {new Escalar(0),new Escalar(0)}
    };

    Matriz A1(ROWS,COLS,Mat1);   //Matriz de enteros
    Matriz B1(ROWS,COLS,Mat2);   //Matriz de enteros
    Matriz D(ROWS,COLS,Mat3);    //Matriz de polinomios
    Matriz E1(ROWS,COLS,Mat4);    //Matriz de polinomios

    Matriz C=A1+D;              //Matriz de enteros mas matriz de Polinomios
    Get_mData(C,Mat5);     //Passing Mat5 by reference (it's an two dim array)
    Matriz DebeSerC(ROWS,COLS,Mat5);
    Entrada* d=C.determinante(Mat5,ROWS);
    Matriz C1=A1*B1;             //Matriz de enteros por matriz de enteros
    Matriz E=A1*D;               //Matriz de enteros por matriz de polinomios
    Matriz F=B1+E;               //Matriz de enteros mas matriz de polinomios
    Matriz G=D*A1;               //Matriz de polinomios por matriz de enteros
    Matriz H=D*D;                //Matriz de polinomios por matriz de polinomios
    Matriz H1=E1*E1;               //Matriz de polinomios por matriz de polinomios

#ifdef SUMA_DE_MATRICES
    std::cout<<typeid(A1).name()<<" A1\n"<<std::endl;
    std::cout<<A1<<std::endl;
    std::cout<<typeid(D).name()<<" D\n"<<std::endl;
    std::cout<<D<<std::endl;
    std::cout<<typeid(C).name()<<" C=A1+D\n"<<std::endl;
    std::cout<<C<<std::endl;
//    Entrada* det=C.determinante(C.Get_mData(),MAX);
    std::cout<<"DebeSerC = \n";
    std::cout<<DebeSerC<<std::endl;
    std::cout<<"\nImprimir *d = "<<*d<<std::endl;
    Escalar* dPt=dynamic_cast<Escalar*>(d);
    Polinomio* dPPt=dynamic_cast<Polinomio*>(d);
    if(dPt){
        std::cout<<"(Escalar) Determinante = "<<*dPt<<std::endl;
    }else if(dPPt){
        std::cout<<"(Polinomio) Determinante = "<<*dPPt<<std::endl;
    }
#endif // SUMA_DE_MATRICES
#ifdef MULTIPLICACION_DE_MATRICES_A
    std::cout<<"Multiplicaci\'on de matrices de enteros"<<std::endl;
    std::cout<<typeid(C1).name()<<" C1=A1*B1\n"<<std::endl;
    std::cout<<C1<<std::endl;
#endif // MULTIPLICACION_DE_MATRICES_A
#ifdef MULTIPLICACION_DE_MATRICES_B
    std::cout<<typeid(D).name()<<" D\n"<<std::endl;
    std::cout<<D<<std::endl;
    std::cout<<"Matriz de enteros por matriz de polinomios"<<std::endl;
    std::cout<<typeid(E).name()<<" E=A1*D\n"<<std::endl;
    std::cout<<E<<std::endl;
#endif // MULTIPLICACION_DE_MATRICES_B
#ifdef MULTIPLICACION_DE_MATRICES_C
    std::cout<<"Matriz de enteros mas matriz de polinomios"<<std::endl;
    std::cout<<typeid(F).name()<<" F\n"<<std::endl;
    std::cout<<F<<std::endl;
#endif // MULTIPLICACION_DE_MATRICES_C
#ifdef MULTIPLICACION_DE_MATRICES_D
    std::cout<<typeid(D).name()<<" D\n"<<std::endl;
    std::cout<<D<<std::endl;
    std::cout<<typeid(A1).name()<<" A1\n"<<std::endl;
    std::cout<<A1<<std::endl;
    std::cout<<typeid(G).name()<<" G=D*A1\n"<<std::endl;
    std::cout<<G<<std::endl;
#endif // MULTIPLICACION_DE_MATRICES_D
#ifdef MULTIPLICACION_DE_MATRICES_E
    std::cout<<"Matriz de polinomios por matriz de polinomios"<<std::endl;
    std::cout<<typeid(D).name()<<" D\n"<<std::endl;
    std::cout<<D<<std::endl;
    std::cout<<typeid(H).name()<<" H=D*D\n"<<std::endl;
    std::cout<<H<<std::endl;
#endif // MULTIPLICACION_DE_MATRICES_E
#ifdef MULTIPLICACION_DE_MATRICES_F
    std::cout<<"Matriz de polinomios por matriz de polinomios"<<std::endl;
    std::cout<<typeid(E1).name()<<" E1\n"<<std::endl;
    std::cout<<E1<<std::endl;
    std::cout<<typeid(H1).name()<<" H1=E1*E1\n"<<std::endl;
    std::cout<<H1<<std::endl;
#endif // MULTIPLICACION_DE_MATRICES_F
    return 0;
}/*end main()*/
