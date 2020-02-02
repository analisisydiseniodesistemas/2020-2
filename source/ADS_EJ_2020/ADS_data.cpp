/**ADS_data.cpp*/
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
#define NACTIV(name,duracion)	\
	VDActividades.push_back(new Actividad(name, duracion ## f ))

/*ends definition of macro NACTIV()*/

void
init_classroom_themes(vector<Actividad*>& VDA)
{
  NACT("0.0 Presentaci\\'on de curso An\\'{a}lisis y Dise\\~{n}o de Sistemas",1.5);
//  NACT("U.T. I Introducci\\'on a la ingenier\\'ia del software", 0.5);
  NACT("1.1 Conceptos fundamentales del software (dato, informaci\\'on)",0.5);
  NACT("Ejemplo de una funci\\'on medible {martes,...,lunes}<-->{0,1,...,6}",1.0);
  NACT("Relaciones de equivalencia, s\\imbolo de UML para una clase",1.5);
  NACT("1.1.1 Descripci\\'on de algoritmo",0.5);
  NACT("Algoritmo de la ra\\'iz cuadrada",0.5);
  NACT("Algoritmo de Euclides",0.5);
  NACT("1.2 Definici\\'on del software",0.5);
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
}/*end init_classroom_themes()*/

void
init_laboratory_themes(vector<Actividad*>& VDActividades)
{
  NACTIV("U.T. I Introducci\\'on a la ingenier\\'ia del software", 0.5);
  NACTIV("1.1 Conceptos fundamentales del software (dato, informaci\\'on)",1.0);
  NACTIV("Programaci\\'on de la funci\\'on medible \
{martes,...,lunes}<-->{0,1,...,6}",1.5);
  NACTIV("P00 Uso de Cygwin:vim, g++, make; uso de github:git clone <repo url>,\
git add <file name>, git commit -m\"<something>\",push origin master",1.5);
  NACTIV("P00 REPASO de las actividades realizadas en el laboratorio",1.5);
  NACTIV("P01 Introducci\\'on a la ingenier\\'ia del software",1.5);
  NACTIV("P02 Fundamentos de la programaci\\'on en C++",5.0);
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
}/*end init_laboratory_themes()*/


