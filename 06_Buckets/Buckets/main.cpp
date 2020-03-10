//#include <iostream>
#include <stdio.h>
//#define NDEBUG
#include <assert.h>
#include "main.h"
using namespace std;
unsigned int bucket[256];
int main()
{
    unsigned int i;
    char sa[]="Sapere aude";
    string stringsa=string(sa);
    vector<string> vs;         /*vector string*/
    cout<<stringsa<<"\n";
    fill_string_vec(stringsa,vs);
    print_vector_string(vs);
    assert(1==0);
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
    int i,suma=0;//,x,z;
    for(i=0; i<=(int)NELEM(bucket); i++)
    {
       suma=suma+b[i];
    }
    return suma;
}/*end selem()*/

