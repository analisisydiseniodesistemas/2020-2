#ifndef ESCALAR_H
#define ESCALAR_H
#include "Entrada.h"
typedef int T;

class Escalar : public Entrada
{
    friend class Polinomio;
    public:
        Escalar();
        Escalar(T val);
        virtual ~Escalar();
        virtual Entrada* operator*(Entrada* other);
        //virtual Entrada* Sumar(Entrada* other);
        virtual Entrada* Sumar(Escalar* other);
        virtual Entrada* Sumar(Polinomio* rhsPol);
        virtual Entrada* Restar(Escalar* other);
        virtual Entrada* Restar(Polinomio* rhsPol);
        virtual std::string to_string();
    protected:

    private:
        T Value;
};/*end class Escalar*/

#endif // ESCALAR_H
