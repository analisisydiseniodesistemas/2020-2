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

Entrada* Escalar::operator*(Entrada* other)
{
  Entrada* EPt=NULL;
  Escalar* derPt=dynamic_cast<Escalar*>(other);
  Polinomio* derPol=dynamic_cast<Polinomio*>(other);
  if(derPt!=0){/**Se multiplica un escalar por un escalar*/
    int r=Value*derPt->Value;
    EPt=new Escalar(r);
  }else if(derPol!=0){/**Se multiplica un escalar por un polinomio*/
    std::vector<int> cPR;
    std::vector<int> mCoef=derPol->get_coef();
    for(unsigned int i=0;i<mCoef.size();i++)
      cPR.push_back(Value*mCoef[i]);
    EPt=new Polinomio(cPR);
  }
  return (Entrada*)EPt;
}

Entrada* Escalar::operator+(Entrada* other)
{
  Entrada* EPt=NULL;
  Escalar* derPt=dynamic_cast<Escalar*>(other);
  Polinomio* polPt=dynamic_cast<Polinomio*>(other);
  if(derPt!=0){
    int r=Value+derPt->Value;
    EPt=new Escalar(r);
  }else if(polPt!=0){
      std::vector<int> mCoef=polPt->get_coef();
      std::vector<int> cPR;
      for(unsigned int i=0;i<mCoef.size();i++)
        cPR.push_back(mCoef[i]);
      cPR[0]=Value+cPR[0];
      EPt=new Polinomio(cPR);
  }
  return (Entrada*)EPt;
}
