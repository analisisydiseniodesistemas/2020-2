/**PyE_data.cpp*/
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
  {"Martes",""},
  {"Mi\\'ercoles",""},
  {"Jueves",""},
  {"Viernes",""},
  {"S\\'abado",""},
  {"Domingo",""}
};

void
init_classroom_themes(vector<Actividad*>& VDA)
{
  NACT("U.T. I TEORIA DE PROBABILIDAD",1.0);
  NACT("I.A CONCEPTO BASICO DE PROBABILIDAD",1.0);
  NACT("I.B CONCEPTO DE EVENTO",1.0);
  NACT("I.C COMBINACIONES DE EVENTOS",3.0);
  NACT("I.D PROBABILIDAD CONDICIONAL",1.0);
  NACT("I.E TEOREMA DE BAYES",1.0);
  NACT("I.F TECNICAS DE CONTEO",1.0);
  NACT("U.T. II VARIABLES ALEATORIAS",1.0);
  NACT("II.A VARIABLES ALEATORIAS DISCRETAS",4.0);
  NACT("II.B VARIABLES ALEATORIAS CONTINUAS",2.0);
  NACT("II.C VALOR ESPERADO DE UNA VARIABLE \
ALEATORIA",2.0);
  NACT("II.D PROBLEMAS DE VALOR ESPERADO DE \
LA VARIABLE ALEATORIA CONTINUA",2.0);
  NACT("II.E VARIANZA DE UNA VARIABLE \
ALEATORIA DISCRETA",1.0);
  NACT("II.F PROBLEMAS, VARIANZA DE LA VARIABLE \
ALEATORIA CONTINUA",1.0);
  NACT("REPASO PREVIO A EVALUACION 1",2.0);
  NACT("PRIMER EXAMEN PARCIAL",2.0);
  NACT("REVISION DEL EXAMEN",0.5);
  //NACT("U.T. III DISTRIBUCIONES DISCRETAS",7.0);
  NACT("U.T. III DISTRIBUCIONES DISCRETAS",1.0);
  NACT("III.A DISTRIBUCION DE PROBABILIDAD \
DE BERNOULLI",1.0);
  NACT("III.B DISTRIBUCION DE PROBABILIDAD \
BINOMIAL",1.0);
  NACT("III.C DISTRIBUCION DE PROBABILIDAD \
GEOMETRICA",1.0);
  NACT("III.D DISTRIBUCION DE PROBABILIDAD \
BINOMIAL NEGATIVA",1.0);
  NACT("III.E DISTRIBUCION DE PROBABILIDAD \
HIPERGEOMETRICA",1.0);
  NACT("III.F DISTRIBUCION DE PROBABILIDAD \
POISSON",1.0);
  //NACT("U.T. IV DISTRIBUCIONES CONTINUAS",4.0);
  NACT("U.T. IV DISTRIBUCIONES CONTINUAS",0.5);
  NACT("IV.A DISTRIBUCION UNIFORME",1.5);
  NACT("IV.B DISTRIBUCION EXPONENCIAL",2.0);
  //NACT("U.T. V DISTRIBUCION NORMAL",5.0);
  NACT("U.T. V DISTRIBUCION NORMAL",0.5);
  NACT("V.A USO DE LA DISTRIBUCION NORMAL \
EN EL CALCULO DE PROBABILIDAD",2.5);
  NACT("V.B DISTRIBUCIONES RELACIONADAS CON \
DISTRIBUCION NORMAL",2.0);
  NACT("REPASO PREVIO A EVALUACION 2",1.5);
  NACT("SEGUNDO EXAMEN PARCIAL",2.0);
  NACT("REVISION DEL EXAMEN",0.5);
  //NACT("U.T. VI ESTADISTICA DESCRIPTIVA",10.0);
  NACT("U.T. VI ESTADISTICA DESCRIPTIVA",0.5);
  NACT("VI.A POBLACION, MUESTRA Y MUESTRA \
ALEATORIA",1.5);
  NACT("VI.B PRESENTACION DE DATOS",2.0);
  NACT("VI.C ESTADISTICOS MUESTRALES DE \
TENDENCIA CENTRAL",3.0);
  NACT("VI.C ESTADISTICOS MUESTRALES DE \
DISPERSION",3.0);
  //NACT("U.T. VII ESTIMACION ESTADISTICA Y
  //DISTRIBUCIONES DE MUESTREO",3.0);
  NACT("U.T. VII ESTIMACION ESTADISTICA \
Y DISTRIBUCIONES DE MUESTREO",0.5);
  NACT("VII.A ESTIMADORES PUNTUALES",0.5);
  NACT("VII.B PROPIEDADES DE LOS ESTIMADORES \
PUNTUALES",1.0);
  NACT("VII.C DISTRIBUCIONES DE MUESTREO",1.0);
  //NACT("U.T. VIII INFERENCIAS EN UNA POBLACION",2.0);
  NACT("U.T. VIII INFERENCIAS EN UNA \
POBLACION",0.5);
  NACT("VIII.A INTERVALOS DE CONFIANZA",0.5);
  NACT("VIII.B PRUEBAS DE HIPOTESIS",1.0);
  //NACT("U.T. IX INFERENCIAS DE DOS
  //POBLACIONES",2.0);
  NACT("U.T. IX INFERENCIAS DE DOS \
POBLACIONES",0.5);
  NACT("IX.A INTRODUCCION",0.5);
  NACT("IX.B ANALISIS DE MUESTRAS \
INDEPENDIENTES",1.0);
  NACT("REPASO PREVIO A EVALUACION 3",0.5);
  NACT("TERCER EXAMEN PARCIAL",2.0);
  NACT("REVISION DEL EXAMEN",0.5);
  NACT("REPASO PREVIO A EVALUACION FINAL",1.5);
  NACT("EXAMEN FINAL",2.0);
  NACT("REVISION DEL EXAMEN",0.5);
}/*end init_classroom_themes()*/


