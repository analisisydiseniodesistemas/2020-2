/**ProbYEst_2022_2_ICI.cpp*/
#include <iostream>
#include <vector>
using namespace std;
#include <stdio.h>
#include <string.h>  /*strcmp()*/
#define NDEBUG
#include <assert.h>
#ifdef USANDO_WINDOWS
#include <windows.h>
#endif // USANDO_WINDOWS
#include "../CommonFiles/Calendario.h"
#include "../CommonFiles/Fecha.h"
#include "../CommonFiles/Dia.h"
#include "../CommonFiles/Actividad.h"
#include "../CommonFiles/Asignacion.h"
//#include "../CommonFiles/AdA.h"
#include <util.h> //add -I<proper directory>
                  //in your make file
//Project->Properties, Projects Build Options
//Search directories
#include <DiaTiempo.h>//add -I<proper directory>
                      //in your make file
void
init_tdt(vector<Dia*> VDDC,
         vector<DiaTiempo> dt,
         Calendario *CalYEAR);
void init_vdd(vector<DiaTiempo> dt,vector<string>& VDD);
void init_classroom_themes(vector<Actividad*>&);
void fill_vector_v(vector<Dia*>&,vector<Dia*>&,int,int);
void manage_IO(int argc,char *argv[],vector<Dia*> VDDC);
vector<Dia*> get_VDDC(Calendario *CalYEAR,
                      Fecha f1,Fecha f2,
                      vector<Dia*> vdnl,
                      vector<DiaTiempo> dt);

int main(int argc,char *argv[])
{
 cout << "PROBABILIDAD Y ESTADISTICA" << endl;
 Calendario *Cal2022 = new Calendario(2022);
 Fecha f1(1,3,2022); /*1 de marzo de 2022 */
 Fecha f2(16,7,2022); /*30 de junio de 2022 */
 /*Se indican los d\'ias de la semana que hay clases
   de la UA y las horas de clase en ese d\'ia*/
 vector<DiaTiempo> dia_tiempo;
 dia_tiempo.push_back(DiaTiempo("Lunes",2.0));
 dia_tiempo.push_back(DiaTiempo("Mi\\'ercoles",2.0));

 /*construir un vector de apuntadores a Dias no laborables*/
 vector<Dia*> vdnl;
 vdnl.push_back(new Dia(new Fecha(7,2,2022)));/*7 febrero 2022*/
 vdnl.push_back(new Dia(new Fecha(21,3,2022)));/*21 marzo 2022*/
 vdnl.push_back(new Dia(new Fecha(5,5,2022)));/*5 mayo 2022*/
 vdnl.push_back(new Dia(new Fecha(10,5,2022)));/*10 mayo 2022*/

 vector<Dia*> VDDC=get_VDDC(Cal2022,f1,f2,vdnl,dia_tiempo);
 /*Se necesita crear las actividades/temas a asignar en los
  dias de clase de teor\'{i}a disponibles. Se usa usa constructor de Actividad
  pasando el nombre del Tema y la duracion del Tema/Actividad en horas.*/
 vector<Actividad*> VDA;
 init_classroom_themes(VDA);/*Create this function properly*/
 /*Por ultimo se hace la planeacion pasando el vector de dias de
  clase y el vector de actividades*/
 Cal2022->planear(VDDC, VDA);
 /*Se imprime en pantalla los dias a planear con los temas
   correspondientes por dia de clase entre las fechas
   f1 y f2.*/
 manage_IO(argc,argv,VDDC);
#ifdef USANDO_WINDOWS
 SYSTEM_INFO si;
 //GetNativeSystemInfo(&si);
 GetSystemInfo(&si);
 printf("Number of Logical Processors: %d\n", (int)si.dwNumberOfProcessors);
 printf("Page size: %d Bytes\n", (int)si.dwPageSize);
 printf("Processor Mask: 0x%p\n", (PVOID)si.dwActiveProcessorMask);
 printf("Minimum process address: 0x%p\n", si.lpMinimumApplicationAddress);
 printf("Maximum process address: 0x%p\n", si.lpMaximumApplicationAddress);
#endif // USANDO_WINDOWS
 return 0;
}/*end main()*/


void manage_IO(int argc,char *argv[],vector<Dia*> VDDC){
 if(argc==1){
   cout<<"Los dias a planificar son:"<<endl;
   for (unsigned int i = 0;i<VDDC.size();i++) {
     cout<<*VDDC[i]<<endl;
   }
 }else if(argc==3){
   int Fi,Ff;
   Fi=atoi(argv[1]);
   Ff=atoi(argv[2]);
   vector<Dia*> v;
   fill_vector_v(VDDC,v,Fi,Ff);
   cout<<"D\\'{i}as a planificar\n";
   for (unsigned int i = 0;i<v.size();i++) {
     cout<<*v[i]<<endl;
   }
 }else if(argc>3){
    cout<<"FORMA DE USO:";
    printf("%s <yyyymmdd> YYYYMMDD\n",argv[0]);
 }
}
