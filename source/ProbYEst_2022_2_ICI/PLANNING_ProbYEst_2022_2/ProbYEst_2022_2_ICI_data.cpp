/**ProbYEst_2022_2_ICI_data.cpp*/
#include <iostream>
#include <vector>
using namespace std;
#define NDEBUG
#include <assert.h>

#include "../CommonFiles/Actividad.h"
//#define ORIG
#define NUEVO

/*Nueva ACTividad*/
#define NACT(name,duracion)	\
	VDA.push_back(new Actividad(name, duracion ## f ))

/*ends definition of macro NACT()*/
//#define NACTIV(name,duracion)
//	VDActividades.push_back(new Actividad(name, duracion ## f ))
//
///*ends definition of macro NACTIV()*/
std::string day_place[7][2]={/*Tuesday 2021.02.09*/
  {"Lunes",""},
  {"Martes","Aula virtual"},
  {"Mi\\'ercoles","Aula virtual"},
  {"Jueves",""},
  {"Viernes","Aula virtual"},
  {"S\\'abado",""},
  {"Domingo",""}
};
std::string day_horario[7][2]={/**Tuesday 2021.09.02*/
  {"Lunes",""},
  {"Martes","14:30-16:00"},
  {"Mi\\'ercoles","14:30-16:00"},
  {"Jueves",""},
  {"Viernes","14:30-16:00"},
  {"S\\'abado",""},
  {"Domingo",""}
};

void
init_classroom_themes(vector<Actividad*>& VDA)
{
 NACT("U.T. I INTRODUCCION A LOS SISTEMAS OPERATIVOS \
EN TIEMPO REAL",0.5);
 NACT("1.1 Definici\\'on de un sistema operativo en tiempo \
real (AD P1 INSTALACION DE UN SISTEMA OPERATIVO EN \
TIEMPO REAL)",1.0);
 NACT("1.1 Definici\\'on de un sistema operativo en tiempo \
real (AA P1 INSTALACION DE UN SISTEMA OPERATIVO EN \
TIEMPO REAL)",2.0);
 NACT("1.2 Diferencias entre un kernel de tiempo real y un \
kernel normal (AD P1 INSTALACION DE UN SISTEMA OPERATIVO EN \
TIEMPO REAL)",1.5);
//#ifdef ORIG
 NACT("1.2 Diferencias entre un kernel de tiempo real y un \
kernel normal (AA P1 INSTALACION DE UN SISTEMA OPERATIVO EN \
TIEMPO REAL)",2.0);
//#endif // ORIG
 NACT("1.3 Conociendo sistemas operativos en tiempo real \
(AD P1 INSTALACION DE UN SISTEMA OPERATIVO EN TIEMPO REAL)",1.5);
#ifdef ORIG
 NACT("1.3 Conociendo sistemas operativos en tiempo real \
(AA P1 INSTALACION DE UN SISTEMA OPERATIVO EN TIEMPO REAL)",0.5);
#endif // ORIG
 NACT("1.4 Caracter\\'isticas en la instalaci\\'on de un \
sistema operativo en tiempo real (AD P2 CONOCIENDO EL \
ENTORNO DE UN SISTEMA OPERATIVO EN TIEMPO REAL)",2.5);
 NACT("1.4 Caracter\\'isticas en la instalaci\\'on de un \
sistema operativo en tiempo real (AA P2 CONOCIENDO EL \
ENTORNO DE UN SISTEMA OPERATIVO EN TIEMPO REAL)",3.5);
#ifdef NUEVO
 NACT("TRABAJO DE INVESTIGACION SOBRE SISTEMAS OPERATIVOS \
DE TIEMPO REAL",2.0);
#endif // NUEVO
 NACT("1.4 Caracter\\'isticas en la instalaci\\'on de un \
sistema operativo en tiempo real (AA P2 CONOCIENDO EL \
ENTORNO DE UN SISTEMA OPERATIVO EN TIEMPO REAL)",1.5);
#ifdef NUEVO
 NACT("CUADRO/TABLA COMPARATIVA DE SISTEMAS OPERATIVOS CONVENCIONALES \
Y DE TIEMPO REAL",2.0);
#endif // NUEVO
 NACT("1.4 Caracter\\'isticas en la instalaci\\'on de un \
sistema operativo en tiempo real (AA P2 CONOCIENDO EL \
ENTORNO DE UN SISTEMA OPERATIVO EN TIEMPO REAL)",1.5);
#ifdef NUEVO
 NACT("ALBUM DE ARCHIVOS DE CODIGO FUENTE EN LENGUAJE ENSAMBLADOR \
Y ANSI C",2.0);
#endif // NUEVO
#ifdef NUEVO
 NACT("REPORTES DE LAS PRACTICAS 1 y 2",2.0);
#endif // NUEVO

 NACT("U.T. II PROGRAMACION CONCURRENTE",0.25);
 NACT("2.1 Concepto de proceso (AD P3 CREACION DE PROCESOS)",0.5);
 NACT("2.1 Concepto de proceso (AA P3 CREACION DE PROCESOS)",1.5);
 NACT("2.2 Concepto de concurrencia (AD P3 CREACION DE PROCESOS)",0.75);
 NACT("2.2 Concepto de concurrencia (AA P3 CREACION DE PROCESOS)",1.5);
#ifdef NUEVO
 NACT("TRABAJO DE INVESTIGACION SOBRE LOS PROCESOS/TAREAS DE LOS \
SISTEMAS OPERATIVOS",0.5);
#endif // NUEVO
 NACT("2.3 Exclusi\\'on mutua (AD P4 EXCLUSION MUTUA)",2.0);
 NACT("2.3 Exclusi\\'on mutua (AA P4 EXCLUSION MUTUA)",4.0);
#ifdef NUEVO
 NACT("CUADRO/TABLA COMPARATIVA DE FUNCIONES DE BIBLIOTECA SINCRONAS \
Y ASINCRONAS DEL SISTEMA OPERATIVO MARTE OS",0.5);
#endif // NUEVO
 NACT("2.3 Exclusi\\'on mutua (AD P5 ALGORITMO DE DEKKER Y PETERSON)",1.5);
 NACT("2.3 Exclusi\\'on mutua (AA P5 ALGORITMO DE DEKKER Y PETERSON)",2.5);
#ifdef NUEVO
 NACT("ALBUM DE ARCHIVOS DE CODIGO FUENTE EN LENGUAJE ENSAMBLADOR \
Y ANSI C",0.5);
#endif // NUEVO
 NACT("2.4 Sem\\'aforos (AD P6 UTILIZANDO SEMAFOROS PARA SINCRONIZAR \
PROCESOS)",1.5);
 NACT("2.4 Sem\\'aforos (AA P6 UTILIZANDO SEMAFOROS PARA SINCRONIZAR \
PROCESOS)",1.5);
 NACT("2.5 Mensajes (AD P7 UTILIZANDO MENSAJES PARA SINCRONIZAR \
PROCESOS)",1.5);
 NACT("2.5 Mensajes (AA P7 UTILIZANDO MENSAJES PARA SINCRONIZAR \
PROCESOS)",1.5);
#ifdef NUEVO
 NACT("REPORTES DE LAS PRACTICAS 3, 4, 5, 6 y 7",0.5);
#endif // NUEVO
 //NACT("U.T. II PROGRAMACION CONCURRENTE",0.0);
 //NACT("U.T. II PROGRAMACION CONCURRENTE",24.0);

 NACT("U.T. III LAS TAREAS, INTERRUPCIONES Y EL RELOJ \
EN TIEMPO REAL",0.25);
 NACT("3.1 Tareas en tiempo real (AD P8 MANEJO DE \
INTERRUCIONES)",0.25);
 NACT("3.1 Tareas en tiempo real (AA P8 MANEJO DE \
INTERRUCIONES)",1.0);
#ifdef NUEVO
 NACT("TRABAJO DE INVESTIGACION SOBRE LOS PROCESOS/TAREAS DE LOS \
SISTEMAS OPERATIVOS",0.5);
#endif // NUEVO
 NACT("3.2 Interrupciones (AD P8 MANEJO DE INTERRUCIONES)",2.0);
 NACT("3.2 Interrupciones (AA P8 MANEJO DE INTERRUCIONES)",1.5);
#ifdef NUEVO
 NACT("CUADRO/TABLA COMPARATIVA DE INTERRUPCIONES ENMASCARABLES \
Y NO ENMASCARABLES DE LOS MICROPROCESADORES INTEL",0.5);
#endif // NUEVO
 NACT("3.3 Reloj del sistema (AD P9 MEDICION DEL TIEMPO \
EN UNA TAREA DEL SISTEMA)",1.0);
#ifdef NUEVO
 NACT("ALBUM DE ARCHIVOS DE CODIGO FUENTE EN LENGUAJE ENSAMBLADOR \
Y ANSI C",0.5);
#endif // NUEVO
 NACT("3.3 Reloj del sistema (AA P9 MEDICION DEL TIEMPO \
EN UNA TAREA DEL SISTEMA)",1.5);
#ifdef NUEVO
 NACT("REPORTES DE LAS PRACTICAS 8 y 9",0.5);
#endif // NUEVO
 //NACT("U.T. III LAS TAREAS, INTERRUPCIONES Y EL RELOJ
//EN TIEMPO REAL",0.0);
 //NACT("U.T. III LAS TAREAS, INTERRUPCIONES Y EL RELOJ
//EN TIEMPO REAL",14.0);

 NACT("U.T. IV PLANIFICACION DE PROCESOS",0.25);
 NACT("4.1 Planificador del sistema en tiempo real \
(AD P10 PLANIFICANDO PROCESOS)",1.75);
 NACT("4.1 Planificador del sistema en tiempo real \
(AA P10 PLANIFICANDO PROCESOS)",5.0);
 NACT("4.2 Enfoque c\\'iclico (AD P10 PLANIFICANDO \
PROCESOS)",0.5);
 NACT("4.2 Enfoque c\\'iclico (AA P10 PLANIFICANDO \
PROCESOS)",1.0);
#ifdef NUEVO
 NACT("TRABAJO DE INVESTIGACION SOBRE PLANIFICACION DE PROCESOS/TAREAS"
,0.5);
#endif // NUEVO
 NACT("4.3 Algoritmos de planificaci\\'on (AD P11 ALGORITMOS \
DE PLANIFICACION)",2.0);
 NACT("4.3 Algoritmos de planificaci\\'on (AA P11 ALGORITMOS \
DE PLANIFICACION)",3.5);
 NACT("4.4 Procesos espor\\'adicos y aperi\\'odicos (AD P11 \
ALGORITMOS DE PLANIFICACION)",1.0);
 NACT("4.4 Procesos espor\\'adicos y aperi\\'odicos (AA P11 \
ALGORITMOS DE PLANIFICACION)",1.5);
#ifdef NUEVO
 NACT("CUADRO/TABLA COMPARATIVA DE ALGORITMOS DE PLANIFICACION \
DE TAREAS EN SISTEMAS OPERATIVOS DE TIEMPO REAL",0.5);
#endif // NUEVO
 NACT("4.5 Interacci\\'on de procesos y bloqueo (AD P12 \
PLANIFICACION POR PRIORIDAD",1.5);
#ifdef NUEVO
 NACT("ALBUM DE ARCHIVOS DE CODIGO FUENTE EN LENGUAJE ENSAMBLADOR \
Y ANSI C",0.5);
#endif // NUEVO
 NACT("4.5 Interacci\\'on de procesos y bloqueo (AA P12 \
PLANIFICACION POR PRIORIDAD)",1.5);
#ifdef NUEVO
 NACT("REPORTES DE LAS PRACTICAS 10, 11 y 12",0.5);
#endif // NUEVO
 //NACT("U.T. III LAS TAREAS, INTERRUPCIONES Y EL RELOJ
//EN TIEMPO REAL",0.0);
 //NACT("U.T. III LAS TAREAS, INTERRUPCIONES Y EL RELOJ
//EN TIEMPO REAL",25.0);
}
