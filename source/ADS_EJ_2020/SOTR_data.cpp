/**SOTR_data.cpp*/
#include <iostream>
#include <vector>
using namespace std;
#define NDEBUG
#include <assert.h>

#include "../CommonFiles/Actividad.h"

/*Nueva ACTividad*/
#define NACT(name,duracion)	\
	VDA.push_back(new Actividad(name, duracion ## f ))

/*ends definition of macro NACT()*/
//#define NACTIV(name,duracion)	\
//	VDActividades.push_back(new Actividad(name, duracion ## f ))
//
///*ends definition of macro NACTIV()*/

void
init_classroom_themes(vector<Actividad*>& VDA)
{
  NACT("0.0 Presentaci\\'on de curso Sistemas operativos en tiempo real",1.5);
  NACT("Primario de programaci\\'on en lenguaje C",1.5);
  NACT("Introducci\\'on al uso del toolchain \
(gcc, make, make file, opciones -D, -I de gcc en command line y \
en make file) de un sistema GNU/Linux",6.0);
  NACT("U.T. I Introducci\\'on a los sistemas operativos en tiempo real",0.5);
  NACT("1.1 Definici\\'on de un sistema operativo en tiempo real",0.5);
  NACT("1.1.1 Clasificaci\\'on",0.5);
  NACT("1.1.2 Caracter\\'isticas",0.5);
  NACT("1.2 Diferencias entre un kernel de tiempo real y un kernel normal",1.0);
  NACT("1.2.1 Ejemplos de sistemas de tiempo real",0.0);
  NACT("1.3 Conociendo sistemas operativos en tiempo real",0.5);
  NACT("1.3.1 Ejemplos de sistemas operativos en tiempo real",0.5);
  NACT("1.4 Caractr\\'isticas en la instalaci\\'on de un sistema \
operativo en tiempo real",2.5);
  NACT("U.T. II Programaci\\'on concurrente",0.25);
  NACT("2.1 Concepto de procesos",0.5);
  NACT("2.1.1 Estados de procesos",0.5);
  NACT("2.1.2 Bloque de control de procesos",0.5);
  NACT("2.2 Concepto de concurrencia",1.0);
  NACT("2.2.1 Procesos s\\'incronos y as\\'incronos",0.5);
  NACT("2.3 Exclusi\\'on mutua",0.5);
  NACT("2.3.1 Regi\\'on cr\\'itica",0.5);
  NACT("2.3.2 Algoritmo de Dekker",0.5);
  NACT("2.3.3 Algoritmo de Peterson",0.5);
  NACT("2.4 Sem\\'aforos",1.0);
  NACT("2.4.1 Sincronizaci\\'on de procesos con sem\\'aforos",0.5);
  NACT("2.5 Mensajes",1.0);
  NACT("2.5.1 Comunicaci\\'on de procesos con mensajes",0.5);
//  NACT("2.6 Arreglos unidimensionalesy bidimensionales",1.0);
//  NACT("2.7 Funciones (M\\'etodos)",1.5);
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
}/*end init_classroom_themes()*/

//void
//init_laboratory_themes(vector<Actividad*>& VDActividades)
//{
//  NACTIV("U.T. I Introducci\\'on a la ingenier\\'ia del software", 0.5);
//  NACTIV("1.1 Conceptos fundamentales del software (dato, informaci\\'on)",1.0);
//  NACTIV("Programaci\\'on de la funci\\'on medible \
//{martes,...,lunes}<-->{0,1,...,6}",1.5);
//  NACTIV("P00 Uso de Cygwin:vim, g++, make; uso de github:git clone <repo url>,\
//git add <file name>, git commit -m\"<something>\",push origin master",1.5);
//  NACTIV("P00 REPASO de las actividades realizadas en el laboratorio",1.5);
//  NACTIV("P01 Introducci\\'on a la ingenier\\'ia del software",1.5);
//  NACTIV("P02 Fundamentos de la programaci\\'on en C++",5.0);
//  NACTIV("P03 Manejo de arreglos unidimensionales y multidimensionales \
//con C++",4.0);
//  NACTIV("P04 Uso de m\\'etodos (funciones) en C++", 4.0);
//  NACTIV("P05 Definici\\'on de clases y objetos en C++",6.0);
//  NACTIV("P06 Manejo de m\\'etodos", 4.5);
//  NACTIV("P07 Herencia simple y m\\'ultiple", 6.0);
//  NACTIV("P08 Clases abstractas y polimorfismo", 4.5);
//  NACTIV("P09 Diagramas de casos de uso", 2.0);
//  NACTIV("P10 Diagrama de actividades", 2.0);
//  NACTIV("P11 Diagramas de clase", 2.0);
//  NACTIV("P12 Diagramas de secuencia", 3.0);
//  NACTIV("P13 Diagramas de distribuci\\'on", 1.0);
//  NACTIV("P14 Generaci\\'on de c\\'odigo", 4.5);
//}/*end init_laboratory_themes()*/


