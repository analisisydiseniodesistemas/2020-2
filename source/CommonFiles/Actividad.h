//Actividad.h
#ifndef ACTIVIDAD_H
#define ACTIVIDAD_H
class Dia;
class Actividad{
public:
  string nombre;         /*nombre de la actividad*/
  string ACT_DE_APR;	/*ACTividad DE APRendizaje*/
  float TRT;             /*Tiempo Requerido Total:tiempo en hrs que debe durar la actividad*/
  float TR;              /*Tiempo Requerido*/

static float ta;         /*tIEMPO DE aCTIVIDADES*/
  void set_TRT(float TRT);
  vector<Dia*> intervalo;/*Dias durante los cuales se realizara la Actividad*/
  Actividad(string name,float trt):nombre(name),
	  ACT_DE_APR(""),TRT(trt),TR(trt){ta+=trt;}
  Actividad(string name,string act_dapr,float trt):nombre(name),
	  ACT_DE_APR(act_dapr), TRT(trt), TR(trt) {ta+=trt;}
};//end class Actividad
#endif /*ACTIVIDAD_H*/
