/**../CommonFiles/util.cpp
 */
#include <iostream>
#include <vector>
using namespace std;
#define NDEBUG
#include <assert.h>
#include <string.h>  /*strcmp()*/
#include "../CommonFiles/Calendario.h"
#include "../CommonFiles/Fecha.h"
#include "../CommonFiles/Dia.h"
#include <DiaTiempo.h>//add -I<proper directory>
                      //in your make file
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
  for(unsigned int i=0;i<vddc.size();i++){
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
  for(unsigned int i=0;i<v1.size();i++){
    v.push_back(v1[i]);
  }
  for(unsigned int i=0;i<v2.size();i++){
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
  for(unsigned int i=0;i<V.size();i++){
    if(((V[i]->f->F)>=Fi)&&((V[i]->f->F)<=Ff)){
      v.push_back(V[i]);
    }
  }
}

/**Se ``llenan'' los Tiempos Totales Disponibles
   de los d\'ias de clases del Vector de Dias De
   Clases. Los tiempos se toman de los atributos
   time de las instancias de DiaTiempo en el
   vector DT.
*/
void init_tdt(vector<Dia*> VDDC,
              vector<DiaTiempo> DT,
              Calendario *CalYEAR){
 string day = "";
 float time = 0.0;
 /*Se asigna Tiempo Disponible Total segun el dia
   de que se trate*/
 for (unsigned int i = 0; i < VDDC.size(); i++) {
   for(unsigned int j = 0; j < DT.size(); j++){
    day = DT[j].get_dia();
    if(!strcmp(CalYEAR->get_day_name(VDDC[i]->f),day.c_str()))
    {
     time = DT[j].get_time();
     VDDC[i]->set_TDT(time);
    }
   }
 }
}

/**Inicializa el vector de dias VDD.
  pre: VDD debe estar vacio.
*/
void init_vdd(vector<DiaTiempo> dt,vector<string>& VDD){
 string dia = "";
 for(unsigned int i = 0; i < dt.size(); i++){
  dia = dt[i].get_dia();
  VDD.push_back(dia);
 }
}

vector<Dia*> get_VDDC(Calendario *CalYEAR,Fecha f1,Fecha f2,
                      vector<Dia*> vdnl,
                      vector<DiaTiempo> dt){
 /*vector de dias de la semana en que hay clases (te\'{o}ria)
  * de la UA correspondiente*/
 vector<string> vdd;
 init_vdd(dt,vdd);
 /*vector con las Fechas entre f1 y f2 correspondientes a
  los dias en el vector vdd */
 vector<Fecha*> VDF = CalYEAR->get_Fechas(&f1, &f2, vdd);

 /*obtener Vector De Dias de Clase,*/
 vector<Dia*> VDDC = CalYEAR->get_Dias_DC(VDF,vdnl);
 /*Se asigna Tiempo Disponible Total segun el dia
   de que se trate. */
 init_tdt(VDDC,dt,CalYEAR);
 return VDDC;
}

