/** main.h*/
#ifndef CALCULAR
#define CALCULAR_H
struct Calcular {
  double radio;
  double area;
  double perimetro;
  static unsigned int count;

  void iniciar();
  void entradaDatos();
  void salidaDatos();
  Calcular();
  Calcular(double r);
};
#endif // CALCULAR_H
