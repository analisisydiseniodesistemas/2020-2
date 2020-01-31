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

/*Nueva ACTividad*/
#define NACT(name,duracion)	\
	VDA.push_back(new Actividad(name, duracion ## f ))

/*ends definition of macro NACT()*/

#define NACTIV(name,duracion)	\
	VDActividades.push_back(new Actividad(name, duracion ## f ))

/*ends definition of macro NACTIV()*/

//int anio = 2020;    /*IS THIS ACTUALLY NEEDED?????????????*/   
                    /**                           2020.01.27
                      YES, see default constructor of class Fecha at 
                      file ../CommonFiles/Fecha.h           */ 
//Calendario *Cal_Greg;   /*Calendario Gregoriano*/

//char MES[][32]={"static char MES[][32]",
//	"enero","febrero","marzo","abril","mayo","junio","julio",
//	"agosto","septiembre","octubre","noviembre","diciembre"
//};

int main(int argc,char *argv[])
{
  //Cal_Greg=new Calendario(2020);    /*Calendario Gregoriano*/
  /*IS Cal_Greg ACTUALLY NEEDED??????????????  2020.01.23
   *                                                    2020.01.27
   *YES, it is used passing it the message get_day_name(Fecha*) */

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
  NACT("0.0 Presentaci\\'on del curso",1.5);
  NACT("U.T. I Introducci\\'on a la ingenier\\'ia del software", 0.5);
  NACT("1.1 Conceptos fundamentales del software (dato, informaci\\'on)",2.5);
  NACT("1.2 Definici\\'on del software",2.0);
  NACT("1.3 Sistemas de informaci\\'on",1.5);
  NACT("1.4 A\\'alisis de requisitos",2.5);
  NACT("1.5 Ciclos de vida",2.0);
  NACT("1.6 Legislaci\\'on del software",0.5);
  NACT("1.7 M\\'etodolog\\'ias para el desarrollo del software",2.5);
  NACT("U.T. II Fundamentos de Programaci\\'on en C++",0.25);
  NACT("2.1 Estructura del lenguaje",0.5);
  NACT("2.2 Funciones de entrada y salida en C++:cin>> y cout<<",0.5);
  NACT("2.3 Declaraci\\'on de variables y constantes",0.5);
  NACT("2.4 Operadores",1.5);
  NACT("2.5 Sentencias de control",1.0);
  NACT("2.6 Arreglos unidimensionalesy bidimensionales",1.0);
  NACT("2.7 Funciones (M\\'etodos)",1.5);
  NACT("U.T. III Fundamentos del paradigma de Orientaci\\'on a Objetos",0.5);
  NACT("3.1 Definici\\'on del paradigma de orientaci\\'on a objetos",\
0.5);
  NACT("3.2 Objetos",3.0);
  NACT("3.3 Definici\\'on y creaci\\'on de m\\'etodos",3.0);
  NACT("3.4 Encapsulado de clases",1.5);
  NACT("3.5 Herencia simple y m\\'ultiple",3.0);
  NACT("3.6 Clases abstractas",0.5);
  NACT("3.7 Polimorfismo",1.0);
  NACT("U.T. 4 An\\'alisis y dise\\~{n}o con UML", 0.25);
  NACT("4.1 Introducci\\'on a UML",0.5);
  NACT("4.2 Herramientas de modelado",0.5);
  NACT("4.3 Diagramas b\\'asicos en UML",0.5);
  NACT("4.4 Diagrama de Actividades",1.5);
  NACT("4.5 Diagramas de clase",1.5);
  NACT("4.6 Diagramas de secuencia",2.0);
  NACT("4.7 Diagrama de distribuci\\'on", 1.0);
  NACT("4.8 Generaci\\'on de c\\'odigo",3.0);

  /*Por ultimo se hace la planeacion pasando el vector de dias de 
  clase y el vector de actividades*/
  Cal2020->planear(VDDC, VDA);
  
  /*Finalmente se imprime en pantalla los dias a planear con las 
  actividades correspondientes por dia de clase entre las fechas 
  f1 y f2.*/
  cout << "Los dias de clase te\\'orica a planificar son:" << endl;
  for (unsigned int i = 0; i<VDDC.size(); i++) {
    cout << *VDDC[i] << endl;
  }
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
  NACTIV("P01 Introducci\\'on a la ingenier\\'ia del software",1.5);
  NACTIV("P02 Fundamentos de la programaci\\'on en C++",9.0);
  NACTIV("P03 Manejo de arreglos unidimensionales y multidimensionales \
con C++",4.0);
  NACTIV("P04 Uso de m\\'etodos (funciones) en C++", 4.0);
  NACTIV("P05 Definici\\'on de clases y objetos en C++",6.0);
  NACTIV("P06 Manejo de m\\'etodos", 4.5);
  NACTIV("P07 Herencia simple y m\\'ultiple", 6.0);
  NACTIV("P08 Clases abstractas y polimorfismo", 4.5);
  NACTIV("P09 Diagramas de casos de uso", 2.0);
  NACTIV("P10 Diagrama de actividades", 2.0);
  NACTIV("P11 Diagramas de clase", 2.0);
  NACTIV("P12 Diagramas de secuencia", 3.0);
  NACTIV("P13 Diagramas de distribuci\\'on", 1.0);
  NACTIV("P14 Generaci\\'on de c\\'odigo", 4.5);
  /*Por ultimo se hace la planeacion pasando el vector de dias de 
   clase de laboratorio y el vector de actividades*/
  Cal2020->planear(VDDClase,VDActividades);
  /*Finalmente se imprime en pantalla los dias a planear con las 
  actividades correspondientes por dia de clase entre las fechas 
  F1 y F2.*/
  cout<<"Los dias de clase de laboratorio a planificar en 2020 son:"<<endl;
  for (unsigned int i = 0;i<VDDClase.size();i++) {
  	cout<<*VDDClase[i]<<endl;
  }
  vector<Dia*> V;
  cat_vddc(VDDC,VDDClase,V);
  ordenar_ddc(V);
  cout<<"Los dias a planificar en 2020-2 para ADS son:"<<endl;
  for (unsigned int i = 0;i<VDDClase.size();i++) {
  	cout<<*V[i]<<endl;
  }
  delete Cal2020;  /*Borrar Calendario usado anteriormente*/
  //delete Cal_Greg; /*Borrar Calendario Gregoriano a usar de ahora 
  //                   en m\'as. Lo ``nuevo'' en la clase del objeto
  //                   Cal_Greg es el m\'etodo 
  //                   (char [][32] get_day_name(Fecha*))*/
                   /*En realidad, los dos objetos (Cal2019 y Cal_Greg) 
                     son de clase Calendario, as\'i que en una 
                     siguiente versi\'on planeo usar solo una variable 
                     global de tipo Calendario*/ 
  return 0;
}//end main()


