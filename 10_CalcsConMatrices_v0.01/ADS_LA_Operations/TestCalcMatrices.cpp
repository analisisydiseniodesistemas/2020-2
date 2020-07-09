#include <iostream>
#include <typeinfo>/*Información de tipos de dato en tiempo ejecucion*/
#include "./include/Vector.h"
#include "./include/Entrada.h"
#include "./include/Escalar.h"
#include "./include/Polinomio.h"
#include "./include/Matriz.h"

using namespace std;
//double **a;

Entrada* MatofOnes[ROWS][COLS]={
  {new Escalar(1),new Escalar(1),new Escalar(1),new Escalar(1)},
  {new Escalar(1),new Escalar(1),new Escalar(1),new Escalar(1)},
  {new Escalar(1),new Escalar(1),new Escalar(1),new Escalar(1)},
  {new Escalar(1),new Escalar(1),new Escalar(1),new Escalar(1)}
};
Entrada* arr[4][4]={
{new Escalar(1),new Escalar(2),new Escalar(3),new Escalar(6)},
{new Escalar(3),new Escalar(6),new Escalar(9),new Escalar(18)},
{new Escalar(5),new Escalar(10),new Escalar(15),new Escalar(30)},
{new Escalar(7),new Escalar(14),new Escalar(21),new Escalar(42)}
};
//double Lambda[]={0.0,64.0,0.000000000000002605,-0.000000000000001990};
int main()
{
    std::cout << "CALCULOS con MATRICES" << std::endl;
    Polinomio* Ppt=new Polinomio(0);
    Escalar* Ept=new Escalar(0);
    std::cout<<typeid(*Ept).name()<<std::endl;
    std::cout<<Ppt->to_string()<<std::endl;
vector<int> lambda;
lambda.push_back(0);
lambda.push_back(1);   /*lambda representa el polinomio s+0*/
Entrada* PreLamdaI[ROWS][COLS]={
  {new Polinomio(lambda),new Escalar(0),new Escalar(0),new Escalar(0)},
  {new Escalar(0),new Polinomio(lambda),new Escalar(0),new Escalar(0)},
  {new Escalar(0),new Escalar(0),new Polinomio(lambda),new Escalar(0)},
  {new Escalar(0),new Escalar(0),new Escalar(0),new Polinomio(lambda)}
};

    Matriz A(ROWS,COLS,MatofOnes);
    //Matriz B(ROWS,COLS,PreLamdaI);
    Matriz F(ROWS,COLS,arr);
//    Matriz L(ROWS,COLS,PreLamdaI);
    Matriz C=A+B;
    //Matriz D=A-B;
    Matriz E=A*F;
    std::cout<<E<<std::endl;
//    std::cout<<typeid(L).name()<<" L"<<std::endl;
//    std::cout<<L<<std::endl;
    std::cout<<typeid(A).name()<<" A"<<std::endl;
    std::cout<<A<<std::endl;
    std::cout<<typeid(B).name()<<" B"<<std::endl;
    std::cout<<B<<std::endl;
    std::cout<<typeid(C).name()<<" C=A+B"<<std::endl;
    std::cout<<C<<std::endl;
    //std::cout<<typeid(D).name()<<" D=A-B"<<std::endl;
    //std::cout<<D<<std::endl;

    //Matriz lambdaI=lambdaTimesIdentity(0.0,4);
    //std::cout<<lambdaI<<std::endl;
    //Matriz AminusLambdaI=A-lambdaI;
    //std::cout<<AminusLambdaI;
    A.~Matriz();
    B.~Matriz();
    C.~Matriz();
//    D.~Matriz();
    //lambdaI.~Matriz();
    //AminusLambdaI.~Matriz();
    return 0;
}/*end main()*/

