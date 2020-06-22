#include "FiguraGeometrica.h"

FiguraGeometrica::FiguraGeometrica(std::string FigName)
{
    nombreDFigura=FigName;
}

/*Constructor de copia*/
FiguraGeometrica::FiguraGeometrica(const FiguraGeometrica& other)
{
    nombreDFigura=other.nombreDFigura;
}
