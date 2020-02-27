/**ListaDTipos.h
*/
#ifndef LISTA_DTIPOS
#define LISTA_DTIPOS
class NullType { };

template <class T,class U>
struct Typelist
{
  typedef T Head;
  typedef U Tail;
};

//namespace TL
//{
// //...typelist algorithms...
//}
//Example of a Typelist:typelist of only one element:
//typedef Typelist<int,NullType> OneTypeOnly;
//
//Example of a Typelist:typelist containing the three 
//char variants:
//typedef Typelist<char,Typelist<signed char,
//   Typelist<unsigned char,NullType> > > AllCharTypes;
//Therefore, we have obtained an open-ended Typelist template 
//that can, by compounding a basic cell, hold any number of types. 
//
//The property of templates used here is that a template parameter 
//can be any type, including another instantiation of the same 
//template. This is an old, well-known property of templates,
//often used to implement ad hoc matrices as 
//vector< vector<double> >. Because Typelist accepts two
//parameters, we can always extend a given Typelist by replacing 
//one of the parameters with another Typelist, ad infinitum. 

#define TYPELIST_1(T1) Typelist<T1, NullType>
#define TYPELIST_2(T1, T2) Typelist<T1, TYPELIST_1(T2) >
#define TYPELIST_3(T1, T2, T3) Typelist<T1, TYPELIST_2(T2, T3) >
#define TYPELIST_4(T1, T2, T3, T4) \
  Typelist<T1, TYPELIST_3(T2, T3, T4) >
//...
//#define TYPELIST_50(T1,T2,...,T50)	...
//
//Each macro uses the previous one, which makes it easy for the 
//library user to extend the upper limit, should this necessity 
//emerge.
//Now the earlier type definition of SignedIntegrals can be 
//expressed in a much more pleasant way: 
//typedef TYPELIST_4(signed char, short int, int, long int)
//   SignedIntegrals;

//Linearizing typelist creation is only the beginning. Typelist 
//manipulation is still very clumsy. For instance, accessing the 
//last element in SignedIntegrals requires using 
//SignedIntegrals::Tail::Tail::Head. It's not yet clear how we 
//can manipulate typelists generically. It's time, then, to define 
//some fundamental operations for typelists by thinking of the 
//primitive operations available to lists of values. 




#endif /*LISTA_DTIPOS*/

