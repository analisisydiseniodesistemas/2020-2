/** main.h */
#ifndef MAIN_H
#include <iostream>
#include <vector>
//#define CPPBUILDER        /*if using Embarcadero RAD Studio 2009*/
#ifndef CPPBUILDER
#include <stdbool.h>
#else
#define true	1
#define false	0
#endif /*NOCPPBUILDER*/
using namespace std;
#define NELEM(x)	((sizeof(x))/(sizeof((x)[0])))
typedef unsigned int uint;
extern unsigned int bucket[256];
/** suma de elementos
*/
unsigned int selem(unsigned int [NELEM(bucket)],int);
void fill_string_vec(string,vector<string>&);
void print_vector_string(vector<string>);
bool is_included(std::string,vector<string>);
void print_index_char_of_string(string s);
bool is_space(char c);
struct StringYuint;
uint mapa(string word,StringYuint * syu_pt,uint size);
void contar_palabras(string line,
                     StringYuint *syu_pt,
                     vector<string> string_vec);

struct StringYuint{
  string palabra;
  uint N;        /*cantidad de veces que aparece el string palabra*/
  uint I;        /*n\'umero de \'indice del string palabra*/
static uint count;/*variable de clase para contar objetos e inicializar I*/
  StringYuint(){ }
  StringYuint(string);
};/*end struct StringYuint*/
#endif // MAIN_H

