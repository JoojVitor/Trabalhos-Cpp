#ifndef QUEUE_H
#define QUEUE_H
#include "node.h"

class Queue
{
public:
    Queue();
    bool Enqueue(int *DAT);
    bool Dequeue(int *DAT);
    bool IsEmpty();
private:
    Node *Head;
    Node *Tail;
};


#endif // QUEUE_H
