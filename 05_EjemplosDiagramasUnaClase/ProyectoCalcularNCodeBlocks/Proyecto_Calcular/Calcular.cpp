#include <iostream>
#include "main.h"

#define PI  3.141592
using namespace std;

unsigned int Calcular::count=0;

Calcular::Calcular(){
  count++;
}

Calcular::Calcular(double r):radio(r){/*inicializador*/
  //this->radio=radio;
  count++;
}

void Calcular::iniciar(){
  cout<<"PROGRAMA QUE CALCULA AREA Y PERIMETRO DE UNA CIRCUNFERENCIA"<<endl;
}

void Calcular::entradaDatos(){
  cout<<"RADIO = ";
  cin>>radio;
  area=radio*radio*PI;
  perimetro=2*PI*radio;
}

void Calcular::salidaDatos(){
  cout<<"RADIO = "<<radio<<endl;
  cout<<"PERIMETRO = "<<perimetro<<endl;
  cout<<"AREA = "<<area<<endl;
}
