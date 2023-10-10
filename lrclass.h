#include "math.h"

class lrclass {
protected:
    int man;
    int exp;

public:
    lrclass(double m){
        exp = 0;
        while (fabs(m) >= 0.2){
            m /= 2;
            exp += 1;
        }

        while (fabs(m) <= 0.1){
            m *= 2;
            exp -= 1;
        }

        m *= 1000;
        man = int(m + 0.5);
    }
    lrclass(int m, int e){
        double k = (double) m;
        while (fabs(k) >= 200){
            k /= 2;
            e += 1;
        }
        while (fabs(k) < 100){
            k *= 2;
            e -= 1;
        }
        man = int(k + 0.5);
        exp = e;
    }

    void normal(lrclass&);
    void print();
    friend lrclass operator +(lrclass, lrclass);
    friend lrclass operator -(lrclass, lrclass);
    friend lrclass operator *(lrclass, lrclass);
};