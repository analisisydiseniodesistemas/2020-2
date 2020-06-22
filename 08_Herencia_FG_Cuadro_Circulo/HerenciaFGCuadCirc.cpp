Class FiguraGeometrica{     // Clase base 

protected: 

 std::string nombreDFigura; 

//... 

public: 

  FiguraGeometrica(std::string nombre); 

 virtual double area()=0; //método virtual puro, => la clase se convierte en una clase abstracta 

};/*end class FiguraGeometrica*/ 

 

Class Cuadro : public FiguragEometrica{ // La clase Cuadro es derivada de la clase FiguraGeometrica 

// ...

public: 

  Cuadro(double base,double altura); 

};/*end class Cuadro*/ 

 

Class Circulo : public Figura Geometrica{ 

public: 

  Circulo(double radio); 

};/*end class Circulo*/ 
