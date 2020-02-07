/**main.cpp
 */
#include <iostream>
using namespace std;
#include <DFecha.h>

int main(int argc,char *argv[])
{
  struct Fecha f;
  f.d=7;f.m=2;f.a=2020;
  cout<<get_string_fecha(f);
}/*end main()*/

