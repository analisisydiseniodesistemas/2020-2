#include <iostream>
#include "./include/Cuadro.h"
#include "./include/Circulo.h"

using namespace std;

int main()
{
    std::cout << "FIGURAS GEOMETRICAS" << endl;
    Cuadro C1(20.0,15.0);
    Circulo S1(10.0);
    std::cout<<C1;
    std::cout<<S1;
    std::cout<<"\n(**************************************)\n";
    FiguraGeometrica *A[2];  /*Arreglo de apuntadores a objeto de clase base*/
    A[0]=&C1;/*Se pueden inicializar con apuntador a objeto de clase derivada*/
    A[1]=&S1;/*Se pueden inicializar con apuntador a objeto de clase derivada*/
    for(int i=0;i<2;i++){/**/
        std::cout<<*A[i]<<": ";/*El método/operaci\'on area() se usa aqu\'i */
        std::cout<<"Area = "<<A[i]->area()<<std::endl;/*polim\'orficamente*/
    }  /*Este ejemplo, muestra el comportamiento polim\'orfico de una operaci\'on*/
    return 0;/*El polimorfismo es una de las caracter\'isticas de la Programaci\'on*/
             /*orientada a objetos (POO), o una caracter\'istica del paradigma de */
             /*orientación a objetos*/
}/*end main()*/
