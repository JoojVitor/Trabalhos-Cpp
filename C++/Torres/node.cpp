//esse mesmo v.02
#include "node.h"

Node* Node::MontaNode(ficha *DAT)
{
    Node *P = new Node;
    if(P)
    {
        P->D = *DAT;
        P->Next = 0;
    }
    return P;
}

void Node::DesmontaNode (Node *P, ficha *DAT)
{
    if(P){
        *DAT = P->D;
        delete P;
    }
}
