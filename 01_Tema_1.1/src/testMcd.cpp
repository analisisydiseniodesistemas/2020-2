/**testMcd.cpp
 */
#include <iostream>
using namespace std;
#include <stdio.h>

#ifndef SECONDS_TO_MINS_PLUS_SECONDS
unsigned int mcd(unsigned int,unsigned int);
void simplificar(int[2]);
#else
#include <mcd.h> /*Add -I./ at your make file*/
#endif /*SECONDS_TO_MINS_PLUS_SECONDS*/

int
main(int argc,char *argv[])
{
  unsigned int n,d,m;
  int N,D;
  if(argc<3){
    cout<<"FORMA DE USO:";
    printf("%s <Numerador> <Denominador>\n",argv[0]);
    return 1;
  }
  N=atoi(argv[1]);  /*ascii to integer*/
  D=atoi(argv[2]);  /*ascii to integer*/
  n=abs(N);
  d=abs(D);
  m=mcd(n,d);
  cout<<"El m.c.d. de "<<n<<" y "<<d<<" es "<<m<<"\n";
#ifdef USING_SIMPLIFICAR
  int fraccion[2];
  fraccion[0]=n;
  fraccion[1]=d;
  simplificar(fraccion);
  cout<<"\n"<<N<<"/"<<D<<" = "<<fraccion[0]<<"/"<<fraccion[1]<<"\n";
#endif /*USING_SIMPLIFICAR*/

#ifdef SECONDS_TO_MINS_PLUS_SECONDS
  cout<<"\nEQUIVALENCIA DE SEGUNDOS A MINUTOS MAS SEGUNDOS:\n";
  show_seconds_like_mins_plus_seconds(500);
#endif /*SECONDS_TO_MINS_PLUS_SECONDS*/

  return 0;
}/*end main()*/

