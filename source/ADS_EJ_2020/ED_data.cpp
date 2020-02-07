/**ED_data.cpp - Ecuaciones Diferenciales
 */

#include <iostream>
#include <vector>
using namespace std;
#define NDEBUG
#include <assert.h>

#include <Actividad.h>   /*Add -I./CommonFiles/ in your make file*/

/*Nueva ACTividad*/
#define NACT(name,duracion)	\
	VDA.push_back(new Actividad(name, duracion ## f ))

/*ends definition of macro NACT()*/


