#include "../include/FiguraGeometrica.h"

FiguraGeometrica::FiguraGeometrica(std::string FigName)
{
    nombreDFigura=FigName;
}

/*Constructor de copia*/
FiguraGeometrica::FiguraGeometrica(const FiguraGeometrica& other)
{
    nombreDFigura=other.nombreDFigura;
}

std::ostream& operator<<(std::ostream& out,FiguraGeometrica& FG)
{
    out<<FG.nombreDFigura;
    return out;
}

//double FiguraGeometrica::area()
//{
//    return 0.0;
//}

//double FiguraGeometrica::sumarArea(FiguraGeometrica* FGPt)
//{
//    return 0.0;
//}

