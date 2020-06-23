#include "FiguraGeometrica.h"
#ifndef CUADRO_H
#define CUADRO_H

/*Clase derivada, Uso de herencia*/
class Cuadro : public FiguraGeometrica
{
    public:
        Cuadro(double base,double altura);// Constructor
        Cuadro(const Cuadro& other);      // Constructor de copia
        virtual double area();
    friend  std::ostream& operator<<(std::ostream& out,Cuadro& Cuad);

    protected:

    private:
        double Base;
        double Altura;
};/*end class Cuadro*/

#endif // CUADRO_H
