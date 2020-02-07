#include <stdio.h>
#include <iostream>
#define UPIITA printf("UPIITA del IPN \n")
void f();
int main(int a, char* b[]) { /*using namespace std; */ printf("%i\n",a); std::cout<<"i="<<a<<std ::endl;f();return 10; }
void f()
{
UPIITA;
}
