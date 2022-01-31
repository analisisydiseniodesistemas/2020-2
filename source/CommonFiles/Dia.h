//Dia.h
#ifndef DIA_H
#define DIA_H
#include <iostream>
#include <ostream>
#include <vector>
using std::string;
using std::vector;
using std::ostream;
using std::endl;

struct Fecha;
class Asignacion;
class Dia{
public:
  Fecha *f;
  float TDT;        /*Tiempo Disponible Total*/
  float TD;         /*Tiempo Disponible*/
  std::string lugar;/*V&G S106,C1; Friday 2020.01.31*/
  std::string horario;/*V&G 14:30-16:00,16:00-17:30; Friday 2020.01.31*/
  vector<Asignacion*> A; /*Los temas planificados para el Dia*/
  Dia(){ }
  Dia(Fecha* fPt):f(fPt),lugar(set_lugar()),
                  horario(set_horario()){ }/*friday 2020.01.31*/
  void set_TDT(float tdt);
  friend ostream& operator<<(ostream& out,Dia& D);
private:
  std::string set_lugar();  /*friday 2020.01.31,2020.02.11*/
  std::string set_horario();  /*friday 2020.01.31*/
};//end class Dia
#endif /*DIA_H*/
