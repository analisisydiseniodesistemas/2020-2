/**DNombreDia.cpp
 */
#include <iostream>
using namespace std;
#include <stdio.h>  /*sprintf()*/
#include <DFecha.h>

/*Numero magico*/
unsigned int NM[]={0,6,3,2};  /*{*,enero,febrero,marzo}*/
string DIA[]={
  "Lunes","Martes","Miercoles","Jueves","Viernes","Sabado","Domingo"
};
string MES[]={
  "string MES[]","enero","febrero","marzo","abril","mayo","junio",
  "julio","agosto","septiembre","octubre","noviembre","diciembre"
};
string get_string_fecha(struct Fecha F)
{
  char tmp[5];
  string fecha="";
  fecha=fecha+DIA[(F.d+7-NM[F.m])%7];
  fecha=fecha+" ";
  sprintf(tmp,"%d",F.d);
  fecha=fecha+string(tmp);
  fecha=fecha+" de ";
  fecha=fecha+MES[F.m];
  fecha=fecha+" de 2020";
  return fecha;
}

