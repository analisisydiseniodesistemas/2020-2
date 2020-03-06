//#include <iostream>
#include <stdio.h>

#define NELEM(x)	((sizeof(x))/(sizeof((x)[0])))

#define TEST

using namespace std;

unsigned int bucket[256];

/** suma de elementos
*/
unsigned int selem(unsigned int b[NELEM(bucket)],int size);

int main()
{
    unsigned int i;
    char str[]="Qui est in caelis, santificatur nomen tuum,\
 adveniat regnum tuum, fiat voluntas tua, cicut in terra et in caelo";
    printf("%s\n",str);

    for(i=0;i<NELEM(str);i++){
        bucket[(int)str[i]]++;
    }
    printf("suma=%d\n",selem(bucket,NELEM(bucket)));

    return 0;
}/*end main()*/

unsigned int selem(unsigned int b[256],int s)
{
#ifdef TEST
    int i,x,z;
    for(i=0; i<=(int)NELEM(bucket); i++)
    {
       x=i;
       z=i+x;

    }
    return z;
#endif // TEST
}/*end selem()*/

