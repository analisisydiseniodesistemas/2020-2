#include <iostream>
#include "./include/Cuadro.h"
#include "./include/Circulo.h"

using namespace std;

int main()
{
    std::cout << "FIGURAS GEOMETRICAS" << endl;
    Cuadro C1(20.0,15.0);
    Circulo S1(10.0);
    std::cout<<C1;
    std::cout<<S1;
    return 0;
}/*end main()*/
