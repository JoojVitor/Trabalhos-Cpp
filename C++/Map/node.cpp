#include "node.h"

static Node* montaNode(thing *DAT){
    Node* P = new Node;
    if(P){
        P->Right = P->Left = nullptr;
        P->D = *DAT;
    }
    return P;
}
static void desmontaNode(Node *P, thing *DAT){
    if(P){
        *DAT = P->D;
        delete P;
    }
}
