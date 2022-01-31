#ifndef XYPOL_H
#define XYPOL_H
#include "Polinomio.h"

class xyPol{
    int x;
    int y;
    //Polinomio *P;
    std::vector<int> co;
public:
    xyPol(){}
    xyPol(int m,int n,std::vector<int> pPt){
      x=m;y=n;co=pPt;
    }
    friend std::ostream& operator<<(std::ostream& sal,xyPol& xyp){
      std::vector<int> c=xyp.co;
      sal<<"X["<<xyp.x<<"]["<<xyp.y<<"]=";
      for(int i=c.size()-1;i>=0;i--){
        sal<<c[i]<<" ";
      }
      sal<<std::endl;
      return sal;
    }
};/*end class xyPol*/
#endif // XYPOL_H

