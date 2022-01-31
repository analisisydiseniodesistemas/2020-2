/**Conversion.h
 * Andrei Alexandrescu, Modern C++ design_generic programming 
 * and design patterns applied-Addison-Wesley Professional (2001).
 * 2.7 Detecting Convertibility and Inheritance at Compile Time
 */
#ifndef CONVERSION_H
#define CONVERSION_H
template <class T, class U> 
class Conversion 
{
   typedef char Small; 
   class Big { char dummy[2]; };
   static Small Test(U); 
   static Big Test(...);   /*Ellipsis function*/
   static T MakeT();
public:
   enum { exists =
      sizeof(Test(MakeT())) == sizeof(Small) };
#ifdef DETECT_INHERITANCE
   enum { sameType = false };
#endif /*DETECT_INHERITANCE*/
};/*end class Conversion*/ 

#ifdef DETECT_INHERITANCE
/** We implement sameType through a 
 * partial specialization of Conversion: */
template <class T>
class Conversion<T, T>
{
public:
   enum { exists = 1, sameType = 1 };
}; 

/** Finally, we're back home. With the help of Conversion, 
 * it is now very easy to determine inheritance: 
 */
#define SUPERSUBCLASS(T, U) \
   (Conversion<const U*, const T*>::exists && \
   !Conversion<const T*, const void*>::sameType)
 
/** SUPERSUBCLASS(T, U) evaluates to true if U inherits 
 * from T publicly, or if T and U are actually the same type. 
 * SUPERSUBCLASS does its job by evaluating the convertibility 
 * from a const U* to a const T*. There are only three cases 
 * in which const U* converts implicitly to const T*: 
 * 1.  T is the same type as U.
 * 2.  T is an unambiguous public base of U. 
 * 3.  T is void. 
 */

#define SUPERSUBCLASS_STRICT(T, U) \
   (SUPERSUBCLASS(T, U) && \
   !Conversion<const T, const U>::sameType) 

#endif /*DETECT_INHERITANCE*/

#endif /*CONVERSION_H*/

