/**TestFecha.cpp - driver to test overloading of operator > */
#include <iostream>
#include <vector>
using namespace std;
#include <stdio.h>   /*printf() et al*/
#include <ctime>
#include <Calendario.h> /*Add -I../CommonFiles/ in your make file*/
#include <Fecha.h>      /*Add -I../CommonFiles/ in your make file*/
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
  
  return 0xa;
}/*end main()*/

