/**CdD.cpp
 * V&G A possible sequence of callings to the functions in this file
 * is:
 * 1 string mykalend=get_kalend(hoy.m,hoy.a);//where hoy is a struct Fecha
 *                                           //properly initialized
 * 2 init_cdd(mykalend);
 * 3 print_ccd();
 */
#include <iostream>
using namespace std;
void init_NM(unsigned int);
extern string DIA[];
extern unsigned int NM[];

static string cdd[6][7];  /*celdas de dias*/
struct StringInt{
  string DayName;
  unsigned int Pos;       /*It represents kalend (day 1 of month) position*/
};
static struct StringInt DayNameToPos[7]={   /*DayName To Position*/
  {"Domingo",0},                  /**/
  {"Lunes",1},
  {"Martes",2},
  {"Miercoles",3},
  {"Jueves",4},
  {"Viernes",5},
  {"Sabado",6}
};

void
init_cdd(string kalend,unsigned int numDMes)
{
  char c=0;
  int index=-1;
  char str[4];
  cdd[0][0]=" DO";
  cdd[0][1]=" LU";
  cdd[0][2]=" MA";
  cdd[0][3]=" MI";
  cdd[0][4]=" JU";
  cdd[0][5]=" VI";
  cdd[0][6]=" SA";
  for(c=0;c<=6;c++){
    if(DayNameToPos[c].DayName==kalend){
      index=c;
      break;
    }
  }
  for(c=0;c<=6;c++){
    if(c<index){
      cdd[1][c]="   ";
    }else{
      sprintf(str,"  %d",1+c-index);
      cdd[1][c]=string(str);
    }
  }
  unsigned int kalend2non=1+c-index;
  unsigned int fil; /*fila*/
  int DdM[]={  /*Dias del Mes*/
    31, /*enero*/
#ifdef LEAP_YEAR
    29, /*febrero*/
#else
    28, /*febrero*/
#endif /*LEAP_YEAR*/
    31,30,31,30,31,31,30,31,30,31 };
  for(fil=2;fil<6;fil++){
    for(c=0;c<=6;c++){
        if(1+kalend2non+c<10){
          sprintf(str,"  %d",1+kalend2non+c);
        }else{ 
          sprintf(str," %d",1+kalend2non+c);
        }
        cdd[fil][c]=string(str);
    }
    kalend2non=1+kalend2non+c;
  }
}/*end init_cdd()*/

string 
get_kalend(unsigned int numDMes,unsigned int year)
{
  string kal;
  init_NM(year); /*initialize the Magic Numbers array unsigned kNM[13]*/
  kal=DIA[(1+7-NM[numDMes])%7];
  return kal;
}/*end get_kalend()*/

void
print_cdd()  /*print celda de dias*/
{
  for(unsigned int i=0;i<6;i++){
    for(unsigned int j=0;j<7;j++){
      cout<<cdd[i][j];
    }
    cout<<"\n";
  }
}

