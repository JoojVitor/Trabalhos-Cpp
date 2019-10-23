#include "node.h"

Node *Node::montaNode(int *DAT){
    Node *AUX = new Node;
    if(AUX){
        AUX->D = *DAT;
        AUX->next = nullptr;
    }
    return AUX;
}

void Node::desmontaNode(Node *P, int *DAT){
    if(P){
        *DAT = P->D;
        delete P;
    }
}

#ifndef NODE_H
#define NODE_H

class Node{
public:
    int D;
    Node *next;

    static Node *montaNode(int *DAT);
    static void desmontaNode(Node *P, int *DAT);
};

#endif // NODE_H
