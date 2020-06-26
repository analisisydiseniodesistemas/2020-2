#include "../include/Circulo.h"

Circulo::Circulo(double radio):FiguraGeometrica("Circulo")  //inicializador
{
    Radio=radio;
}

Circulo::Circulo(const Circulo& other):FiguraGeometrica("Circulo")  //inicializador
{
    nombreDFigura=other.nombreDFigura;
    Radio=other.Radio;
}

double Circulo::area()
{
  return 3.1416*Radio*Radio;
}

double Circulo::sumarArea(FiguraGeometrica* FGPt)
{
    return (area()+FGPt->area());
}

std::ostream& operator<<(std::ostream& out,Circulo& Circ)
{
    out<<Circ.nombreDFigura
       <<" Radio="<<Circ.Radio<<"\n";
    return out;
}/*end operator<<()*/


