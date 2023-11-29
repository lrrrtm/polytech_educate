#include "vector.h"
#include "stdio.h"
#include "iostream"
#include "lrclassSat.h"

// выделяем память для масссива объектов lrclassSat и устанавливаем размер вектора
vector::vector(int s) {
    if (s <= 0) error("zero_arr_length"); // длина меньше 0
    v = new lrclassSat(s);
    if (v == nullptr) error("vector_memory"); // проверка успешности выделения памяти
    sz = s;
}

//дестркутор для освобождения памяти, выделенной под вектор
vector::~vector() {
    delete[]v;
}

// создание нового вектора того же размера и копирование в него элементов
vector::vector(const vector &a) : vector(a.size()) {
    for (int i = 0; i < size(); i++) {
        elem(i) = a.elem(i);
    }
}

// оператор присваивания векторов
vector &vector::operator=(vector &a) {
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

// оператор сложения векторов
vector &vector::operator+(vector &a) {
    int s = size();
    if (s != a.size()) error("diff_dimesion_add");
    vector sum(s);
    for (int i = 0; i < s; i++) {
        sum.elem(i) = elem(i) + a.elem(i);
    }
    return sum;
}

// оператор вычитания векторов
vector operator-(vector &a, vector &b) {
    int s = a.size();
    if (s != b.size()) error("diff_dimesion_subdiv");
    vector sub(s);
    for (int i = 0; i < s; i++) {
        sub.elem(i) = a.elem(i) - b.elem(i);
    }
    return sub;
}

// оператор индекации (возвращает ссылку на элемент вектора с заданным индексом
lrclassSat &vector::operator[](int i) {
    if (i < 0 || i >= sz) error("3");
    return v[i];
}

// оператор поэлементного сравнения вектора (0 если отличается размерность или векторы не равны)
int vector::operator==(vector &a) {
    if (size() != a.size()) return 0;

    for (int i = 0; i < sz; i++) {
        if (elem(i) != a.elem(i)) return 0;
    }
    return 1;
}

// функция вывода ошибки в консоль
void error(const char *p) {
    printf(p);
    exit(1);
}