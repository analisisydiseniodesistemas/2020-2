/**PROG_ESTRUCT_2021_2_1TV1_data.cpp*/
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
std::string day_place[7][2]={/*Tuesday 2021.02.09*/
  {"Lunes",""},
  //{"Martes","2/o ICE"},
  {"Martes",""},
  {"Mi\\'ercoles",""},
  {"Jueves",""},
  //{"Viernes","2/o ICE"},
  {"Viernes",""},
  {"S\\'abado",""},
  {"Domingo",""}
};
std::string day_horario[7][2]={/*Tuesday 2021.02.09*/
  {"Lunes","13:00-14:30"},
  {"Martes","13:00-14:30"},
  {"Mi\\'ercoles","13:00-14:30"},
  {"Jueves",""},
  {"Viernes",""},
  {"S\\'abado",""},
  {"Domingo",""}
};

void
init_classroom_themes(vector<Actividad*>& VDA)
{
 NACT("U.T. I INTRODUCCION A LA PROGRAMACION",0.25);
 NACT("1.1 Estructura de un Programa en C (AD T)",0.25);
 NACT("1.1 Estructura de un Programa en C (AA T)",0.5);
 NACT("1.2 Uso de variables y constantes (AD T)",0.5);
 NACT("1.2 Uso de variables y constantes (AA T)",0.5);
 NACT("1.3 Creaci\\'on de c\\'odigo fuente, objeto \
y ejecutable (AD P1)",1.0);
 NACT("1.3 Creaci\\'on de c\\'odigo fuente, objeto \
y ejecutable (AA T)",0.5);
 NACT("1.4 Operadores (AA T)",1.0);
 NACT("1.4 Operadores (AD P1)",1.0);
 NACT("1.5 Expresiones simples y complejas (AA T)",1.0);
 NACT("1.5 Expresiones simples y complejas (AD P1)",1.0);

 NACT("U.T. II ESTRUCTURAS DE CONTROL Y APLICACIONES \
CON ARREGLOS",0.25);
 NACT("2.1 Diagramas de flujo (AD T)",0.25);
 NACT("2.1 Diagramas de flujo (AD P2)",3.0);
 NACT("2.1 Diagramas de flujo (AA T)",0.5);
 NACT("2.1 Diagramas de flujo (AA P2)",0.5);
 NACT("2.2 Sentencias de control (AD T)",1.0);
 NACT("2.2 Sentencias de control (AA T)",1.0);
 NACT("2.2 Sentencias de control (AD P2)",4.0);
 NACT("2.2 Sentencias de control (AA P2)",0.5);
 NACT("2.3 Tipos de arreglos (AD T)",1.0);
 NACT("2.3 Tipos de arreglos (AA T)",1.0);
 NACT("2.3 Tipos de arreglos (AD P3)",4.5);
 NACT("2.4 Aplicaciones con arreglos (AD T)",1.0);
 NACT("2.4 Aplicaciones con arreglos (AA T)",1.0);
 //NACT("2.4 Aplicaciones con arreglos (AD P3)",4.5);
 NACT("2.4 Aplicaciones con arreglos (AD P3)",3.0);
 NACT("2.4 Aplicaciones con arreglos (AA P3)",0.5);
// NACT("U.T. II ESTRUCTURAS DE CONTROL Y APLICACIONES
//CON ARREGLOS",0.0);

 NACT("U.T. III MANEJO DE FUNCIONES Y CADENAS",0.5);
 NACT("3.1 Funciones (AD T)",0.5);
 NACT("3.1 Funciones (AA T)",2.0);
 //NACT("3.1 Funciones (AD P4)",4.0);
 NACT("3.1 Funciones (AD P4)",3.0);
 NACT("3.1 Funciones (AA P4)",3.0);
 NACT("3.2 Cadenas (AD T)",1.5);
 NACT("3.2 Cadenas (AA T)",1.5);
 NACT("3.2 Cadenas (AD P5)",4.5);
 NACT("3.2 Cadenas (AA P5)",1.0);
 //NACT("U.T. III MANEJO DE FUNC0IONES Y CADENAS",0.0);

 //NACT("U.T. IV MANEJOS DE APUNTADORES Y ESTRUCTURAS",0.0);
 NACT("4.1 Apuntadores y variables (AD T)",1.5);
 NACT("4.1 Apuntadores y variables (AA T)",1.5);
 //NACT("4.1 Apuntadores y variables (AD P6)",5.0);
 NACT("4.1 Apuntadores y variables (AD P6)",4.0);
 NACT("4.1 Apuntadores y variables (AA P6)",1.5);
 NACT("4.2 Estructuras (AD T)",1.5);
 NACT("4.2 Estructuras (AA T)",1.5);
 //NACT("4.2 Estructuras (AD P7)",5.0);
 NACT("4.2 Estructuras (AD P7)",4.0);
 NACT("4.2 Estructuras (AA P7)",2.0);
 //NACT("U.T. IV MANEJOS DE APUNTADORES Y ESTRUCTURAS",0.0);
 //NACT("U.T. IV MANEJOS DE APUNTADORES Y ESTRUCTURAS",19.5);

 //NACT("U.T. V MANEJO DE ARCHIVOS Y PUERTOS",11.0);
 NACT("5.1 Puertos (serie y paralelo) (AD T)",0.5);
 NACT("5.1 Puertos (serie y paralelo) (AA T)",1.0);
 NACT("5.1 Puertos (serie y paralelo) (AD P8)",3.0);
 NACT("5.2 Archivos (AD T)",1.0);
 NACT("5.2 Archivos (AA T)",1.0);
 NACT("5.2 Archivos (AD P9)",4.5);
 //NACT("U.T. MANEJO DE ARCHIVOS Y PUERTOS",11.0);
}

