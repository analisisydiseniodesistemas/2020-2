/**../CommonFiles/util.cpp
 */
#include <iostream>
#include <vector>
using namespace std;
#define NDEBUG
#include <assert.h>
#include "../CommonFiles/Calendario.h"
#include "../CommonFiles/Fecha.h"
#include "../CommonFiles/Dia.h"
//extern char MES[][32];    /*turned a comment on thursday 2020.01.30*/  
void   /**Becomed a friend function of class Calendario on 2020.01.30*/
printf_fecha(Fecha *fPt,Calendario *Cal_Greg)
{
    printf("%15s %2d de %s de %4d\n",Cal_Greg->get_day_name(fPt)
                                     ,fPt->d
                                     ,Cal_Greg->MES[fPt->m]
                                     ,fPt->a);
}

void /*show vector dE dIAS con fECHAS*/
show_vector_ddconf(vector<Dia*> vddc) 
{
  Calendario *C=new Calendario(2020);
  for(int i=0;i<vddc.size();i++){
    printf_fecha(vddc[i]->f,C);
    cout<<endl;
  }
}

/** pre:vector v must be empty */
void 
cat_vddc(vector<Dia*>& v1,vector<Dia*>& v2,vector<Dia*>& v)
{
#ifndef NDEBUG
  cout<<"v1: "<<v1.size()<<"\nv2: "<<v2.size()<<"\n";
#endif
  for(int i=0;i<v1.size();i++){
    v.push_back(v1[i]);
  }
  for(int i=0;i<v2.size();i++){
    v.push_back(v2[i]);
  }
#ifndef NDEBUG
  cout<<"v: "<<v.size()<<"\n";
#endif
}

/**
 * pre: vector<Dia*> v must be empty.
 */ 
void
fill_vector_v(vector<Dia*>&V,vector<Dia*>&v,int Fi,int Ff)
{
  for(int i=0;i<V.size();i++){
    if(((V[i]->f->F)>=Fi)&&((V[i]->f->F)<=Ff)){
      v.push_back(V[i]);
    }
  }
}

