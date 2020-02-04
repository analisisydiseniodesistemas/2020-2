/**mcd.cpp - Euclides algorithm
 */
unsigned int
mcd(unsigned int N,unsigned int D)
{
  unsigned int tmp,R;
  for(;(R=D%N);){
    D=D/N;   /*Divisi\'on entera*/
    N=R;
  }
  return N;
}

