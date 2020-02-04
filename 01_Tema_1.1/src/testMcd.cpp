/**testMcd.cpp
 */
#include <iostream>
using namespace std;
#include <stdio.h>

unsigned int mcd(unsigned int,unsigned int);

int
main(int argc,char *argv[])
{
  unsigned int n,d,m;
  if(argc<3){
    cout<<"FORMA DE USO:";
    printf("%s <Numerador> <Denominador>\n",argv[0]);
    return 1;
  }
  n=atoi(argv[1]);  /*ascii to integer*/
  d=atoi(argv[2]);  /*ascii to integer*/
  m=mcd(n,d);
  cout<<"El m.c.d. de "<<n<<" y "<<d<<" es "<<m<<"\n";

  return 0;
}/*end main()*/

