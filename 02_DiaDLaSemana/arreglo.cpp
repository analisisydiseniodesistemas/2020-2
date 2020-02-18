#include <iostream>
using namespace std;

int main(){
//char nm[3]; /* nm[0], nm[1], nm[2] */
//nm[0]='A';
//nm[1]='B';
//nm[2]='C';
char nm[]={'A','B','C'}; /*extension*/ 
cout<<'A'<<'B'<<'C'<<"\n";
//cout<<nm[0]<<nm[1]<<nm[2]<<"\n";
  cout<<nm[0];
  cout<<nm[1];
  cout<<nm[2];
cout<<"\n";
for(int i=0;i<3;i=i+1){
  cout<<nm[i];
}
cout<<"\n";

return 0;
}/*end main()*/

