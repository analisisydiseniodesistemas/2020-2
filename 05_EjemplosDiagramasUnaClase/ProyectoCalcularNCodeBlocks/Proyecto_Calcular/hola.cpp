#include <stdio.h>  /*scanf()*/
// number of elements in fixed-size array
#define NELEM(x) (sizeof(x)/sizeof((x)[0]))

int main(void)
{
  printf("HOLA MUNDO C\n");
  int boleta[3],tmp,i;
  printf("Ingrese los n\\'umeros de boleta: ");
  for(i=0;i<NELEM(boleta);i++){
    printf("Boleta %i: ",i+1);
    scanf("%d*%c",boleta+i);
  }
  tmp=boleta[NELEM(boleta)-1]%256;
  return tmp;
}/*end main()*/
