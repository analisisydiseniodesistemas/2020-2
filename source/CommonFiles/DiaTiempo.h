#ifndef DIATIEMPO_H_INCLUDED
#define DIATIEMPO_H_INCLUDED

struct DiaTiempo{
 string day;
 float time;
 DiaTiempo(string dia,float tiempo):
 day(dia),time(tiempo){ }
 string get_dia(){return day;}
 float get_time(){return time;}
};/*end struct DiaTiempo*/

#endif // DIATIEMPO_H_INCLUDED
