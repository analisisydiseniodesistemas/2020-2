#include <iostream>
#include <vector>
#include <iomanip>
#include <typeinfo>
#include <cmath>
#include <assert.h>
#include "../include/Entrada.h"
#include "../include/Escalar.h"
#include "../include/Polinomio.h"
#include "Matriz.h"
#include "../include/xyPol.h"

Matriz::Matriz()
{
    // ctor
}

//Matriz::Matriz(int row,int col,double **dPt)
Matriz::Matriz(int row,int col,Entrada* dPt[ROWS][COLS])
{
    Row=row;
    Col=col;
    //mData=dPt;
    //std::cout<<"Row="<<Row<<"\n";
    //std::cout<<"Col="<<Col<<"\n";
    for(int i=0;i<Row;i++)
        for(int j=0;j<Col;j++)
          mData[i][j]=dPt[i][j];
}

Matriz::~Matriz()
{
    for(int i=0;i<Row;i++){
      for(int j=0;j<Col;j++){
        delete mData[i][j];
      }
    }
}/*end Matriz::~Matriz()*/

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
    for(int i=0;i<Row;i++){
        for(int j=0;j<Col;j++){
            mData[i][j]=new Escalar(0);
        }
    }
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
          if((EscalarPtr!=0)&&(rhsPtr!=0)){// Si ambos son Escalar*
              R.mData[i][j]=EscalarPtr->Sumar((Escalar*)M1.mData[i][j]);
          }else if((EscalarPtr!=0)&&(rhsPolPt!=0)){/* Escalar + Polinomio */
              R.mData[i][j]=EscalarPtr->Sumar((Polinomio*)M1.mData[i][j]);
          }else{ //FALTA Polinomio mas Escalar y Polinomio mas Polinomio 2020.07.20
                 //FIXME!!
              std::cout<<"SUMA de Matrices: ESTO NO DEBE IMPRIMIRSE\n";
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
    for(int i=0;i<Row;i++){
        for(int j=0;j<Col;j++){
          //R.mData[i][j]=mData[i][j]-M1.mData[i][j];
          EntPt=mData[i][j];
          Escalar* EscalarPtr=dynamic_cast<Escalar*>(EntPt);
          Polinomio* PolPtr=dynamic_cast<Polinomio*>(EntPt);
          Escalar* rhsPtr=dynamic_cast<Escalar*>(M1.mData[i][j]);
          Polinomio* rhsPolPt=dynamic_cast<Polinomio*>(M1.mData[i][j]);
          /* Escalar - Escalar */
          if((EscalarPtr!=0)&&(rhsPtr!=0)){// Escalar menos Escalar*
              R.mData[i][j]=EscalarPtr->Restar((Escalar*)M1.mData[i][j]);
          }else if((EscalarPtr!=0)&&(rhsPolPt!=0)){/* Escalar - Polinomio */
              R.mData[i][j]=EscalarPtr->Restar((Polinomio*)M1.mData[i][j]);
          }else if((PolPtr!=0)&&(rhsPtr!=0)){
              R.mData[i][j]=PolPtr->Restar((Escalar*)M1.mData[i][j]);
          }else if((PolPtr!=0)&&(rhsPolPt!=0)){
              R.mData[i][j]=PolPtr->Restar((Polinomio*)M1.mData[i][j]);
          }else{/*Faltan los casos Polinomio - Escalar y Polinomio - Polinomio*/
              std::cout<<"Matriz::operator-(): ESTO NO DEBE IMPRIMIRSE\n";
              R.mData[i][j]=mData[i][j];
          }
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

Matriz Matriz::operator*(const Matriz& M1)
{
    Entrada *EntPt;
    Matriz R(Row,Col);
    assert((Row==M1.Row)&&(Col==M1.Col)&&(Col==M1.Col));
    for(int i=0;i<Row;i++){
        for(int j=0;j<Col;j++){
            for(int z=0;z<Col;z++){
          //R.mData[i][j]=mData[i][j]+M1.mData[i][j];
          EntPt=mData[i][z];
          Escalar* EscalarPtr=dynamic_cast<Escalar*>(EntPt);
          Escalar* rhsPtr=dynamic_cast<Escalar*>(M1.mData[z][j]);
          Polinomio* rhsPolPt=dynamic_cast<Polinomio*>(M1.mData[z][j]);

          Polinomio* PolPt=dynamic_cast<Polinomio*>(EntPt);
          /* Escalar * Escalar */
          if((EscalarPtr!=0)&&(rhsPtr!=0)){// Ambos son Escalar*
                //std::cout<<"\nA i="<<i<<" j="<<j<<": "
                //         <<R.mData[i][j]->to_string()<<" + "
                //         <<EscalarPtr->to_string()
                //         <<"*("<<rhsPtr->to_string()<<")\n";
            R.mData[i][j]=(*R.mData[i][j])+
                (Entrada*)((*EscalarPtr)*((Entrada*)rhsPtr));
          }else if((EscalarPtr!=0)&&(rhsPolPt!=0)){// Son Escalar* y Polinomio*
              //R.mData[i][j]=EscalarPtr->operator*((Polinomio*)M1.mData[i][j]);
                //std::cout<<"\nB i="<<i<<" j="<<j<<": "
                //         <<R.mData[i][j]->to_string()<<" + "
                //         <<EscalarPtr->to_string()
                //         <<"*("<<rhsPolPt->to_string()<<")\n";
            R.mData[i][j]=(*R.mData[i][j])+
                (Entrada*)((*EscalarPtr)*((Entrada*)rhsPolPt));
          }else if((PolPt!=0)&&(rhsPtr!=0)){// Son Polinomio* y Escalar*
              R.mData[i][j]=(*R.mData[i][j])+
                 (Entrada*)((*PolPt)*((Entrada*)rhsPtr));
          }else if((PolPt!=0)&&(rhsPolPt!=0)){// Son Polinomio* y Polinomio*
               R.mData[i][j]=(*R.mData[i][j])+
                  (Entrada*)((*PolPt)*((Entrada*)rhsPolPt));
          }else{
              std::cout<<"ESTO NO DEBE IMPRIMIRSE\n";
              R.mData[i][j]=mData[i][j];
          }
        }//if((i==0)&&(j==0))
           //std::cout<<"i=0,j=0: "<<R.mData[i][j]->to_string()<<"\n";
      }
    }
    return R;
}/*end Matriz::operator*(const Matriz& M1) */

//Entrada* Matriz::determinante(int matriz[][MAX], int orden)
Entrada* Matriz::determinante(Entrada* matriz[][MAX],int orden)
{
   Entrada* det = new Escalar(0);
   Escalar* derEsc=dynamic_cast<Escalar*>(matriz[0][0]);
   Polinomio* derPol=dynamic_cast<Polinomio*>(matriz[0][0]);

   if (orden == 1) {
     if(derEsc!=0){
       det = derEsc;
     }else if(derPol!=0){
       det = derPol;
     }
   } else {
      for (int j = 0; j < orden; j++) {
        Escalar* derivEsc=dynamic_cast<Escalar*>(matriz[0][j]);
        Polinomio* derivPol=dynamic_cast<Polinomio*>(matriz[0][j]);
        Escalar* EscalarPtr=dynamic_cast<Escalar*>(cofactor(matriz, orden, 0, j));
        Polinomio* rhsPtr=dynamic_cast<Polinomio*>(cofactor(matriz, orden, 0, j));
        //det = det + matriz[0][j] * cofactor(matriz, orden, 0, j);
        if((derivEsc!=0)&&(EscalarPtr!=0)){//Escalar por Escalar
            det = (*det) + (Entrada*)((*derivEsc)*((Entrada*)EscalarPtr));
        } else if((derivEsc!=0)&&(rhsPtr!=0)){//Escalar por Polinomio
            det = (*det) + (Entrada*)((*derivEsc)*((Entrada*)rhsPtr));
        } else if((derivPol!=0)&&(EscalarPtr!=0)){//Polinomio por Escalar
            det = (*det) + (Entrada*)((*derivPol)*((Entrada*)EscalarPtr));
        } else if((derivPol!=0)&&(rhsPtr!=0)){//Polinomio por Polinomio
            det = (*det) + (Entrada*)((*derivPol)*((Entrada*)rhsPtr));
        }else{
            std::cout<<"Matriz::determinante(): ESTO NO DEBE IMPRIMIRSE\n";
        }
      }
   }

   return det;
}/*end Matriz::determinante()*/

//int Matriz::cofactor(int matriz[][MAX], int orden, int fila, int columna)
Entrada* Matriz::cofactor(Entrada* matriz[][MAX], int orden, int fila, int columna)
{
   Entrada* EPt=NULL;
   Entrada* submatriz[MAX][MAX];
   int n = orden - 1;

   int x = 0;
   int y = 0;
   for (int i = 0; i < orden; i++) {
      for (int j = 0; j < orden; j++) {
         if (i != fila && j != columna) {
            submatriz[x][y] = matriz[i][j];
            y++;
            if (y >= n) {
               x++;
               y = 0;
            }
         }
      }
   }
   Escalar* factor=new Escalar((int)pow(-1.0, fila + columna));
   Escalar* dEPtr=dynamic_cast<Escalar*>(determinante(submatriz, n));
   Polinomio* DPPtr=dynamic_cast<Polinomio*>(determinante(submatriz, n));
   if(dEPtr){
     EPt=(*factor) * dEPtr;
   }else if(DPPtr){
     EPt=(*factor) * DPPtr;
   }
   return EPt;
}/*end Matriz::cofactor()*/

/** A function friend of class Matriz */
void Get_mData(Matriz& M,Entrada* arr[ROWS][COLS])
{
    //std::cout<<"Starting Get_mData(): ...\n";
    //std::cout<<"M.Row="<<M.Row<<" M.Col="<<M.Col<<"\n";
   for(int i=0;i<M.Row;i++){
    for(int j=0;j<M.Col;j++){
        arr[i][j]=M.mData[i][j];
        //std::cout<<"Get_mData(): "<<arr[i][j]->to_string()<<"\n";
    }
   }
}/*Get_mData()*/

