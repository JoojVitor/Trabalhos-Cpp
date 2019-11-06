#include "node.h"

Node *Node::montaNode(int *DAT){
    Node *AUX = new Node;
    if(AUX){
        AUX->D = *DAT;
        AUX->next = NULL;
    }
    return AUX;
}

void Node::desmontaNode(Node *P, int *DAT){
    if(P){
        *DAT = P->D;
        delete P;
    }
}
