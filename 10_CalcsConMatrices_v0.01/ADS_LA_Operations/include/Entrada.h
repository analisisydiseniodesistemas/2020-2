#ifndef ENTRADA_H
#define ENTRADA_H
#include <iostream>
class Escalar;        /*Declaración anticipada de clase*/
class Polinomio;      /*Declaración anticipada de clase*/
class Entrada
{
    public:
        Entrada();         /*Constructor por defecto*/
        virtual ~Entrada();/*Destructor*/
        Entrada(std::string nameOfEntry);/*Constructor*/
        //virtual Entrada* operator*(Entrada* other);
        virtual Entrada* operator+(Entrada* other);
        //virtual Entrada* Sumar(Entrada* other)=0;
        virtual Entrada* Sumar(Escalar* other)=0;   /*funci\'on virtual pura  */
        virtual Entrada* Sumar(Polinomio* rhsPol)=0;/* => Entrada es abstracta*/
        //virtual Entrada* Restar(Entrada* other);
        virtual Entrada* Restar(Escalar* other)=0;
        virtual Entrada* Restar(Polinomio* rhsPol)=0;
        virtual Entrada* operator-(Entrada* other);
        virtual std::string to_string()=0;
        virtual Entrada* operator*(Entrada* other)=0;
    friend std::ostream& operator<<(std::ostream& out,Entrada& rhs);

    protected:
        std::string nombreDEntrada;    /*"Escalar","Polinomio"*/
    private:
};/*end class Entrada*/

#endif // ENTRADA_H
