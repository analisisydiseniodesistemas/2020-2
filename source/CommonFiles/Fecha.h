#ifndef FECHA_H
#define FECHA_H
extern int anio;

typedef struct Fecha{
  int d;/*dia*/
  int m;/**mes, 0 enero, 1 febrero, 2 marzo, etc.
         * Starting from october 29, 2019:
         * 1 for january, 2 for february, 3 for march etcetera */
  int a;/*a\~no*/
  Fecha():d(0),m(0),a(anio){ }
  Fecha(int a,int b):d(a),m(b),a(anio){ }
  Fecha(int x,int y,int z):d(x),m(y),a(z){ } /*2019.10.20*/
  /*sobrescritura (sobrecarga/overloading) del operador ==*/
  /*overloading of the operator ==*/ /*2020.01.27*/
  bool operator==(Fecha& f){
    return ((d==f.d)&&(m==f.m));
  }
} Fecha;
void printf_fecha(Fecha *,Calendario *);
#endif /*FECHA_H*/
