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
//#define NACTIV(name,duracion)
//	VDActividades.push_back(new Actividad(name, duracion ## f ))
//
///*ends definition of macro NACTIV()*/
#ifdef SEPTIEMBRE_DICIEMBRE_2020
void
init_classroom_themes(vector<Actividad*>& VDA)
{
  NACT("0.0 Presentaci\\'on de curso Sistemas operativos en tiempo real",0.25);
  NACT("Primario de programaci\\'on en lenguaje C",0.25);
  NACT("Introducci\\'on al uso del toolchain \
(gcc, make, make file, opciones -D, -I, -H de gcc en command line y \
en make file) de un sistema GNU/Linux",3.0);
  NACT("U.T. I Introducci\\'on a los sistemas operativos en tiempo real",0.5);
  NACT("1.1 Definici\\'on de un sistema operativo en tiempo real",2.25);
  //NACT("1.1.1 Clasificaci\\'on",0.5);
  //NACT("1.1.2 Caracter\\'isticas",0.5);
  NACT("1.2 Diferencias entre un kernel de tiempo real y un kernel normal",3.5);
  //NACT("1.2.1 Ejemplos de sistemas de tiempo real",0.0);
  NACT("1.3 Conociendo sistemas operativos en tiempo real",3.0);
  //NACT("1.3.1 Ejemplos de sistemas operativos en tiempo real",0.5);
  NACT("1.4 Caracter\\'isticas en la instalaci\\'on de un sistema \
operativo en tiempo real",6.0);

  NACT("U.T. II Programaci\\'on concurrente",0.25);
  NACT("2.1 Concepto de procesos",4.5);
  //NACT("2.1.1 Estados de procesos",0.5);
  //NACT("2.1.2 Bloque de control de procesos",0.5);
  NACT("2.2 Concepto de concurrencia",4.5);
  //NACT("2.2.1 Procesos s\\'incronos y as\\'incronos",0.5);
  NACT("2.3 Exclusi\\'on mutua",6.0);
  //NACT("2.3.1 Regi\\'on cr\\'itica",0.5);
  //NACT("2.3.2 Algoritmo de Dekker",0.5);
  //NACT("2.3.3 Algoritmo de Peterson",0.5);
  NACT("2.4 Sem\\'aforos",4.5);
  //NACT("2.4.1 Sincronizaci\\'on de procesos con sem\\'aforos",0.5);
  NACT("2.5 Mensajes",4.5);
  //NACT("2.5.1 Comunicaci\\'on de procesos con mensajes",0.5);

  NACT("U.T. III Las tareas, interrupciones y el reloj en tiempo real",0.5);
  NACT("3.1 Tareas en tiempo real",2.0);
  NACT("3.2 Interrupciones",6.0);
  //NACT("3.3 Reloj del sistema",6.0);
  NACT("3.3 Reloj del sistema",5.5);

  NACT("U.T. 4 Planificaci\\'on de procesos", 0.5);
  //NACT("4.1 Planificador del sistema en tiempo real",7.0);
  NACT("4.1 Planificador del sistema en tiempo real",4.0);
  NACT("4.2 Enfoque c\\iclico",1.5);
  NACT("4.3 Algoritmos de planificaci\\'on",12.0);
  NACT("4.4 Procesos espor\\'adicos y apri\\'odicos",2.5);
  NACT("4.5 Interacci\\'on de procesos y bloqueo",2.0);
}/*end init_classroom_themes()*/
#endif // SEPTIEMBRE_DICIEMBRE_2020
#ifdef ENERO_2021
void
init_classroom_themes(vector<Actividad*>& VDA)
{
  NACT("U.T. 4 Planificaci\\'on de procesos", 0.5);
  //NACT("4.1 Planificador del sistema en tiempo real",7.0);
  NACT("4.1 Planificador del sistema en tiempo real",4.5);
  //NACT("4.2 Enfoque c\\iclico",1.5);
  NACT("4.2 Enfoque c\\iclico",1.0);
  //NACT("4.3 Algoritmos de planificaci\\'on",12.0);
  NACT("4.3 Algoritmos de planificaci\\'on",4.5);
  //NACT("4.4 Procesos espor\\'adicos y aperi\\'odicos",2.5);
  NACT("4.4 Procesos espor\\'adicos y aperi\\'odicos",1.5);
  NACT("4.5 Interacci\\'on de procesos y bloqueo",2.0);
}/*end init_classroom_themes()*/
#endif // ENERO_2021


