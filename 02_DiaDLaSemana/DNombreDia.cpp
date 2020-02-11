/**DNombreDia.cpp
 */
#include <iostream>
#include <vector>
using namespace std;
#include <stdio.h>  /*sprintf()*/
#include <DFecha.h> /*Add -I./ or whatever necessary at make*/ 
#include <Calendario.h>/*Add -I./whatever/necessary/ at make*/
                  /* also add -DUSAR_STRING at make*/
/*Numero magico*/
unsigned int NM[]={0,6,3,2};  /*{*,enero,febrero,marzo}*/
string DIA[]={
  "Lunes","Martes","Miercoles","Jueves","Viernes","Sabado","Domingo"
};
string MES[]={
  "string MES[]","enero","febrero","marzo","abril","mayo","junio",
  "julio","agosto","septiembre","octubre","noviembre","diciembre"
};

static vector<string> dias_del_mes;

/** devuelve el n\'{u}mero de d\'{i}a del mes
 * correspondiente al primer lunes del mes
 * numDMes del a\~{n}o year.
 */
unsigned int 
primer_lunes_del_mes(unsigned int numDMes,
                     unsigned int year)
{
  Calendario *C=new Calendario(year);
  Fecha f;f.d=1;f.m=numDMes;f.a=year;
  dias_del_mes.clear();
  dias_del_mes.push_back("dias_del_mes"); /*dummy entry*/
  for(char i=1;i<=7;i++){
    dias_del_mes.push_back(C->get_day_name(&f));
    f.d++;
  }
  for(char i=1;i<=7;i++){
    if("Lunes"==dias_del_mes[i])
      return (unsigned int)i;
  }
  return 0;
}

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

