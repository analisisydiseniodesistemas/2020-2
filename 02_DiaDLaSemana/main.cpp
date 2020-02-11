/**main.cpp
 */
#include <iostream>
using namespace std;
#include <ctime>
#include <DFecha.h>  /*put -I. or whatever necessary at make*/
#include <gettingdate.h>/* -I../source/CommonFiles/ at make */
extern string MES[];
unsigned int primer_lunes_del_mes(unsigned int,unsigned int);

int main(int argc,char *argv[])
{
  time_t tiempo=time(0);
  struct tm *ltm=localtime(&tiempo);
  struct Fecha hoy;
  hoy.d=get_day(ltm);hoy.m=get_month(ltm);hoy.a=get_year(ltm);
  cout<<"                            "<<get_string_fecha(hoy);
#ifdef LMC1
  cout<<"\nPRIMEROS LUNES DE LOS MESES DE 2020\n";
  for(int i=1;i<=12;i++){
    cout<<primer_lunes_del_mes(i,2020)
        <<" de "<<MES[i]<<"\n";
  }
#endif /*LMC1*/
  return 0;
}/*end main()*/


