#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include "./include/Cuadro.h"
#include "./include/Circulo.h"

using namespace std;
/*
Ok, Ud. Axel Yaxel Flores de la Rosa, ustilizará la función x^{2}
Ok Camila Lopez Vega trabajará con la función f(x)=1/x
Efren Alejandro Mendoza trabajará con la función f(x)=2x
Jesus E. Fragoso trabajará con la función f(x)=x^{3}
Uri Yael Alvarez Lopez trabajará con la función f(x)=raíz de x.
Owen Nathaniel Gutierrez trabajará con la función f(x)=x^{-3}
Erick Leonel Cedillo CRuz trabajará con la función f(x)=4x^{-2}
Carlos Flores Ramirez trabajará con la función f(x)=log(x)
Alexis Gonzalez San Juan trabajará con la función f(x)=|x|
*/
/**
 * @param a:l\'imite inferior de integraci\'on
 * @param b:l\imite superior de integraci\'on
 * @param n:cantidad de rectangulos a utilizar para
 *          calcular la integral de la funci\'on
 */
double integracionRectangulo(double a,double b,int n);
int main()
{
    std::cout << "FIGURAS GEOMETRICAS" << endl;
    Cuadro C1(20.0,15.0);
    Circulo S1(10.0);
    //FiguraGeometrica *fgPt=new FiguraGeometrica("Alguna Figura");
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
    //std::cout<<A[0]->sumarArea(fgPt)<<std::endl;
    std::cout<<A[0]->sumarArea(&C1)<<std::endl;
    std::cout<<A[0]->sumarArea(&S1)<<std::endl;
    std::cout<<A[1]->sumarArea(&C1)<<std::endl;
    double Superficie=integracionRectangulo(0.0,3.0,20);
    std::cout<<std::fixed<<std::setw(15)<<Superficie
             <<std::fixed<<std::setw(15)<<Superficie<<"\n";
    std::cout.precision(2);
    std::cout<<std::fixed<<std::setw(15)<<Superficie
             <<std::fixed<<std::setw(15)<<Superficie<<"\n";
    double funTable[10][2];  /*Tabla de la función */
    double Delta=0.1;
double f(double);
    for(int i=0;i<10;i++){
        funTable[i][0]=Delta*((double)i);
        funTable[i][1]=f(Delta*((double)i));
    }
    std::cout.precision(2);
    for(int i=0;i<10;i++){
        std::cout<<std::fixed<<std::setw(10)
                 <<funTable[i][0];
        std::cout<<std::fixed<<std::setw(10)
                 <<funTable[i][1]<<std::endl;
    }
    std::cout<<std::endl;
    std::vector<Cuadro*> vrec;  /*vector de apuntadores a objetos */
                                /* de la clase Cuadro */
    double base=0.1;
    double altura[3]={2.3,1,1,5.9};
    vrec.push_back(new Cuadro(base,altura[0]));
    vrec.push_back(new Cuadro(base,altura[1]));
    vrec.push_back(new Cuadro(base,altura[2]));

    return 0;/*El polimorfismo es una de las caracter\'isticas de la Programaci\'on*/
             /*orientada a objetos (POO), o una caracter\'istica del paradigma de */
             /*orientación a objetos*/
}/*end main()*/

/**
 * @param n: la cantidad de rectangulos a utiliar
   pre: n<200
 */
double integracionRectangulo(double a,double b,int n)
{
    std::vector<Cuadro*> vec_Cuadro;
    double sup=0.0;
    //ESCRIBA SU CODIGO AQUI
    for(unsigned int i=0;i<vec_Cuadro.size();i++){//Cálculo de la integral
        sup+=vec_Cuadro[i]->area();
    }
    return sup;
}/*end integracionRectangulo()*/


double f(double x)
{
    return 0.0;
}
