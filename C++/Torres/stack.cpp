//esse mesmo v.02
#include "stack.h"
#include <iostream>

stackVector::stackVector(){
    TOP = 0;
    this->N = 6;
    aux = 0;
}

stackVector::stackVector(int d){
    TOP = 0;
    this->N = 6;
    D = d;
    aux = 0;
}

bool stackVector::Push(ficha O){
    if(TOP==N){
        return false;
    }
    V[TOP] = O;
    TOP++;
    return true;
}

bool stackVector::Pop(ficha *AUX){
    if(!TOP){
        return false;
    }
    TOP--;
    *AUX = V[TOP];
    return true;
}

void stackVector::imprime(){
    while(aux != N){
        std::cout<<(V[aux]).ch << '\t';
        aux++;
    }
}

void stackVector::retDiagonal(ficha *aux){
    *aux = V[D];
}
