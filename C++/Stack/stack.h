#ifndef STACK_H
#define STACK_H
#include "node.h"

class stack{
private:
    Node *TOP;
    void printAll();
public:
    stack(){TOP = 0;}
    bool IsEmpty(){return !TOP;}
    bool Push(int *DAT);
    bool Pop(int *DAT);
};

#endif // STACK_H
