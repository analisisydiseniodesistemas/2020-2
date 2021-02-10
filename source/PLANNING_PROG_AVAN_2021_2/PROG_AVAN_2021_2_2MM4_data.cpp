/**PROG_AVAN_2021_2_2MM4_data.cpp*/
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
  {"Lunes",""},
  //{"Martes","11:30-13:30"},
  {"Martes",""},
  {"Mi\\'ercoles","11:30-13:00"},
  {"Jueves",""},
  //{"Viernes","11:30-13:30"},
  {"Viernes","11:30-13:00"},
  {"S\\'abado",""},
  {"Domingo",""}
};

void
init_classroom_themes(vector<Actividad*>& VDA)
{
 //NACT("U.T. I PROGRAMACION ORIENTADA A OBJETOS",18.0);
 NACT("U.T. I PROGRAMACION ORIENTADA A OBJETOS",0.25);
 NACT("1.1 Clases (AD P1 CLASES)",1.75);
 NACT("1.1 Clases (AA P1 CLASES)",2.0);
 NACT("1.2 Objetos (AD P2 OBJETOS)",0.5);
 NACT("1.2 Objetos (AA P2 OBJETOS)",3.0);
 NACT("1.3 Herencia (AD P3 HERENCIA)",1.0);
 NACT("1.3 Herencia (AA P3 HERENCIA)",2.5);
 NACT("1.4 Polimorfismo (AD P4 POLIMORFISMO)",1.0);
 NACT("1.4 Polimorfismo (AA P4 POLIMORFISMO)",2.5);
 NACT("1.5 Abstracci\\'on (AD P5 ABSTRACCION)",1.0);
 NACT("1.4 Abstracci\\'on (AA P5 ABSTRACCION)",2.5);
 //NACT("U.T. I PROGRAMACION ORIENTADA A OBJETOS",0.0);

 NACT("U.T. II INTERFAZ GRAFICA DE USUARIO (GUI)",0.25);
 NACT("2.1 Ambiente de desarrollo \
(AD P6 AMBIENTE DE DESARROLLO)",0.25);
 NACT("2.1 Ambiente de desarrollo \
(AA P6 AMBIENTE DE DESARROLLO)",1.0);
 NACT("2.2 Controles b\\'asicos \
(AD P7 CONTROLES BASICOS)",0.5);
 NACT("2.2 Controles b\\'asicos \
(AA P7 CONTROLES BASICOS)",1.0);
 NACT("2.3 Controles avanzados \
(AD P8 CONTROLES AVANZADOS)",0.5);
 NACT("2.3 Controles avanzados \
(AA P8 CONTROLES AVANZADOS)",1.0);
 NACT("2.4 Eventos (AD P9 EVENTOS)",1.0);
 NACT("2.4 Eventos (AA P9 EVENTOS)",3.5);
 //NACT("U.T. II INTERFAZ GRAFICA DE USUARIO (GUI)",0.0);

 NACT("U.T. III PUERTOS Y COMUNICACIONES",0.25);
 NACT("3.1 Puerto serie (AD P10 COMUNICACION SERIE)",
      1.75);
 NACT("3.1 Puerto serie (AA P10 COMUNICACION SERIE)",
      5.0);
 NACT("3.2 Puerto USB (AD P11 COMUNICACION USB)",2.0);
 NACT("3.2 Puerto USB (AA P11 COMUNICACION USB)",5.0);
 NACT("3.3 Comunicaci\\'on TCP/IP (AD P12 \
COMUNICACION TCP/IP)",3.0);
 NACT("3.3 Comunicaci\\'on TCP/IP (AA P12 \
COMUNICACION TCP/IP)",4.0);
 //NACT("U.T. III PUERTOS Y COMUNICACIONES",0.0);
 //NACT("U.T. III PUERTOS Y COMUNICACIONES",21.0);

 NACT("U.T. IV ADQUISICION DE IMAGENES",0.25);
 NACT("4.1 Adquisici\\'on de im\\'agenes \
(AD P13 VISION POR COMPUTADORA)",1.75);
 NACT("4.1 Adquisici\\'on de im\\'agenes \
(AA P13 VISION POR COMPUTADORA)",4.0);
 //NACT("U.T. IV ADQUISICION DE IMAGENES",0.0);
 //NACT("U.T. IV ADQUISICION DE IMAGENES",6.0);
}

