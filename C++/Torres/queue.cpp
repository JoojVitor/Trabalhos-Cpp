//esse mesmo v.02
#include "queue.h"

Queue::Queue()
{
    Head = Tail = nullptr;
}

bool Queue::IsEmpty()
{
    return !Head;
}

bool Queue::Enqueue(ficha *DAT){
    Node *P = Node::MontaNode(DAT);
    if(!P)
        return false;
    if(!Head){
        Head = Tail = P;
    }else{
        Tail->Next = P;
        Tail = P;
    }
    return true;
}

bool Queue::Dequeue(ficha *DAT)
{
    if(!Head)
        return false;

    Node *P = Head;
    Head = Head->Next;
    Node::DesmontaNode(P, DAT);

    if(!Head)
        Tail = nullptr;

    return true;
}
