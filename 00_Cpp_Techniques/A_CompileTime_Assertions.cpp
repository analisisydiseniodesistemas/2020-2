#include <assert.h>
#include <stdlib.h>

#ifdef RUNTIME_ASSERTION
template <class To,class From>
To safe_reinterpret_cast(From from)
{
  assert(sizeof(From)<=sizeof(To));
  return reinterpret_cast<To>(from);
}
#endif  /*RUNTIME_ASSERTION*/

#define STATIC_CHECK(expr)	{char unnamed[(expr)?1:-1];}

#ifdef COMPILETIME_ASSERTION
template <class To,class From>
To safe_reinterpret_cast(From from)
{
  STATIC_CHECK(sizeof(From)<=sizeof(To));
  return reinterpret_cast<To>(from);
}
#endif /*COMPILETIME_ASSERTION*/

int
main(int argc,char *argv[])
{
  int i=argc;
#ifdef RUNTIME_ASSERTION
  char *p=safe_reinterpret_cast<char*>(i);
#endif  /*RUNTIME_ASSERTION*/

#ifdef COMPILETIME_ASSERTION
  void *somePointer=malloc(1);
  char c=safe_reinterpret_cast<char>(somePointer);
#endif /*COMPILETIME_ASSERTION*/

  return 0;
}/*end main()*/

