/**TestFecha.cpp - driver to test overloading of operator > */
#include <iostream>
#include <vector>
using namespace std;
#include <stdio.h>   /*printf() et al*/
#include <ctime>
#include <Calendario.h> /*Add -I../CommonFiles/ in your make file*/
#include <Fecha.h>      /*Add -I../CommonFiles/ in your make file*/
#include <Dia.h>        /*Add -I../CommonFiles/ in your make file*/
#include <gettingdate.h>/*Add -I../CommonFiles/ in your make file*/

/**The next lines are included by now, in order to fix a compilation
 * error in file ../CommonFiles/Calendario.cpp.       2020.01.28*/
Calendario *Cal_Greg;
int anio=2020;
char MES[][32]={"static char MES[][32]",
	"enero","febrero","marzo","abril","mayo","junio","julio",
	"agosto","septiembre","octubre","noviembre","diciembre"
};
/** **********************************************************      */

int
main(int argc,char *argv[])
{
  /**The next line is include by now, in order to fix a compilation
   * error in file ../CommonFiles/Calendario.cpp.       2020.01.28*/
  Cal_Greg=new Calendario(2020);    /*Calendario Gregoriano*/
  time_t tiempo=time(0);
  struct tm *ltm=localtime(&tiempo);
  struct Fecha hoy(get_day(ltm),get_month(ltm),get_year(ltm));
  struct Fecha JKalend(1,1,2020);        /*January Kalend of 2020*/
  printf_fecha(&hoy,new Calendario(2020));
  printf_fecha(&JKalend,new Calendario(2020));
  if(hoy>JKalend){
    cout<<":-)\n"; 
  }else{
    cout<<":-(\n";
  }
  if(JKalend>hoy){
    cout<<":-(\n"; 
  }else{
    cout<<":-)\n";
  }
//  vector<Dia*> VDDC = Cal_Greg->get_Dias_DC(VDF,vdnl); 
//  Fix this -----------^ (We could fill vector VDDC using push_back method
//  and pointers to Dia propperly initialized with Fecha objects/Fecha 
//  pointers)
  Fecha fLunes27ENE(27,1,2020),fJueves30ENE(30,1,2020),
        fLunes03FEB(3,2,2020),fJueves06FEB(6,2,2020),
        fMartes28ENE(28,1,2020),fViernes31ENE(31,1,2020),
        fMartes04FEB(4,2,2020),fViernes07FEB(7,2,2020);
  vector<Dia*> VDDC,vddc,v;
  VDDC.push_back(new Dia(&fLunes27ENE));
  VDDC.push_back(new Dia(&fJueves30ENE));
  VDDC.push_back(new Dia(&fLunes03FEB));
  VDDC.push_back(new Dia(&fJueves06FEB));
  vddc.push_back(new Dia(&fMartes28ENE));
  vddc.push_back(new Dia(&fViernes31ENE));
  vddc.push_back(new Dia(&fMartes04FEB));
  vddc.push_back(new Dia(&fViernes07FEB));
  cat_vddc(VDDC,vddc,v);
  show_vector_ddconf(v);
  ordenar_ddc(v);
  cout<<"Despu\\'es de ordenar los d\\'ias por su fecha."<<"\n";
  show_vector_ddconf(v);
  
  return 0xa;
}/*end main()*/

