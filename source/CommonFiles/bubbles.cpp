/**bubles.cpp*/
#include <vector>
#include <string>
using namespace std;
#include <Calendario.h>/*Add -I../CommonFiles in your make file*/
#include <Fecha.h>     /*Add -I../CommonFiles in your make file*/
#include <Dia.h>       /*Add -I../CommonFiles in your make file*/

void
ordenar_ddc(vector<Dia*>& vddc){
  Dia *dtmp;
  for(int j=vddc.size()-1;j>0;j--){
    for(int i=1;i<=j;i++){
      if(*(vddc[i-1]->f)>*(vddc[i]->f)){
        dtmp=vddc[i];
        vddc[i]=vddc[i-1];
        vddc[i-1]=dtmp;
      }
    }
  }
}

