#pragma once

#include "lrclassSat.h"

class vector {
    lrclassSat *v; // указатель на массив объектов lrclassSat
    int sz; // размер вектора
public:
    vector(int = 99);

    ~vector();

    vector(const vector &);

    vector &operator=(vector &);

    vector &operator+(vector &);

    int operator==(vector &);

    inline int size() const { return sz; }

    lrclassSat &operator[](int);

    inline lrclassSat &elem(int i) const { return v[i]; }

    friend vector operator-(vector &, vector &);
};

void error(const char *p);