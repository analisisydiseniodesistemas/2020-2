/**main2.cpp*/
#include <iostream>
#include <stdio.h>

//#define NDEBUG
#include <assert.h>
#include "main.h"

using namespace std;
uint bucket[256];
uint *BUCKET;

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
    vector<string> vs;         /*vector string*/
    string stringsa=string(str);
    fill_string_vec(stringsa,vs);
    printf("/******************************************/\n");
    //print_vector_string(vs);

    StringYuint *syu_Pt=new StringYuint[vs.size()];
    for(uint index=0;index<vs.size();index++)
    {
      syu_Pt[index]=StringYuint(vs[index]);
    }
    BUCKET=new uint[vs.size()+1];
    for(uint index=0;index<=vs.size();index++)
    {
      BUCKET[index]=0;
    }
    contar_palabras(stringsa,syu_Pt,vs);
    printf("/******************************************/\n");
    for(uint index=0;index<vs.size();index++)
    {
      printf("%-15s %3d\n",
             &(syu_Pt[index].palabra[0]),
             BUCKET[syu_Pt[index].I]);
    }

    return 0;
}/*end main()*/


void contar_palabras(string line,
                     StringYuint *syu_pt,
                     vector<string> string_vec)
{
  uint i,inic=-1,fin;
  std::string str_tmp;
  /**detect if string is fill of ' 's*/
  for(i=0;i<line.size();i++)
  {
    if(line[i]==' ')
        continue;
    inic=i;
    break;
  }
  if(inic<0)
    goto out;
  while(i<=line.size()-1)
  {
    for(i=inic;i<line.size();i++)
    {
      if(line[i]==' ')
        continue;
      inic=i;
      break;
    }
    for(i=inic;i<line.size();i++)
    {
      if((' '==line[i])||('\0'==line[i])||(i==(line.size()-1))){
         fin=i;
         str_tmp=line.substr(inic,fin-inic+1);
        
         if(str_tmp.size()>=2){
         /**Quitar coma --si la hay--*/
         if(str_tmp[str_tmp.size()-2]==',')
            str_tmp=str_tmp.substr(0,str_tmp.size()-2);
         /**Quitar punto y coma --si lo hay--*/
         if(str_tmp[str_tmp.size()-2]==';')
            str_tmp=str_tmp.substr(0,str_tmp.size()-2);
         /**Quitar punto --si lo hay--*/          
         if(str_tmp[str_tmp.size()-2]=='.')
            str_tmp=str_tmp.substr(0,str_tmp.size()-2);
         }
         if(is_included(str_tmp,string_vec)){
           BUCKET[mapa(str_tmp,syu_pt,string_vec.size())]++;
         }
         inic=fin+1;
         break;
       }
     }/*end for()*/ 
  }/*end while()*/

out:
    return;
}/*end contar_palabras()*/

