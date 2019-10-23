//esse mesmo v.02
#ifndef QUEUE_H
#define QUEUE_H
#include "node.h"

class Queue
{
public:
    Queue();
    bool Enqueue(ficha *DAT);
    bool Dequeue(ficha *DAT);
    bool Enqueuee(ficha *DAT);
    bool IsEmpty();
private:
    Node *Head;
    Node *Tail;
};

#endif // QUEUE_H
