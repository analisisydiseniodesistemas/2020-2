/** funciones.cpp */
#include <iostream>
#include <vector>
using namespace std;
/**Stub (inicialmente 2020.03.10)
  pre:string_vec.size()=0
*/
void fill_string_vec(string linea,
                     vector<string>& string_vec)
{
  string_vec.push_back("Qui");
  string_vec.push_back("est");
  string_vec.push_back("in");
  string_vec.push_back("caelis");
}/*end fill_string_vec()*/

void print_vector_string(vector<string> v)
{
    unsigned int i;
    for(i=0;i<v.size();i++)
    {
        cout<<v[i]<<"\n";
    }
}/*end print_vector_string()*/
