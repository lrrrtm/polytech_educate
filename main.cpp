#include "lrclassSat.h"
#include "iostream"

int main(){
    lrclassSat s(128.4);
    lrclassSat d(23.4);
    lrclassSat res = s + d;

    printf("Input data\n");
    s.print();
    d.print();

    printf("\nadd\n");
    res.print();

    printf("\nsubtract\n");
    res = s - d;
    res.print();

    printf("\nmultiply\n");
    res = s * d;
    res.print();
}