#include <iostream>
#include "main.h"



using namespace std;
struct vectorDInt{
  int N;
  int *intPt;
};

int main()
{
    Calcular C1;
    C1.iniciar();
    C1.entradaDatos();
    C1.salidaDatos();
    Calcular C(10);
    cout<<"C.radio="<<C.radio<<endl;
    cout << "Cantidad de instancias de la clase Calcular: "
         << C1.count<<endl;

    struct vectorDInt V={3,new int[3]};
    struct vectorDInt V1;

    cout<<V.N<<"\n";
    V.intPt[0]=5;
    *(V.intPt+1)=6;
    cout<<V.intPt[0]<<"\n";
    cout<<*V.intPt<<"\n";
    cout<<*(V.intPt+1)<<"\n";
    cout<<"/*************************************/"<<endl;
    V1.N=2;
    V1.intPt=V.intPt;
    cout<<V1.intPt[0]<<"\n";
    cout<<*V1.intPt<<"\n";
    cout<<*(V1.intPt+1)<<"\n";
    V1.intPt[2]=100;
    cout<<V.intPt[2]<<"\n";


    return 0;
}/*end main()*/
