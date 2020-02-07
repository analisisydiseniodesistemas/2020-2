#include <assert.h>
#include <stdlib.h>

template<bool> struct CompilerTimeError;
template<> struct CompilerTimeError<true> {};

#define STATIC_CHECK(expr) \
  (CompileTimeError< != 0>() )


int
main(int argc,char *argv[])
{
  CompilerTimeError<true> dummy1;
  CompilerTimeError<false> dummy2;
  return 0;
} /*end main()*/

