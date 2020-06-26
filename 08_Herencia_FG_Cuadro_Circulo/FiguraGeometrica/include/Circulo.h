#include "FiguraGeometrica.h"
#ifndef CIRCULO_H
#define CIRCULO_H


class Circulo : public FiguraGeometrica
{
    public:
        Circulo(double radio);// Constructor
        Circulo(const Circulo& other);      // Constructor de copia
        virtual double area();
        virtual double sumarArea(FiguraGeometrica* FGPt);
    friend  std::ostream& operator<<(std::ostream& out,Circulo& Circ);

    protected:

    private:
        double Radio;
};/*end class Circulo*/

#endif // CIRCULO_H
