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
    char cad[32];
    std::string str="";
    int a=(int)(coef.size()-1);
    for(unsigned int i=0;i<coef.size();i++){
      sprintf(cad,"%d  ",coef[a-i]);
      str=str+std::string(cad);
    }
    return str;
}

std::ostream& operator<<(std::ostream& sal,Polinomio& P)
{
    int a=P.coef.size()-1;
    for(unsigned int i=0;i<P.coef.size();i++){
      sal<<P.coef[a-i]<<"  ";
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


Entrada* Polinomio::operator*(Entrada* other)
{
    Entrada* EPt=NULL;
    Escalar* derPt=dynamic_cast<Escalar*>(other);
    Polinomio* derPolPt=dynamic_cast<Polinomio*>(other);
    int graDPolR;              // Grado De Polinomio Resultado
    std::vector<int> cPR;
    if(derPt!=0){              // Polinomio por Escalar
        for(unsigned int i=0;i<coef.size();i++)
          cPR.push_back(derPt->Value*coef[i]);
        EPt=new Polinomio(cPR);
    }else if(derPolPt!=0){   // Polinomio por Polinomio
        graDPolR=coef.size()+derPolPt->coef.size()-2;  // size1 - 1+size2 -1
        for(int i=0;i<=graDPolR;i++){
            cPR.push_back(0);
        }
        for(unsigned int i=0;i<coef.size();i++){
            for(unsigned int j=0;j<derPolPt->coef.size();j++){
                cPR[i+j]+=coef[i]*derPolPt->coef[j];
            }
        }
        EPt=new Polinomio(cPR);
    }
  return (Entrada*)EPt;
}/*end Polinomio::operator*()*/

#define max(a,b)    (((a)>(b))?(a):(b))
Entrada* Polinomio::operator+(Entrada* other)
{
    Entrada* EPt=NULL;
    Escalar* derPt=dynamic_cast<Escalar*>(other);
    Polinomio* polPt=dynamic_cast<Polinomio*>(other);
    int resultsize;
    std::vector<int> resultcoef;
    if(derPt!=0){          //Se suma Polinomio mas Escalar
      std::vector<int> cPR;
      for(unsigned int i=0;i<coef.size();i++)
        cPR.push_back(coef[i]);
      cPR[0]=derPt->Value+cPR[0];
      EPt=new Polinomio(cPR);
    }else if(polPt!=0){   //Se suma Polinomio mas Polinomio
      resultsize=max(coef.size(),polPt->coef.size());
      if(coef.size()==polPt->coef.size()){/*resultsize=coef.size()=polPt->coef.size()*/
        for(int i=0;i<resultsize;i++){
          resultcoef.push_back(coef[i]+polPt->coef[i]);
        }
      }else if(coef.size()>polPt->coef.size()){/*resultsize=coef.size()*/
          for(unsigned int i=0;i<coef.size();i++){
            resultcoef.push_back(coef[i]);
          }
          for(unsigned int i=0;i<polPt->coef.size();i++){
            resultcoef[i]+=polPt->coef[i];
          }
      }else{/*resultsize=polPt->coef.size()*/
          for(unsigned int i=0;i<polPt->coef.size();i++){
            resultcoef.push_back(polPt->coef[i]);
          }
          for(unsigned int i=0;i<coef.size();i++){
            resultcoef[i]+=coef[i];
          }
      }
      EPt=new Polinomio(resultcoef);
    }
    return EPt;
}/*end Polinomio::operator+()*/

