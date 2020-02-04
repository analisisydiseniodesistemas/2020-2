#ifdef VISUAL_STUDIO_2017
#include "stdafx.h"
#endif /*VISUAL_STUDIO_2017*/
#include <iostream>
#include <ostream>
#include <vector>
#include <string>
#define NDEBUG
#include <assert.h>
/*
using std::string;
using std::ostream;
using std::vector;
using std::endl;
*/
using namespace std;
#include "../CommonFiles/Calendario.h"
#include "Fecha.h"
#include "Dia.h"
#include "Asignacion.h"
#include "Calendario.h"         /*2019.10.20*/
extern string ARREGLO[][7];
extern string MONTH[];
//extern char MES[][32];
/** Definition of array MES made after definition of array
 * MES at Calendario.cpp            (thursday 2020.01.30)*/
static char MES[][32]={"static char MES[][32]",
"enero","febrero","marzo","abril","mayo","junio","julio",
"agosto","septiembre","octubre","noviembre","diciembre"
};

#ifdef ADS_PLANNING
static std::string day_place[7][2]={      /*Friday 2020.01.31*/
  {"Lunes","S106"},
  {"Martes","C1"},
  {"Mi\\'ercoles",""},
  {"Jueves","S106"},
  {"Viernes","C1"},
  {"S\\'abado",""},
  {"Domingo",""}
};
static std::string day_horario[7][2]={       /*Friday 2020.01.31*/
  {"Lunes","16:00-17:30"},
  {"Martes","16:00-17:30"},
  {"Mi\\'ercoles",""},
  {"Jueves","16:00-17:30"},
  {"Viernes","16:00-17:30"},
  {"S\\'abado",""},
  {"Domingo",""}
};
#endif /*ADS_PLANNING*/
#ifdef SOTR_PLANNING
static std::string day_place[7][2]={      /*Friday 2020.01.31*/
  {"Lunes",""},
  {"Martes","C8"},
  {"Mi\\'ercoles","C7"},
  {"Jueves",""},
  {"Viernes","C7"},
  {"S\\'abado",""},
  {"Domingo",""}
};
static std::string day_horario[7][2]={       /*Friday 2020.01.31*/
  {"Lunes",""},
  {"Martes","14:30-16:00"},
  {"Mi\\'ercoles","14:30-16:00"},
  {"Jueves",""},
  {"Viernes","14:30-16:00"},
  {"S\\'abado",""},
  {"Domingo",""}
};
#endif /*SOTR_PLANNING*/

/**2019.10.20 If it is necessary, for backward compatibility, 
 * define USING_ARREGLO at command in the make file.
 */ 
ostream& operator<<(ostream& out,Dia& D){
#ifdef USING_ARREGLO   
  out<<ARREGLO[D.f->m][(D.f->d)%7]<<" "<<D.f->d<<" de "
     <<MONTH[D.f->m]<<" de "<<anio<<endl;
#else
  Calendario *Cal_Greg=new Calendario();
#ifndef NDEBUG
//  cout<<__FILE__<<": "<<__LINE__+1<<":";
  printf("%s, line %d:D.f->d=%d, D.f->m=%d, D.f->a=%d\n",
         __FILE__,__LINE__,D.f->d,D.f->m,D.f->a);
  printf("\n%s, line %d, %s\n",__FILE__,__LINE__,Cal_Greg->get_day_name(D.f));
assert((D.f->m>=1)&&(D.f->m<=12));
assert((D.f->d>=1)&&(D.f->d<=31));
#endif /*NDEBUG*/
#ifdef LMC_TEST_20200130_1
  printf("%s %d de %s de %d\n",Cal_Greg->get_day_name(D.f)
                              ,D.f->d
                              ,MES[D.f->m]
                              ,anio);
#endif /*LMC_TEST_20200130_1*/
  out<<Cal_Greg->get_day_name(D.f)
     <<" "<<D.f->d<<" "<<MES[D.f->m]<<" de "<<D.f->a
     <<"\nLugar:"<<D.lugar<<"     Horario:"<<D.horario<<"\n";
  delete Cal_Greg;
#endif /*USING_ARREGLO*/
  for(unsigned int i=0;i<D.A.size();i++){
    out<<*(D.A[i])<<endl;
  }
//assert(1==0);
  return out;
}/*end ostream& operator<<(ostream& out,Dia& D)*/

void Dia::set_TDT(float tdt){
  TD=TDT=tdt;
}

std::string Dia::set_lugar()        /*Friday 2020.01.31*/
{
  Calendario *C=new Calendario(f->a);
  std::string dayName=string(C->get_day_name(f));
  for(int i=0;i<7;i++){
    if(dayName==day_place[i][0]){
      return day_place[i][1];
    }
  }
  return std::string("");
}

std::string Dia::set_horario()        /*Friday 2020.01.31*/
{
  Calendario *C=new Calendario(f->a);
  std::string dayName=string(C->get_day_name(f));
  for(int i=0;i<7;i++){
    if(dayName==day_horario[i][0]){
      return day_horario[i][1];
    }
  }
  return std::string("");
}

