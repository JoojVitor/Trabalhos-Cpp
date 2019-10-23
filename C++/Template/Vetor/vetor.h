#ifndef VETOR_H
#define VETOR_H

#include<iostream>
using namespace std;

template <typename T>
class Array {
private:
    T *ptr;
    int size;
public:
    Array(T arr[], int s);
    Array();
    ~Array();

    void print();
};

#endif // VETOR_H
