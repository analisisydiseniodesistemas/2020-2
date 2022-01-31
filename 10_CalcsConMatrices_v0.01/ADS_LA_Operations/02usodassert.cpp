#include <iostream> 
#include <cassert> 
#include <cmath>

int main(int argc, char* argv[])
{
  double a;
  std::cout << "Enter a non-negative number\n";
  std::cin >> a;
  //Run without assertion: assert(a >= 0.0);
  std::cout << "The square root of "<< a;
  std::cout << " is " << sqrt(a) << "\n";
  return 0;
}


