#include <cassert>
#include "Escalar.h"
#include "Polinomio.h"

Polinomio::Polinomio()
{

}

Polinomio::Polinomio(int)
{
    //ctor
}

Polinomio::Polinomio(std::vector<int>& c)
{
    grado=c.size()-1;
    for(unsigned int i=0;i<c.size();i++){
        coef.push_back(c[i]);
    }
}

/** Constructor que crea un Polinomio que es el resultado
 *  de sumar un escalar a un Polinomio. (En este sistema
 *  los escalares son enteros, y los polinomios tienen
 *  coeficientes enteros).
 */
Polinomio::Polinomio(Escalar* EscPt,Polinomio* PolPt)
{
    grado=PolPt->coef.size()-1;
    for(unsigned int i=0;i<PolPt->coef.size();i++){
        coef.push_back(PolPt->coef[i]);
    }
    coef[0]+=EscPt->Value;
}

Polinomio::~Polinomio()
{
    //dtor
}

//Stub
Entrada* Polinomio::Sumar(Escalar* other)
{
    return (Entrada*)other;
}
//Stub
Entrada* Polinomio::Sumar(Polinomio* rhsPol)
{
    return (Entrada*)rhsPol;
}
//Stub
Entrada* Polinomio::Restar(Escalar* other)
{
    return (Entrada*)other;
}
//Stub
Entrada* Polinomio::Restar(Polinomio* rhsPol)
{
    return (Entrada*)rhsPol;
}

std::string Polinomio::to_string()
{
    return typeid(*this).name();
}

std::ostream& operator<<(std::ostream& sal,Polinomio& P)
{
    for(unsigned int i=P.coef.size()-1;i>=0;i--){
      sal<<P.coef[i]<<" ";
    }
    return sal;
}

std::vector<int> Polinomio::get_coef()
{
    return coef;
}

Polinomio& Polinomio::operator=(const Polinomio& other)
{
    if (this == &other) return *this; // handle self assignment
    assert(other.grado==(int)(other.coef.size()-1));
    grado=other.grado;
    for(unsigned int i=0;i<other.coef.size();i++){
        coef.push_back(other.coef[i]);
    }
    return *this;
}

Polinomio Polinomio::operator-()
{
    assert(grado==(int)(coef.size()-1));
    Polinomio R(coef);
    for(unsigned int i=0;i<R.coef.size();i++){
        R.coef[i]=-R.coef[i];
    }
    return R;
}

