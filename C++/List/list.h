#ifndef LIST_H
#define LIST_H
#include "node.h"

class List
{
private:
    Node *Head;
    Node *Tail;

public:
    List();
    bool IsEmpty(){return !Head;}
    bool Push(int *DAT);
    bool Pop(int K, int *DAT);
    bool search(int K, int *DAT);
};

#endif // LIST_H
