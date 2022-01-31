/**TestConversion.cpp
 */
#include <iostream>
#include <vector>
#include <Conversion.h>

#ifdef DETECT_INHERITANCE
class A{ };
class B : public A{ };
#endif /*DETECT_INHERITANCE*/

int main()
{
   using namespace std;
   cout
      << Conversion<double, int>::exists << ' '
      << Conversion<char, char*>::exists << ' '
      << Conversion<size_t, vector<int> >::exists << ' ';
#ifdef DETECT_INHERITANCE
  if(SUPERSUBCLASS(A,B)){
    cout<<"\nClass A is an unambiguous base of class B\n";
  }
  if(SUPERSUBCLASS_STRICT(A,B)){
    cout<<"\nClass A is an unambiguous base of class B\n";
  }
#endif /*DETECT_INHERITANCE*/

  return 0;
}/*end main()*/ 

