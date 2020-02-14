#include <iostream>
using namespace std;
#include <ctime>
#include <DFecha.h>  /*put -I. or whatever necessary at make*/
#include <gettingdate.h>/* -I../source/CommonFiles/ at make */
void init_NM(unsigned int);
string get_kalend(unsigned int,unsigned int);
void init_cdd(string);
void print_cdd();

int main(int argc,char *argv[])
{
  time_t tiempo=time(0);             /** Estas primeras 4 l\'ineas  */
  struct tm *ltm=localtime(&tiempo); /*  son para obtener la fecha  */
  struct Fecha hoy;                  /*  de hoy */
  hoy.d=get_day(ltm);hoy.m=get_month(ltm);hoy.a=get_year(ltm);

  string kalend;
#ifdef TEST_INICIAL
  init_NM(hoy.a);
#ifndef NDEBUG
  cout<<"hoy.m="<<hoy.m<<" hoy.a="<<hoy.a<<"\n";
#endif
  kalend=get_kalend(hoy.m,hoy.a);
#ifndef NDEBUG
  cout<<"kalend="<<kalend<<"\n";
#endif
  init_cdd(kalend);
  cout<<"                                "<<get_string_fecha(hoy)
      <<"\n";
  print_cdd();
#else
  kalend=get_kalend(1,hoy.a);     /*ENERO*/
  init_cdd(kalend);
  cout<<"\nENERO, "<<hoy.a<<"\n";
  print_cdd();

  kalend=get_kalend(2,hoy.a);     /*FEBRERO*/
  init_cdd(kalend);
  cout<<"\nFEBRERO, "<<hoy.a<<"\n";
  print_cdd();

  kalend=get_kalend(3,hoy.a);     /*MARZO*/
  init_cdd(kalend);
  cout<<"\nMARZO, "<<hoy.a<<"\n";
  print_cdd();
#endif /*TEST_INICIAL*/

  return 0;
}/*end main()*/

