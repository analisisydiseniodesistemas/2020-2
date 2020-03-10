/** main.h */
#ifndef MAIN_H
#include <iostream>
#include <vector>
using namespace std;
//ADD YOUR CODE HERE
#define NELEM(x)	((sizeof(x))/(sizeof((x)[0])))
extern unsigned int bucket[256];
/** suma de elementos
*/
unsigned int selem(unsigned int [NELEM(bucket)],int);
void fill_string_vec(string,vector<string>&);
void print_vector_string(vector<string>);
#endif // MAIN_H
