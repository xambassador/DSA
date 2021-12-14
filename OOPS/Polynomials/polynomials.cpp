#pragma once;
#include<iostream>
using std::cout;
using std::endl;
class Polynomial {
    public:
    int* arr;
    int cpacity;

    Polynomial() {
        arr = new int[1000];
        for (int i{}; i < 1000; i++) arr[i] = 0;
        cpacity = 1000;
    }

    Polynomial(Polynomial const &p) {
        this->arr = new int[p.cpacity];
        for (int i{}; i < p.cpacity; i++) this->arr[i] = p.arr[i];
        this->cpacity = p.cpacity;
    }

    void operator=(Polynomial const &p) {
        this->arr = new int[p.cpacity];
        for (int i{}; i < p.cpacity; i++) this->arr[i] = p.arr[i];
        this->cpacity = p.cpacity;
    }

    Polynomial operator+(Polynomial const &p) {
       int maxCpacity;
       if (this->cpacity >= p.cpacity) maxCpacity = this->cpacity;
       else maxCpacity = p.cpacity;
       Polynomial fNew;
       int* a = new int[maxCpacity];
       for (int i{}; i < maxCpacity; i++) a[i] = 0;
       for (int i{}; i < maxCpacity; i++) a[i] = this->arr[i] + p.arr[i];
       delete [] fNew.arr;
       fNew.arr = a;
       fNew.cpacity = maxCpacity;
       return fNew;
    }

    Polynomial operator-(Polynomial const &p) {
        int maxCpacity;
        if (this->cpacity >= p.cpacity) maxCpacity = this->cpacity;
        else maxCpacity = p.cpacity;
        Polynomial fNew;
        int* a = new int[maxCpacity];
        for (int i{}; i < maxCpacity; i++) a[i] = 0;
        for (int i{}; i < maxCpacity; i++) a[i] = this->arr[i] - p.arr[i];
        delete [] fNew.arr;
        fNew.arr = a;
        fNew.cpacity = maxCpacity;
        return fNew;
    }

    Polynomial operator*(Polynomial const &p) {
        int* a = new int[this->cpacity * p.cpacity];
        for (int i{}; i < this->cpacity * p.cpacity; i++) a[i] = 0;
        for (int i{}; i < this->cpacity; i++){
            int deg = i, coeff = this->arr[i];
            for (int j{}; j < p.cpacity; j++){
                int t = coeff * p.arr[j];
                int ind = deg + j;
                a[ind] = t + a[ind];
            }
        }
        Polynomial fNew;
        delete [] fNew.arr;
        fNew.arr = a;
        fNew.cpacity = this->cpacity*p.cpacity;
        return fNew;
    }

    void print() {
        for (int i{}; i < cpacity; i++) {
            if(arr[i] == 0) continue;
            else cout << arr[i] << "x" << i << " ";
        }
        cout << endl;
    }

    void setCoefficient(int degree, int coeff){
        if (degree  > cpacity){
            int* a = new int[cpacity + degree];
            for (int i{}; i < cpacity + degree; i++) a[i] = 0;
            for (int i{}; i < cpacity; i++) a[i] = arr[i];
            delete [] arr;
            arr = a;
            cpacity += degree;
        }
        arr[degree] = coeff;
    }
};
