/**main.cpp
 */
#include <iostream>
using namespace std;
#include <ctime>
#include <DFecha.h>  /*put -I. or whatever necessary at make*/
#include <gettingdate.h>/* -I../source/CommonFiles/ at make */
extern string MES[];
unsigned int primer_lunes_del_mes(unsigned int,unsigned int);
void init_NM(unsigned int);

int main(int argc,char *argv[])
{
  time_t tiempo=time(0);             /** Estas primeras 4 l\'ineas  */
  struct tm *ltm=localtime(&tiempo); /*  son para obtener la fecha  */
  struct Fecha hoy;                  /*  de hoy */
  hoy.d=get_day(ltm);hoy.m=get_month(ltm);hoy.a=get_year(ltm);
  init_NM(hoy.a);
  cout<<"                            "<<get_string_fecha(hoy);
#ifdef LMC1
  cout<<"\nPRIMEROS LUNES DE LOS MESES DE "<<hoy.a<<"\n";
  for(int i=1;i<=12;i++){
    cout<<primer_lunes_del_mes(i,2020)
        <<" de "<<MES[i]<<"\n";
  }
#endif /*LMC1*/
  return 0;
}/*end main()*/


