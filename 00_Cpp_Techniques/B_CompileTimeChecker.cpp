/**B_CompileTimeChecker.cpp - It does not work as I expect. 2020.02.07
 * On the other hand: reinterpret_cast<To>(from) complains at 
 * compilation time saying something like: 
g++ -DUSANDO_MAKE B_CompileTimeChecker.cpp -o dcompileTimeChecker.exe
B_CompileTimeChecker.cpp: En la instanciación de ‘To safe_reinterpret_cast(From) [con To = char; From = void*]’:
B_CompileTimeChecker.cpp:42:49:   se requiere desde aquí
B_CompileTimeChecker.cpp:35:10: error: la conversión de ‘void*’ a ‘char’ pierde precisión [-fpermissive]
   return reinterpret_cast<To>(from);
          ^~~~~~~~~~~~~~~~~~~~~~~~~~
make: *** [Makefile:19: dcompileTimeChecker.exe] Error 1

which is proper, I guess.
 */
#ifdef USANDO_MAKE
#include <assert.h>
#include <stdlib.h>
#endif /*USANDO_MAKE*/

template<bool> struct CompileTimeChecker
{
  CompileTimeChecker(...);
};
template<> struct CompileTimeChecker<false> { };
//template<> struct CompileTimeChecker<true> { };

//(void)sizeof(CompileTimeChecker<(expr)!=0>(ERROR_##msg()));}
#define STATIC_CHECK(expr,msg) { class ERROR_##msg {}; \
struct CompileTimeChecker<(expr) != 0> CTC(ERROR_##msg()); \
}

/*end macro STATIC_CHECK*/

/**Assume that sizeof(char) < sizeof(void*). (The standard does not 
 * guarantee that this is necessarily true.) Let's see what happens 
 * when you write the following:
 */
template<class To,class From>
To safe_reinterpret_cast(From from)
{
  //STATIC_CHECK(sizeof(From)<=sizeof(To),
  STATIC_CHECK(false,
     Destination_Type_Too_Narrow);

  return reinterpret_cast<To>(from);
}

int
main(int argc,char *argv[])
{
  void *somePointer=malloc(1);
  char c=safe_reinterpret_cast<char>(somePointer);

  return 0;
}/*end main()*/

