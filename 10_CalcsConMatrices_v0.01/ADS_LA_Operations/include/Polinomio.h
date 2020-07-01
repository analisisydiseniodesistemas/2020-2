#ifndef POLINOMIO_H
#define POLINOMIO_H
#include <vector>
#include <Entrada.h>
#include "Escalar.h"
//#include "xyPol.h"
//class xyPol;
class Polinomio : public Entrada
{
//    friend class xyPol;
    public:
        Polinomio();
        Polinomio(int);
        Polinomio(std::vector<int>& c);
        Polinomio(Escalar* EscPt,Polinomio* PolPt);
        virtual ~Polinomio();
        virtual Entrada* Sumar(Escalar* other);
        virtual Entrada* Sumar(Polinomio* rhsPol);
        virtual Entrada* Restar(Escalar* other);
        virtual Entrada* Restar(Polinomio* rhsPol);
        virtual std::string to_string();
        std::vector<int> get_coef();
        Polinomio& operator=(const Polinomio& other);
        Polinomio operator-();      /*unary substraction operator*/
    friend std::ostream& operator<<(std::ostream& sal,Polinomio& P);

    protected:

    private:
        /*coef[0]+coef[1]s^{1}+\cdots+coef[grado]s^{grado}*/
        int grado;
        std::vector<int> coef;    /* grado plus one */
};/*end class Polinomio*/

#endif // POLINOMIO_H
