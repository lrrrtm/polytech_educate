#include "stdio.h"
#include "math.h"
#include "lrclass.h"

void lrclass::normal(lrclass &a2) {
    while (exp > a2.exp) {
        man *= 2;
        exp -= 1;
    }
    while (a2.exp > exp) {
        a2.man *= 2;
        a2.exp -= 1;
    }
}

void lrclass::print() {
    printf("mantissa: %d, exponent: %d fact: %f\n", man, exp, (man / 1000.0) * pow(2.0, exp));
}

lrclass operator+(lrclass a1, lrclass a2) {
    a1.normal(a2);
    return lrclass((a1.man + a2.man), a1.exp);
}

lrclass operator-(lrclass a1, lrclass a2) {
    a1.normal(a2);
    return lrclass((a1.man - a2.man), a1.exp);
}

lrclass operator*(lrclass a1, lrclass a2) {
    a1.normal(a2);
    return lrclass((a1.man * a2.man) / 1000, a1.exp + a2.exp);
}

// сравнение для векторов
int lrclass::operator!=(lrclass &a) {
    if (man != a.man) return 1;
    if (exp != a.exp) return 1;
    return 0;
}