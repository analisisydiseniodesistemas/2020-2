/**mcd.cpp - Euclides algorithm
 */
#include <stdlib.h>  /*abs()*/
#include <iostream>
using namespace std;

unsigned int
mcd(unsigned int N,unsigned int D)
{
  unsigned int R;
  for(;(R=D%N);){
    D=N;   
    N=R;
  }
  return N;
}

/**Simplifica la fracci\'on con numerador
 * frac[0] y denominador frac[1]
 * pre:frac[1] debe ser diferente de 0.
 */ 
void
simplificar(int frac[2])
{
  unsigned int intMCD=mcd(abs(frac[0]),abs(frac[1]));
  frac[0]=frac[0]/intMCD;
  frac[1]=frac[1]/intMCD; 
}

void 
show_seconds_like_mins_plus_seconds(unsigned int sec) 
{
  cout<<sec<<" segundos equivalen a "<<sec/60
      <<" minutos con "<<sec%60<<" segundos.\n";
}


