/** sotr_using_Calendario.cpp - Driver program used to test classes
 *  Calendario, Fecha, Dia, Actividad, Asignacion.
 *  Learning Real Time Operating System
 *  planning for the semester August - December, 2020.
 *  (semester will be finished by january, 2021).
 */
#include <iostream>
#include <vector>
using namespace std;
#include <stdio.h>
#include <string.h>  /*strcmp()*/
#define NDEBUG
#include <assert.h>
#include "../CommonFiles/Calendario.h"
#include "../CommonFiles/Fecha.h"
#include "../CommonFiles/Dia.h"
#include "../CommonFiles/Actividad.h"
#include "../CommonFiles/Asignacion.h"
#if 0 //LMC 2021.08.30
#include "../CommonFiles/AdA.h"
#endif // 0
#include <util.h>


int main(int argc,char *argv[])
{
  Calendario *Cal2021 = new Calendario(2021);
  Fecha f1(1,1,2021); /*Viernes 1 de enero de 2021*/
  Fecha f2(23,1,2021); /*S\'abado 23 de enero de 2021*/

  /*vector de dias de la semana en que hay clases (te\'{o}ria) de la
   * UA correspondiente*/
  vector<string> vdd;
  /*Se indican los d\'ias de la semana que hay clases de SOTR*/
  vdd.push_back("Martes");
  vdd.push_back("Mi\\'ercoles");
  vdd.push_back("Viernes");
  /*vector con las Fechas entre f1 y f2 correspondientes a
   los dias en el vector vdd */
  vector<Fecha*> VDF = Cal2021->get_Fechas(&f1, &f2, vdd);
  /*construir un vector de apuntadores a Dias no laborables*/
  vector<Dia*> vdnl;
  vdnl.push_back(new Dia(new Fecha(1,1,2021)));   /*Viernes 1 de enero de 2021*/
/*Ahora usando el vector de Fechas VDF y el vector de Dias no
 laborables vdnl, construir un vector de Dias laborables (los dias de
 clase para los que se planificar\'an actividades) este vector de Dias
 laborables se obtendr\'a pasando un mensaje al objeto de clase
 Calendario*/
  /*obtener Vector De Dias de Clase,*/
  vector<Dia*> VDDC = Cal2021->get_Dias_DC(VDF,vdnl);
  /*Se asigna Tiempo Disponible Total segun el dia de que se trate*/
  for (unsigned int i = 0; i < VDDC.size(); i++) {
    if(!strcmp(Cal2021->get_day_name(VDDC[i]->f),"Martes")){
      VDDC[i]->set_TDT(1.5);
    }
    if(!strcmp(Cal2021->get_day_name(VDDC[i]->f),"Mi\\'ercoles")){
      VDDC[i]->set_TDT(1.5);
    }
    if(!strcmp(Cal2021->get_day_name(VDDC[i]->f),"Viernes")){
      VDDC[i]->set_TDT(1.5);
    }
  }
  /*Se necesita crear las actividades/temas a asignar en los
  dias de clase de teor\'{i}a disponibles. Se usa usa constructor de Actividad
  pasando el nombre del Tema y la duracion del Tema/Actividad en horas.*/
  vector<Actividad*> VDA;
void init_classroom_themes(vector<Actividad*>&);
  init_classroom_themes(VDA);

  /*Por ultimo se hace la planeacion pasando el vector de dias de
  clase y el vector de actividades*/
  Cal2021->planear(VDDC, VDA);

  /*Finalmente se imprime en pantalla los dias a planear con las
  actividades correspondientes por dia de clase entre las fechas
  f1 y f2.*/
  if(argc==1){
    cout<<"Los dias a planificar en 2021-1 para 3MV11::SOTR son:"<<endl;
    for (unsigned int i = 0;i<VDDC.size();i++) {
      cout<<*VDDC[i]<<endl;
    }
  }else if(argc==3){
    int Fi,Ff;
    Fi=atoi(argv[1]);
    Ff=atoi(argv[2]);
    vector<Dia*> v;
void fill_vector_v(vector<Dia*>&,vector<Dia*>&,int,int);
    fill_vector_v(VDDC,v,Fi,Ff);
    cout<<"D\\'{i}as a planificar\n";
    for (unsigned int i = 0;i<v.size();i++) {
      cout<<*v[i]<<endl;
    }
  }else if(argc>3){
    cout<<"FORMA DE USO:";
    printf("%s <yyyymmdd> YYYYMMDD\n",argv[0]);
  }

  delete Cal2021;  /*Borrar Calendario*/

  return 0;
}//end main()


