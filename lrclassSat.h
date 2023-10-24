#include "math.h"
#include "lrclass.h"
#pragma once

class lrclassSat: public lrclass {
protected:
    int flag;
public:
    lrclassSat(double m): lrclass(m){
        flag = 0;
        if (exp > 10) {
            exp = 10;
            man = 199;
            flag = 1;
        }
        else if (exp < -10){
            man = 100;
            flag = 1;
        }
    }

    lrclassSat(lrclass m, int f) : lrclass(m){
        if (exp > 10){
            exp = 10;
            man = 199;
            f = 1;
        }
        else if (exp < -10){
            man = 100;
            f = 1;
        }
        flag = f;
    }

    void print();
    friend lrclassSat operator +(lrclassSat, lrclassSat);
    friend lrclassSat operator -(lrclassSat, lrclassSat);
    friend lrclassSat operator *(lrclassSat, lrclassSat);
};


