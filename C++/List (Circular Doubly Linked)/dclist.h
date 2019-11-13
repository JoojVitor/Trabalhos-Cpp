#ifndef DCLIST_H
#define DCLIST_H
#include "node.h"

template<class thing>
class DCList{
private:
    Node<thing> *head;
    thing K;
    int size;
public:
    DCList();
    int Size(){return size;}
    bool Empty(){return !head;}
    bool Push(thing *DAT);
    bool Search(thing *DAT, int K);
    bool Pop(thing *DAT, int K);
};

#endif // DCLIST_H
