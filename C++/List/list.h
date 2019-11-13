#ifndef LIST_H
#define LIST_H
#include "node.h"

template<class thing>
class List
{
private:
    Node<thing> *Head;
    Node<thing> *Tail;

public:
    List();
    bool IsEmpty(){return !Head;}
    bool Push(thing *DAT);
    bool Pop(int K, thing *DAT);
    bool search(int K, thing *DAT);
};

#endif // LIST_H
