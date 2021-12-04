/**Test_determinante.cpp*/
#include <iostream>
#include <typeinfo>/*Información de tipos de dato en tiempo ejecucion*/
#include "./include/Vector.h"
#include "./include/Entrada.h"
#include "./include/Escalar.h"
#include "./include/Polinomio.h"
#include "./include/Matriz.h"

int main()
{
#ifdef TEST_1
    std::vector<int> c;c.push_back(1);c.push_back(1);
    Entrada* Mat[ROWS][COLS]={new Polinomio(c)};
    Entrada* Nat[ROWS][COLS]={new Escalar(0)};
    Matriz M((int)ROWS,(int)COLS,Mat);
    Get_mData(M,Nat);
    Matriz N((int)ROWS,(int)COLS,Nat);
    Entrada* d=M.determinante(Nat,1);
#endif // TEST_1
#ifdef TEST_2
    Entrada* Mat1[ROWS][COLS]={
      {new Escalar(1),new Escalar(12)},     // 1, 12
      {new Escalar(3),new Escalar(1)}       // 3,  1
    };
    std::vector<int> cp1;cp1.push_back(0);cp1.push_back(-1);//-s + 0
    std::vector<int> cp2;cp2.push_back(0);cp2.push_back(-1);//-s + 0
    Entrada* Mat3[ROWS][COLS]={
      {new Polinomio(cp1),new Escalar(0)},  // -s,  0
      {new Escalar(0),new Polinomio(cp2)}   //  0, -s
    };
    Entrada* Mat5[ROWS][COLS]={
      {new Escalar(0),new Escalar(0)},
      {new Escalar(0),new Escalar(0)}
    };
    Matriz A1(ROWS,COLS,Mat1);   //Matriz de enteros
    Matriz D(ROWS,COLS,Mat3);    //Matriz de polinomios
    Matriz C=A1+D;         //Matriz de enteros mas matriz de Polinomios
    Get_mData(C,Mat5);     //Passing Mat5 by reference (it's an two dim array)
    Matriz DebeSerC(ROWS,COLS,Mat5);
    Entrada* d=C.determinante(Mat5,ROWS);
#endif // TEST_2

#ifdef TEST_1
    std::cout<<"N ="<<std::endl;
    std::cout<<N<<std::endl;

#endif // TEST_1
#ifdef TEST_2
    std::cout<<typeid(A1).name()<<" A1\n"<<std::endl;
    std::cout<<A1<<std::endl;
    std::cout<<typeid(C).name()<<" C=A1+D\n"<<std::endl;
    std::cout<<C<<std::endl;
    std::cout<<"DebeSerC = \n";
    std::cout<<DebeSerC<<std::endl;
    std::cout<<"det{A1 - s*I} = "<<d->to_string()<<std::endl;
#endif // TEST_2

    Entrada* Mat1[ROWS][COLS]={
      {new Escalar(2),new Escalar(1),new Escalar(3)},     //
      {new Escalar(0),new Escalar(2),new Escalar(-1)},    //
      {new Escalar(0),new Escalar(0),new Escalar(2)}
    };
    std::vector<int> cp1;cp1.push_back(0);cp1.push_back(-1);//-s + 0
    Entrada* Mat2[ROWS][COLS]={
      {new Polinomio(cp1),new Escalar(0),new Escalar(0)},   //
      {new Escalar(0),new Polinomio(cp1),new Escalar(0)},   //
      {new Escalar(0),new Escalar(0),new Polinomio(cp1)}
    };
    Entrada* Mat3[ROWS][COLS]={
      {new Escalar(0),new Escalar(0),new Escalar(0)},  //
      {new Escalar(0),new Escalar(0),new Escalar(0)},  //
      {new Escalar(0),new Escalar(0),new Escalar(0)}
    };
    std::vector<int> cp;cp.push_back(0);cp.push_back(1);// s + 0
    Entrada* Mat4[ROWS][COLS]={
      {new Polinomio(cp),new Escalar(0),new Escalar(0)},   //
      {new Escalar(0),new Polinomio(cp),new Escalar(0)},   //
      {new Escalar(0),new Escalar(0),new Polinomio(cp)}
    };
    Matriz A(ROWS,COLS,Mat1);
    Matriz L(ROWS,COLS,Mat2);
    Matriz LI(ROWS,COLS,Mat4);
    Matriz AmL=A+L;
    Get_mData(AmL,Mat3);
    Entrada* d=AmL.determinante(Mat3,ROWS);
    Matriz AML=A-LI;
    Get_mData(AML,Mat3);
    Entrada* D=AML.determinante(Mat3,ROWS);

    std::cout<<typeid(A).name()<<" A\n"<<std::endl;
    std::cout<<A<<std::endl;
    std::cout<<typeid(AmL).name()<<" AmL=A+L\n"<<std::endl;
    std::cout<<AmL<<std::endl;
    std::cout<<"det{A - s*I} = "<<d->to_string()<<std::endl;
    std::cout<<typeid(AML).name()<<" AML=A-L\n"<<std::endl;
    std::cout<<AML<<std::endl;
    //std::cout<<"det{A - s*I} = "<<D->to_string()<<std::endl;
    Polinomio* polD=dynamic_cast<Polinomio*>(D);
    if(polD)
      std::cout<<"det{A - s*I} = "<<*polD<<std::endl;

    return 0;
}/*end main()*/
