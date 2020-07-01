#include <iostream>
#include "Entrada.h"

Entrada::Entrada()
{
    //ctor
}

Entrada::~Entrada()
{
    //dtor
}

Entrada::Entrada(std::string nameOfEntry)
{
    nombreDEntrada=nameOfEntry;
}

Entrada* Entrada::operator*(Entrada* other)
{
    return other;/*REVISAR QUE ESTA FUNCION EN REALIDAD NO SE USE*/
                 /*Y QUE EN SU LUGAR SE UTILICE LA FUNCION */
                 /*Escalar::operator*(Escalar*) O BIEN LA FUNCION*/
                 /*Escalar::operator*(PolOrderOne*) */
                 /*PARA ELLO, ESTA FUNCION SE DECLARO COMO virtual*/
}/*end Entrada::operator*()*/

/*THIS IS A VIRTUAL METHOD OF Entrada CLASS*/
Entrada* Entrada::operator+(Entrada* other)
{
    return other;
}
/*THIS IS A VIRTUAL METHOD OF Entrada CLASS*/
//Entrada* Entrada::Sumar(Escalar* other)
//{
//    return (Entrada*)other;
//}
/*THIS IS A VIRTUAL METHOD OF Entrada CLASS*/
//Entrada* Entrada::Sumar(Entrada* other)
//{
//    return other;
//}

//Entrada* Entrada::Restar(Escalar* other)
//{
//    return (Entrada*)other;
//}
/*THIS IS A VIRTUAL METHOD OF Entrada CLASS*/
//Entrada* Entrada::Restar(Entrada* other)
//{
//    return other;
//}

/*THIS IS A VIRTUAL METHOD OF Entrada CLASS*/
Entrada* Entrada::operator-(Entrada* other)
{
    return other;
}

std::ostream& operator<<(std::ostream& out,Entrada& rhs)
{
    out<<rhs.nombreDEntrada;
    return out;
}
