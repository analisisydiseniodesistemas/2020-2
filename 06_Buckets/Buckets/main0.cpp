/**main0.cpp*/
#include <iostream>
#include <stdio.h>

#define NDEBUG
#include <assert.h>
#include "main.h"

using namespace std;
unsigned int bucket[256];

int main(int argc,char *argv[])
{
    uint i;
    char str[]="Pater noster, qui es in caelis, \
 santificetur nomen Tuum, adveniat Regnum Tuum, \
 fiat voluntas tua, sicut in caelo et in terra. \
 Panem nostrum cotidianum da nobis hodie, \
 et dimitte nobis debita nostra, \
 sicut et nos dimittimus debitoribus nostris; \
 et ne nos inducas in tentationem,\
 sed libera nos a malo";
    printf("%s\n",str);

    for(i=0;i<NELEM(str);i++)
    {
        bucket[(int)str[i]]++;
    }
    printf("suma=%d\n",selem(bucket,NELEM(bucket)));

    printf("%-4s %-6s\n","Char","Amount");
    for(i='A';i<='Z';i++)
    {
        if(bucket[i])
            printf("%c %5d\n",i,bucket[i]);
    }
    for(i='a';i<='z';i++)
    {
        if(bucket[i])
            printf("%c %5d\n",i,bucket[i]);
    }
#ifdef CPPBUILDER
	getchar();
#endif
    return 0;
}/*end main()*/

