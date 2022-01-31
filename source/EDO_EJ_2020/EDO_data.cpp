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
  NACT("0.0 Presentaci\\'on de curso Ecuaciones Diferenciales",1.5);
  NACT("U.T. I ECUACIONES DIFERENCIALES DE PRIMER ORDEN", 0.5);
  NACT("I.A IMPORTANCIA DEL ESTUDIO DE LAS ECUACIONES DIFERENCIALES",2.0);
  NACT("I.B METODOS DE SOLUCION DE ECUACIONES DIFERENCIALES DE PRIMER ORDEN",2.0);
  NACT("I.C APLIACIONES FISICAS, QUIMICAS Y BIOLOGICAS",2.0);
  NACT("PRIMERA EVALUACION PARCIAL",2.0);
  NACT("REVISION DE LA PRIMERA EVALUACION PARCIAL",2.0);
  NACT("U.T. II ECUACIONES DIFERENCIALES LINEALES DE ORDEN SUPERIOR (DOS O MAYOR)",0.25);
  NACT("II.A REDUCCION DE ORDEN",1.75);
  NACT("II.B SOLUCION GENERAL DE LA ECUACION LINEAL HOMOGENEA Y NO HOMOGENEA",2.0);
  NACT("II.C SOLUCIONES LINEALMENTE INDEPENDIENTES Y WRONSKIANO",2.0);
  NACT("II.D TEOREMA DE EXISTENCIA",2.0);
  NACT("II.E LA ECUACION LINEAL HOMOGENEA CON COEFICIENTES CONSTANTES Y PROBLEMAS CON VALOR INICIAL",2.0);
  NACT("II.F METODOS DE SOLUCION DE ECUACIONES DIFERENCIALES NO HOMOGENEAS",1.0);
  NACT("II.G APLICACIONES FISICAS",1.0);
  NACT("SEGUNDA EVALUACION PARCIAL",2.0);
  NACT("REVISION DE LA SEGUNDA EVALUACION PARCIAL",2.0);
  NACT("U.T. III SISTEMAS DE ECUACIONES DIFERENCIALES DE PRIMER ORDEN",0.5);
  NACT("III.A SISTEMAS LINEALES HOMOGENEOS CON COEFICIENTES CONSTANTES",1.5);
  NACT("III.B VALORES PROPIOS REALES Y DISTINTOS",2.5);
  NACT("III.C VALORES PROPIOS REPETIDOS",2.0);
  NACT("III.D VALORES PROPIOS COMPLEJOS",0.5);
  NACT("III.E VARIACION DE PARAMETROS",2.5);
  NACT("III.F MATRIZ EXPONENCIAL",2.5);
  NACT("U.T. IV TRANSFORMADA DE LAPLACE",0.25);
  NACT("IV.A EXISTENCIA DE LA TRANSFORMADA",0.25);
  NACT("IV.B SOLUCION DE ECUACIONES DIFERENCIALES USANDO LA TRANSFORMADA DE LAPLACE",1.0);
  NACT("IV.C PROPIEDADES DE LA TRANSFORMADA Y APLICACIONES FISICAS",0.5);
  NACT("U.T. V FUNCIONES ORTOGONALES Y SERIES DE FOURIER",0.25);
  NACT("V.A FUNCIONES ORTOGONALES",0.25);
  NACT("V.B SERIES DE FOURIER",1.75);
  NACT("V.C SERIES DE FOURIER DE SENOS Y COSENOS",0.5);
  NACT("V.D EL PROBLEMA DE STURM LLOUVILLE",1.25);
  NACT("U.T. VI ECUACIONES DIFERENCIALES EN DERIVADAS PARCIALES Y PROBLEMAS DE VALOR EN LA FRONTERA EN CORDENADAS RECTANGULARES",2.0);
  NACT("VI.A ECUACIONES DIFERENCIALES PARCIALES SEPARABLES",3.0);
  NACT("VI.B ECUACIONES CLASICAS Y PROBLEMAS DE VALOR EN LA FRONTERA",1.0);
  NACT("VI.C ECUACION DE TRANSMISION DE CALOR",0.5);
  NACT("VI.D ECUACION DE ONDA",0.5);
  NACT("VI.E ECUACION DE LAPLACE",0.5);
  NACT("VI.F ECUACIONES NO HOMOGENEAS Y CONDICIONES EN LA FRONTERA", 0.5);
  NACT("TERCERA EVALUACION PARCIAL",2.0);
  NACT("REVISION DE LA TERCERA EVALUACION PARCIAL",2.0);
  NACT("EXAMEN FINAL",2.0);
  NACT("REVISION DEL EXAMEN FINAL",2.0);
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
//
