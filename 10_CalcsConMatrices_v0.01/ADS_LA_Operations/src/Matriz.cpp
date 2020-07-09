#include <iostream>
#include <vector>
#include <iomanip>
#include <typeinfo>
#include <assert.h>
#include "../include/Entrada.h"
#include "../include/Escalar.h"
#include "../include/Polinomio.h"
#include "Matriz.h"
#include "../include/xyPol.h"

//Matriz::Matriz(int row,int col,double **dPt)
Matriz::Matriz(int row,int col,Entrada* dPt[ROWS][COLS])
{
    Row=row;
    Col=col;
    //mData=dPt;
    for(int i=0;i<ROWS;i++)
        for(int j=0;j<COLS;j++)
          mData[i][j]=dPt[i][j];
}

Matriz::~Matriz()
{
    //delete[] mData;
}

Matriz::Matriz(const Matriz& other)
{
    //copy ctor
}

Matriz& Matriz::operator=(const Matriz& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    //return *this;
    assert((Row==rhs.Row)&&(Col==rhs.Col));
    for(int i=0;i<Row;i++)
        for(int j=0;j<Col;j++)
          mData[i][j]=rhs.mData[i][j];
    return *this;
}

Matriz::Matriz(int row,int col)
{
    Row=row;
    Col=col;
}

Matriz Matriz::operator+(const Matriz& M1)
{
    Entrada *EntPt;
    Matriz R(Row,Col);
    assert((Row==M1.Row)&&(Col==M1.Col));
    for(int i=0;i<Row;i++)
        for(int j=0;j<Col;j++){
          //R.mData[i][j]=mData[i][j]+M1.mData[i][j];
          EntPt=mData[i][j];
          Escalar* EscalarPtr=dynamic_cast<Escalar*>(EntPt);
          Escalar* rhsPtr=dynamic_cast<Escalar*>(M1.mData[i][j]);
          Polinomio* rhsPolPt=dynamic_cast<Polinomio*>(M1.mData[i][j]);
          /* Escalar + Escalar */
          if((EscalarPtr!=0)&&(rhsPtr!=0)){// Ambos 0 si no son Escalar*
              R.mData[i][j]=EscalarPtr->Sumar((Escalar*)M1.mData[i][j]);
          }else if((EscalarPtr!=0)&&(rhsPolPt!=0)){/* Escalar + Polinomio */
              R.mData[i][j]=EscalarPtr->Sumar((Polinomio*)M1.mData[i][j]);
          }else{
              R.mData[i][j]=mData[i][j];
          }
        }
    return R;
}/*end Matriz::operator+()*/

Matriz Matriz::operator-(const Matriz& M1)
{
    Matriz R(Row,Col);
    Entrada* EntPt;
    assert((Row==M1.Row)&&(Col==M1.Col));
    for(int i=0;i<Row;i++)
        for(int j=0;j<Col;j++){
          //R.mData[i][j]=mData[i][j]-M1.mData[i][j];
          EntPt=mData[i][j];
          Escalar* EscalarPtr=dynamic_cast<Escalar*>(EntPt);
          Escalar* rhsPtr=dynamic_cast<Escalar*>(M1.mData[i][j]);
          Polinomio* rhsPolPt=dynamic_cast<Polinomio*>(M1.mData[i][j]);
          /* Escalar + Escalar */
          if((EscalarPtr!=0)&&(rhsPtr!=0)){// Ambos 0 si no son Escalar*
              R.mData[i][j]=EscalarPtr->Restar((Escalar*)M1.mData[i][j]);
          }else if((EscalarPtr!=0)&&(rhsPolPt!=0)){/* Escalar - Polinomio */
              R.mData[i][j]=EscalarPtr->Restar((Polinomio*)M1.mData[i][j]);
          }else{
              R.mData[i][j]=mData[i][j];
          }
        }
    return R;
}/*end Matriz::operator-()*/

//Matriz lambdaTimesIdentity(const double lambda,const int identitySize)
//{
//    double **a=new double*[identitySize];
//    for(int i=0;i<identitySize;i++)
//        a[i]=new double[identitySize];
//    Matriz R(identitySize,identitySize,a);
//    for(int i=0;i<R.Row;i++){
//        for(int j=0;j<R.Col;j++)
//          if(i==j){
//                R.mData[i][j]=lambda;
//          }else{
//              R.mData[i][j]=0.0;
//          }
//    }
//    return R;
//}/*end lambdaTimesIdentity()*/


std::ostream& operator<<(std::ostream& out,Matriz& rhs)
{

    std::vector<xyPol> v;
    out.precision(2);
    for(int i=0;i<rhs.Row;i++){
      for(int j=0;j<rhs.Col;j++){
          //out<<std::fixed<<std::setw(9)<<*(rhs.mData[i][j]);
         Escalar* EscPtr=dynamic_cast<Escalar*>(rhs.mData[i][j]);
         Polinomio* polPt=dynamic_cast<Polinomio*>(rhs.mData[i][j]);
         if(EscPtr){
          out<<std::fixed<<std::setw(9)
             <<rhs.mData[i][j]->to_string();
         }else{
          v.push_back(xyPol(i+1,j+1,polPt->get_coef()));
          out<<std::fixed<<std::setw(4)
             <<"X["<<i+1<<"]["<<j+1<<"]";
         }
      }
        out<<std::endl;
    }
    out<<std::endl;
    for(unsigned int i=0;i<v.size();i++){
        out<<v[i]<<"\n";
    }
    return out;
}/*end operator<<()*/

Matriz Matriz::operator*(Matriz other)
{
   //ESCRIBA SU CODIGO AQUI
}
