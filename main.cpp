#include "lrclass.h"

int main(){
    lrclass s(123.4);
    lrclass d(23.56);
    lrclass res = s + d;
    s.print();
    d.print();
    res.print();
    res = s - d;
    res.print();
    res = s * d;
    res.print();
}