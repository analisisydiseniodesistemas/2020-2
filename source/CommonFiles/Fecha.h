#ifndef FECHA_H
#define FECHA_H
extern int anio;

typedef struct Fecha{
  int d;/*dia*/
  int m;/**mes, 0 enero, 1 febrero, 2 marzo, etc.
         * Starting from october 29, 2019:
         * 1 for january, 2 for february, 3 for march etcetera */
  int a;/*a\~no*/
  int F;/**F=a\times 10000+m\times 100+d; can be initialized at 
         * constructor Fecha(int x,int y,int z)*/
  Fecha():d(0),m(0),a(anio){ }
  Fecha(int a,int b):d(a),m(b),a(anio){ }
  /*2019.10.20,2020.01.28*/
  Fecha(int x,int y,int z):d(x),m(y),a(z),F(z*10000+y*100+x){ } 
  /*sobrescritura (sobrecarga/overloading) del operador ==*/
  /*overloading of the operator ==*/ /*2020.01.27*/
  bool operator==(Fecha& f){
    return ((d==f.d)&&(m==f.m));
  }
  bool operator>(Fecha& f){return (F>f.F);}
} Fecha;
void printf_fecha(Fecha *,Calendario *);
#endif /*FECHA_H*/
