//esse mesmo v.02
#ifndef STACK_H
#define STACK_H
#include "ficha.h"

class stackVector{
private:
    ficha V[6];
    int aux;
    int N;
    int TOP;
    int D;
public:
    stackVector();
    stackVector(int d);
    void imprime();
    bool Push(ficha O);
    bool Pop(ficha *AUX);
    void retDiagonal(ficha *aux);
    bool IsEmpty(){return !TOP;}
    bool IsFull(){return TOP==N;}
};

#endif // STACK_H
