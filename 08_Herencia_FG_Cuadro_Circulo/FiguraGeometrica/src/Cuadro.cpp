#include "../include/Cuadro.h"

Cuadro::Cuadro(double base,double altura):FiguraGeometrica("Cuadro")  //inicializador
{
    Base=base;
    Altura=altura;
}

Cuadro::Cuadro(const Cuadro& other):FiguraGeometrica("Cuadro")  //inicializador
{
    nombreDFigura=other.nombreDFigura;
    Base=other.Base;
    Altura=other.Altura;
}

double Cuadro::area()
{
  return Base*Altura;
}

double Cuadro::sumarArea(FiguraGeometrica* FGPt)
{
    return (area()+FGPt->area());
}


std::ostream& operator<<(std::ostream& out,Cuadro& Cuad)
{
    out<<Cuad.nombreDFigura<<" Base="<<Cuad.Base
       <<" Altura="<<Cuad.Altura<<"\n";
       return out;
}/*end operator<<()*/


