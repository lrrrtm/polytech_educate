#include "stdio.h"
#include "lrclassSat.h"

// вывод числа и указателем насыщаемости *
void lrclassSat::print() {
    lrclass::print();
    if (flag == 1) {
        printf("*\n");
    }
}

// сложение
lrclassSat operator+(lrclassSat a1, lrclassSat a2) {
    return lrclassSat(lrclass(a1) + a2, a1.flag == 1 || a2.flag == 1);

}

// вычитание
lrclassSat operator-(lrclassSat a1, lrclassSat a2) {
    int f = 0;
    if (a1.flag == 1 || a2.flag == 1) {
        f = 1;
    }
    lrclass a(a1.man, a1.exp);
    lrclass b(a2.man, a2.exp);
    lrclass c = a - b;
    return lrclassSat(c, f);
}

// умножение
lrclassSat operator*(lrclassSat a1, lrclassSat a2) {
    int f = 0;
    if (a1.flag == 1 || a2.flag == 1) {
        f = 1;
    }
    lrclass a(a1.man, a1.exp);
    lrclass b(a2.man, a2.exp);
    lrclass c = a * b;
    return lrclassSat(c, f);
}

// сравнение для векторов
int lrclassSat::operator!=(lrclassSat &a) {
    if (flag != a.flag) return 1;
    if (lrclassSat(a) != (*this)) return 1;
    return 0;
}