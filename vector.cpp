#include "vector.h"
#include "stdio.h"
#include "iostream"
#include "lrclassSat.h"

vector::vector(int s) {
    if (s <= 0) error("1");
    v = new lrclassSat(s);
    if (v == nullptr) error("2");
    sz = s;
}

vector::~vector() {
    delete[]v;
}

vector::vector(const vector & a): vector(a.size()) {
    for (int i = 0; i < size(); i++){
        elem(i) = a.elem(i);
    }
}

vector& vector::operator=(vector & a) {
    int s = a.size();
    if (size() != a.size()) {
        delete[]v;
        this->v = new lrclassSat(s);
        sz = s;
    }
    for (int i = 0; i < size(); i++) {
        elem(i) = a.elem(i);
    }
}

vector& vector::operator+(vector & a) {
    int s = size();
    if (s != a.size()) error("-2");
    vector sum(s);
    for (int i = 0; i < s; i++) {
        sum.elem(i) = elem(i) + a.elem(i);
    }
    return sum;
}

lrclassSat& vector::operator[](int i) {
    if (i < 0 || i >= sz) error("3");
    return v[i];
}

vector operator-(vector& a, vector& b){
    int s = a.size();
    if (s != b.size()) error("-3");
    vector sub(s);
    for (int i = 0; i < s; i++) {
        sub.elem(i) = a.elem(i) - b.elem(i);
    }
    return sub;
}


int vector::operator==(vector & a) {
    if (size() != a.size()) return 0;

    for (int i = 0; i < sz; i++) {
        if (elem(i) != a.elem(i)) return 0;
    }
    return 1;
}


void error(const char* p) {
    printf(p);
    exit(1);
}