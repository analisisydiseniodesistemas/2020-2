#include "FiguraGeometrica.h"
#ifndef CUADRO_H
#define CUADRO_H


class Cuadro : public FiguraGeometrica
{
    public:
        Cuadro(double base,double altura);// Constructor
        Cuadro(const Cuadro& other);      // Constructor de copia
        virtual double area();

    protected:

    private:
        double Base;
        double Altura;
};/*end class Cuadro*/

#endif // CUADRO_H
