#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include <iostream>

class FiguraGeometrica
{
    protected:
      std::string nombreDFigura;
    public:
        FiguraGeometrica(std::string FigName);
        FiguraGeometrica(const FiguraGeometrica& other);
        virtual double area()=0;   //un metodo virtual puro ( = 0 ) => la clase es abstracta
                                   //No se puede instanciar objetos de una clase abstracta.
};/*end class FiguraGeometrica*/

#endif // FIGURAGEOMETRICA_H
