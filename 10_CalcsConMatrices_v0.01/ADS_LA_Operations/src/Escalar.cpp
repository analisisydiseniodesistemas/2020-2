#include <stdio.h>
#include "Escalar.h"
#include "Polinomio.h"

Escalar::Escalar():Entrada("Esc0")
{

}

Escalar::Escalar(T val):Entrada("Esc")
{
    Value=val;
}

Escalar::~Escalar()
{
    //dtor
}

Escalar* Escalar::operator*(Escalar* other)
{
    Escalar* EPt=new Escalar();
    EPt->Value=Value*other->Value;
    return EPt;
}

//Entrada* Escalar::Sumar(Entrada* other)
//{
//    return (Entrada*)(new Escalar(Value+other->Value));
//}

Entrada* Escalar::Sumar(Escalar* other)
{
    return (Entrada*)(new Escalar(Value+other->Value));
}

Entrada* Escalar::Sumar(Polinomio* rhsPol)
{
    return (Entrada*)(new Polinomio(this,rhsPol));
}

Entrada* Escalar::Restar(Escalar* other)
{
    return (Entrada*)(new Escalar(Value-other->Value));
}

/**Hace la operaci\'on Escalar menos Polinomio.
 * El polinomio se pasa con un apuntador.
 */
Entrada* Escalar::Restar(Polinomio* rhsPol)
{
    Polinomio *minusPol=new Polinomio();
    *minusPol=-(*rhsPol);
    return (Entrada*)(new Polinomio(this,minusPol));
}

std::string Escalar::to_string()
{
    char cad[32];
    sprintf(cad,"%d",Value);
    std::string str=std::string(cad);
    return str;
}
