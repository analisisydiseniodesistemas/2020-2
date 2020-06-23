#include "FiguraGeometrica.h"
#ifndef CIRCULO_H
#define CIRCULO_H


class Circulo : public FiguraGeometrica
{
    public:
        Circulo(double radio);// Constructor
        Circulo(const Circulo& other);      // Constructor de copia
        virtual double area();
    friend  std::ostream& operator<<(std::ostream& out,Circulo& Circ);

    protected:

    private:
        double Radio;
};/*end class Circulo*/

#endif // CIRCULO_H
