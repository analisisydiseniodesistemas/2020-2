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
    char sa[]="Sapere aude";
    string stringsa=string(sa);

    vector<string> vs;         /*vector string*/
    cout<<stringsa<<"\n";
    fill_string_vec(stringsa,vs);
    print_vector_string(vs);

    stringsa="Assinus,  assinum  a fricat";
    vs.clear();
    fill_string_vec(stringsa,vs);
    printf("/******************************************/\n");
    print_vector_string(vs);

    char str[]="Qui est in caelis, santificatur nomen tuum,\
 adveniat regnum tuum, fiat voluntas tua, cicut in terra et in caelo";
    printf("%s\n",str);

    for(i=0;i<NELEM(str);i++){
        bucket[(int)str[i]]++;
    }
    printf("suma=%d\n",selem(bucket,NELEM(bucket)));
#ifdef ADS_20202_1
    printf("Checking macro ADS_20202_1 definition\n");
    assert(1==0);
#endif // ADS_20202_1

    return 0;
}/*end main()*/


