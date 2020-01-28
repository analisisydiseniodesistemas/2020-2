/**../CommonFiles/util.cpp
 */
#include <iostream>
#include <vector>
using namespace std;
#include "../CommonFiles/Calendario.h"
#include "../CommonFiles/Fecha.h"
extern char MES[][32];
void
printf_fecha(Fecha *fPt,Calendario *Cal_Greg)
{
    //printf("%15s %2d de %7s de %4d\n",Cal_Greg->get_day_name(fPt)
    printf("%15s %2d de %7s de %4d\n",Cal_Greg->get_day_name(fPt)
                                     ,fPt->d
                                     ,MES[fPt->m]
                                     ,2019);
}
