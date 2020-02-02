/** test_Calendario.cpp - Driver program used to test classes 
 *  Calendario, Fecha, Dia, Actividad, Asignacion (maybe), and 
 *  AdA.
 *  Learning Unit An\'{a}lisis y Dise\~{n}o de Sistemas 
 *  planning for the semester January - July, 2020.
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
#include "../CommonFiles/AdA.h"

///*Nueva ACTividad*/
//#define NACT(name,duracion)	\
//	VDA.push_back(new Actividad(name, duracion ## f ))
//
///*ends definition of macro NACT()*/

//#define NACTIV(name,duracion)	\
//	VDActividades.push_back(new Actividad(name, duracion ## f ))
//
///*ends definition of macro NACTIV()*/
//

int main(int argc,char *argv[])
{
  Calendario *Cal2020 = new Calendario(2020);
  Fecha f1(20,1,2020); /*Lunes 20 de enero de 2020 */
  Fecha f2(31,5,2020); /*Domingo 31 de mayo de 2020*/

  /*vector de dias de la semana en que hay clases (te\'{o}ria) de la 
   * UA correspondiente*/
  vector<string> vdd;   
  /*Se indican los d\'ias de la semana que hay clases de teor\'{i}a*/
  vdd.push_back("Lunes");
  vdd.push_back("Jueves");
  /*vector con las Fechas entre f1 y f2 correspondientes a 
   los dias en el vector vdd */
  vector<Fecha*> VDF = Cal2020->get_Fechas(&f1, &f2, vdd); 
  /*construir un vector de apuntadores a Dias no laborables*/
  vector<Dia*> vdnl;
  vdnl.push_back(new Dia(new Fecha(3,2,2020)));   /*Lunes 3 de febrero de 2020*/
  vdnl.push_back(new Dia(new Fecha(16,3,2020)));   /*Lunes 16 de marzo de 2020*/
  vdnl.push_back(new Dia(new Fecha(1,5,2020)));  /*Viernes 1 de mayo de 2020*/
  vdnl.push_back(new Dia(new Fecha(5,5,2020)));  /*Martes 5 de mayo de 2020*/
/*Ahora usando el vector de Fechas VDF y el vector de Dias no 
 laborables vdnl, construir un vector de Dias laborables (los dias de 
 clase para los que se planificar\'an actividades) este vector de Dias 
 laborables se obtendr\'a pasando un mensaje al objeto de clase 
 Calendario*/
  /*obtener Vector De Dias de Clase,*/
  vector<Dia*> VDDC = Cal2020->get_Dias_DC(VDF,vdnl); 
  /*Se asigna Tiempo Disponible Total segun el dia de que se trate*/
  for (unsigned int i = 0; i < VDDC.size(); i++) {
    if(!strcmp(Cal2020->get_day_name(VDDC[i]->f),"Lunes")){
      VDDC[i]->set_TDT(1.5);
    }
    if(!strcmp(Cal2020->get_day_name(VDDC[i]->f),"Jueves")){
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
  Cal2020->planear(VDDC, VDA);
  
  /*Finalmente se imprime en pantalla los dias a planear con las 
  actividades correspondientes por dia de clase entre las fechas 
  f1 y f2.*/
//  cout << "Los dias de clase te\\'orica a planificar son:" << endl;
//  for (unsigned int i = 0; i<VDDC.size(); i++) {
//    cout << *VDDC[i] << endl;
//  }
                   /*2019.10.29,2020.01.27*/

  /*Ahora la planeaci\'on (Enero-Mayo, 2020) */
  Fecha F1(20,1,2020); /*Lunes 20 de enero de 2020 */
  Fecha F2(31,5,2020); /*Domingo 31 de mayo de 2020 */
  /*vector de dias de la semana en que hay clases de laboratorio 
   * de la UA correspondiente*/
  vector<string> VDD;   
  VDD.push_back("Martes");
  VDD.push_back("Viernes");
  /*vector con las Fechas entre F1 y F2 correspondientes a 
   los dias en el vector VDD */
  vector<Fecha*> VDFechas= Cal2020->get_Fechas(&F1,&F2,VDD); 
  /*construir un vector de apuntadores a Dias no laborables*/
  vector<Dia*> VDNL;
  VDNL.push_back(new Dia(new Fecha(3,2,2020))); /*Lunes 3 de febrero de 2020*/
  VDNL.push_back(new Dia(new Fecha(3,2,2020)));   /*Lunes 3 de febrero de 2020*/
  VDNL.push_back(new Dia(new Fecha(16,3,2020)));   /*Lunes 16 de marzo de 2020*/
  VDNL.push_back(new Dia(new Fecha(1,5,2020)));  /*Viernes 1 de mayo de 2020*/
  VDNL.push_back(new Dia(new Fecha(5,5,2020)));  /*Martes 5 de mayo de 2020*/
  /*Ahora usando el vector de Fechas VDFechas y el vector de Dias no 
   laborables VDNL, construir un vector de Dias laborables (los dias de 
   clase para los que se planificar\'an actividades) este vector de Dias 
   laborables se obtendra pasando un mensaje al objeto de clase Calendario*/
   /*obtener Vector De Dias de Clase,*/
   vector<Dia*> VDDClase = Cal2020->get_Dias_DC(VDFechas,VDNL); 
  /*Se asigna Tiempo Disponible Total segun el dia de que se trate*/
  for (unsigned int i = 0; i < VDDClase.size(); i++){
    if(!strcmp(Cal2020->get_day_name(VDDClase[i]->f),"Martes")){
      VDDClase[i]->set_TDT(1.5);
    }
    if(!strcmp(Cal2020->get_day_name(VDDClase[i]->f),"Viernes")){
      VDDClase[i]->set_TDT(1.5);
    }
  }
  /*Se necesita crear las actividades/temas a asignar en los
  dias de clase de laboratorio disponibles. Se usa usa constructor 
  de Actividad pasando el nombre del Tema y la duracion del 
  Tema/Actividad en horas.*/
  vector<Actividad*> VDActividades;
void init_laboratory_themes(vector<Actividad*>&);
  init_laboratory_themes(VDActividades);
  /*Por ultimo se hace la planeacion pasando el vector de dias de 
   clase de laboratorio y el vector de actividades*/
  Cal2020->planear(VDDClase,VDActividades);
  /*Finalmente se imprime en pantalla los dias a planear con las 
  actividades correspondientes por dia de clase entre las fechas 
  F1 y F2.*/
//  cout<<"Los dias de clase de laboratorio a planificar en 2020 son:"<<endl;
//  for (unsigned int i = 0;i<VDDClase.size();i++) {
//  	cout<<*VDDClase[i]<<endl;
//  }
  vector<Dia*> V;
  cat_vddc(VDDC,VDDClase,V);
  ordenar_ddc(V);
#ifndef NDEBUG
  cout<<"V: "<<V.size()<<"\n";
#endif
  cout<<"Los dias a planificar en 2020-2 para ADS son:"<<endl;
  for (unsigned int i = 0;i<V.size();i++) {
  	cout<<*V[i]<<endl;
  }
  delete Cal2020;  /*Borrar Calendario usado anteriormente*/

  return 0;
}//end main()


