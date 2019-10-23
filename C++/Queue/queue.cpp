#include "queue.h"
#include "node.cpp"

Queue::Queue()
{
    Head = Tail = nullptr;
}

bool Queue::IsEmpty()
{
    return !Head;
}

bool Queue::Enqueue(int *DAT){
    Node *P = Node::montaNode(DAT);
    if(!P)
        return false;
    if(!Head){
        Head = Tail = P;
    }else{
        Tail->next = P;
        Tail = P;
    }
    return true;
}

bool Queue::Dequeue(int *DAT)
{
    if(!Head)
        return false;

    Node *P = Head;
    Head = Head->next;
    Node::desmontaNode(P, DAT);

    if(!Head)
        Tail = nullptr;

    return true;
}
