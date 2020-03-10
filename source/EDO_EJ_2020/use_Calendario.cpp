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
#include <util.h>


int main(int argc,char *argv[])
{
  Calendario *Cal2020 = new Calendario(2020);
  Fecha f1(3,3,2020); /*Martes 3 de marzo de 2020 */
  Fecha f2(27,6,2020); /*Sabado 27 de junio de 2020*/

  /*vector de dias de la semana en que hay clases (te\'{o}ria) de la 
   * UA correspondiente*/
  vector<string> vdd;   
  /*Se indican los d\'ias de la semana que hay clases de teor\'{i}a*/
  vdd.push_back("Martes");
  vdd.push_back("Viernes");
  /*vector con las Fechas entre f1 y f2 correspondientes a 
   los dias en el vector vdd */
  vector<Fecha*> VDF = Cal2020->get_Fechas(&f1, &f2, vdd); 
  /*construir un vector de apuntadores a Dias no laborables*/
  vector<Dia*> vdnl;
  vdnl.push_back(new Dia(new Fecha(3,2,2020)));   /*Lunes 3 de febrero de 2020*/
  vdnl.push_back(new Dia(new Fecha(16,3,2020)));   /*Lunes 16 de marzo de 2020*/
  vdnl.push_back(new Dia(new Fecha(9,4,2020)));   //Jueves y
  vdnl.push_back(new Dia(new Fecha(10,4,2020)));  //Viernes santos.
  vdnl.push_back(new Dia(new Fecha(1,5,2020)));  /*Viernes 1 de mayo de 2020*/
  vdnl.push_back(new Dia(new Fecha(5,5,2020)));  /*Martes 5 de mayo de 2020*/
  //vdnl.push_back(new Dia(new Fecha(5,5,2020)));
/*Ahora usando el vector de Fechas VDF y el vector de Dias no 
 laborables vdnl, construir un vector de Dias laborables (los dias de 
 clase para los que se planificar\'an actividades) este vector de Dias 
 laborables se obtendr\'a pasando un mensaje al objeto de clase 
 Calendario*/
  /*obtener Vector De Dias de Clase,*/
  vector<Dia*> VDDC = Cal2020->get_Dias_DC(VDF,vdnl); 
  /*Se asigna Tiempo Disponible Total segun el dia de que se trate*/
  for (unsigned int i = 0; i < VDDC.size(); i++) {
    if(!strcmp(Cal2020->get_day_name(VDDC[i]->f),"Martes")){
      VDDC[i]->set_TDT(2.0);
    }
    if(!strcmp(Cal2020->get_day_name(VDDC[i]->f),"Viernes")){
      VDDC[i]->set_TDT(2.0);
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

//  vector<Dia*> VDDClase;
  vector<Dia*> V;
//  cat_vddc(VDDC,VDDClase,V);
//  ordenar_ddc(V);
//#ifndef NDEBUG
//  cout<<"V: "<<V.size()<<"\n";
//#endif
typedef unsigned int uint;
  for(uint ni=0;ni<VDDC.size();ni++)
  {
    V.push_back(VDDC[ni]);
  }
  if(argc==1){
    cout<<"Los dias a planificar en 2020-2 para EDO son:"<<endl;
    for (unsigned int i = 0;i<V.size();i++) {
      cout<<*V[i]<<endl;
    }
  }else if(argc==3){
    int Fi,Ff;
    Fi=atoi(argv[1]);
    Ff=atoi(argv[2]);
    vector<Dia*> v;
void fill_vector_v(vector<Dia*>&,vector<Dia*>&,int,int);
    fill_vector_v(V,v,Fi,Ff);
    //cout<<"Total de d\\'{i}as a planificar: "<<v.size()<<"\n";
    for (unsigned int i = 0;i<v.size();i++) {
      cout<<"["<<i+1<<"] ";
      cout<<*v[i]<<endl;
    }
    cout<<"Total de d\\'{i}as planificados: "<<v.size()<<"\n";
    cout<<"\nTiempo total necesario para las actividades\nta="
        <<Actividad::ta<<"\n";
  }else if(argc>3){
    cout<<"FORMA DE USO:";
    printf("%s <yyyymmdd> YYYYMMDD\n",argv[0]);
  }
 
  delete Cal2020;  /*Borrar Calendario*/

  return 0;
}//end main()


