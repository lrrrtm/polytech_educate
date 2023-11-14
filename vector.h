#pragma once
#include "lrclassSat.h"

class vector {
    lrclassSat* v;
    int sz;
public:
    vector(int = 99);
    ~vector();
    vector(const vector&);

    vector& operator=(vector&);
    vector operator+(vector&);
    int operator==(vector&);
    inline int size() const{return sz;}
    lrclassSat& operator[](int);
    inline lrclassSat& elem(int i ) const{return v[i];}
    friend vector operator -(vector&, vector&);
};

void error(const char* p);