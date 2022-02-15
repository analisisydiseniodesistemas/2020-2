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
  {"Lunes","Aula presencial"},
  {"Martes",""},
  {"Mi\\'ercoles","Aula presencial"},
  {"Jueves",""},
  {"Viernes",""},
  {"S\\'abado",""},
  {"Domingo",""}
};
std::string day_horario[7][2]={
  {"Lunes","07:30-09:30"},
  {"Martes",""},
  {"Mi\\'ercoles","07:30-09:30"},
  {"Jueves",""},
  {"Viernes",""},
  {"S\\'abado",""},
  {"Domingo",""}
};

void
init_classroom_themes(vector<Actividad*>& VDA)
{
 NACT("U.T. I TEORIA DE PROBABILIDAD",0.5);
 NACT("I.A Probabilidad",0.5);
 NACT("I.B Eventos",1.0);
 NACT("I.C Combinaciones de Eventos ",2.0);
 NACT("I.D Probabilidad Condicional",2.0);
 NACT("I.E Teorema de Bayes",1.0);
 NACT("I.F T\\'ecnicas de Conteo",1.0);

 NACT("U.T. II VARIABLES ALEATORIAS",0.5);
 NACT("II.A Variables Aleatorias Discretas",1.5);
 NACT("II.B Variables Aleatorias Continuas",2.0);
 NACT("II.C Valor Esperado de una Variable Aleatoria",2.0);
 NACT("II.D Problemas. Valor Esperado de una Variable Aleatoria Continua",2.0);
 NACT("II.E Varianza de una Variable Aleatoria Discreta",1.0);
 NACT("II.F Problemas. Varianza de la Variable Aleatoria Continua",3.0);
 NACT("PRIMERA EVALUACION PARCIAL",2.0);
 NACT("REVISION DE LA PRIMERA EVALUACION PARCIAL",0.5);

 NACT("U.T. III DISTRIBUCIONES DISCRETAS",0.5);
 NACT("III.A Distribuci\\'on de Probabilidad de Bernoulli",1.0);
 NACT("III.B Distribuci\\'on de Probabilidad Binomial",1.0);
 NACT("III.C Distribuci\\'on de Probabilidad Geom\\'etrica",1.0);
 NACT("III.D Distribuci\\'on de Probabilidad Binomial Negativa",1.0);
 NACT("III.E Distribuci\\'on Hipergeom\\'etrica",1.0);
 NACT("III.F Distribuci\\'on Poisson",1.0);

 NACT("U.T. IV DISTRIBUCIONES CONTINUAS",0.5);
 NACT("IV.A Distribuci\\'on Uniforme",1.5);
 NACT("IV.B Distribuci\\'on Exponencial",2.0);

 NACT("U.T. V LA DISTRIBUCION NORMAL",0.5);
 NACT("V.A Uso de la distribuci\\'on normal en el c\\'alculo de probabilidad",3.5);
 NACT("V.B Distribuciones relacionadas con la distribuci\\'on normal",1.0);
 NACT("SEGUNDA EVALUACION PARCIAL",2.0);
 NACT("REVISION DE LA SEGUNDA EVALUACION PARCIAL",0.5);

 NACT("U.T. VI ESTADISTICA DESCRIPTIVA",0.5);
 NACT("VI.A Poblaci\\'on, muestra y muestra aleatoria",2.0);
 NACT("VI.B Presentaci\\'on de datos",2.0);
 NACT("VI.C Estad\\'isticos muestrales",3.0);
 NACT("U.T. VII ESTIMACION ESTADISTICA Y DISTRIBUCIONES DE MUESTREO",0.5);
 NACT("VII.A Estimadores puntuales",1.5);
 NACT("VII.B Propiedades de los estimadores puntuales",1.0);
 NACT("VII.C Distribuciones de muestreo",1.0);

 NACT("U.T. VIII INFERENCIAS EN UNA POBLACION",0.5);
 NACT("VIII.A Intervalos de confianza",1.5);
 NACT("VIII.B Pruebas de hip\\'otesis",2.0);

 NACT("U.T. IX  INFERENCIAS DE DOS POBLACIONES",0.5);
 NACT("IX.A Introducci\\'on",1.5);
 NACT("IX.B An\\'alisis de muestras independientes",2.0);

 NACT("TERCERA EVALUACION PARCIAL",2.0);
 NACT("REVISION DE LA TERCERA EVALUACION PARCIAL",2.0);

 NACT("EVALUACION FINAL",2.0);
 NACT("REVISION DE LA EVALUACION FINAL",0.5);
}
