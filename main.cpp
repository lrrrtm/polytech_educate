#include "lrclassSat.h"
#include "iostream"
#include "vector.h"

int main() {
    /*
    lrclassSat s(189.0);
    lrclassSat d(186.0);
    lrclassSat res = s + d;
    printf("lab 2\n\n");
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
    */

    vector b (3);
    vector c (3);

    for (int i = 0; i < 3; i++) {
        b.elem(i) = lrclassSat(2.0);
        c.elem(i) = lrclassSat(4.5);
    }
    printf("\nlab 3\n\nvector B\n");
    for (int i = 0; i < 3; i++){
        b.elem(i).print();
    }
    printf("vector C\n");
    for (int i = 0; i < 3; i++){
        c.elem(i).print();
    }

    vector result = b + c;

}
