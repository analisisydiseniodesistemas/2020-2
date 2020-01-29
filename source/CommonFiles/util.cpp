/**../CommonFiles/util.cpp
 */
#include <iostream>
#include <vector>
using namespace std;
#include "../CommonFiles/Calendario.h"
#include "../CommonFiles/Fecha.h"
#include "../CommonFiles/Dia.h"
extern char MES[][32];
void
printf_fecha(Fecha *fPt,Calendario *Cal_Greg)
{
    //printf("%15s %2d de %7s de %4d\n",Cal_Greg->get_day_name(fPt)
    printf("%15s %2d de %s de %4d\n",Cal_Greg->get_day_name(fPt)
                                     ,fPt->d
                                     ,MES[fPt->m]
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
  for(int i=0;i<v1.size();i++){
    v.push_back(v1[i]);
  }
  for(int i=0;i<v2.size();i++){
    v.push_back(v2[i]);
  }
}

