#ifndef NODE_H
#define NODE_H

class thing{
public:
    int key;
};

class Node
{
public:
    Node *Right;
    Node *Left;
    thing D;
    int FB;

    static Node *montaNode(thing *DAT);
    static void desmontaNode(Node *P, thing *DAT);
};

Node *Node::montaNode(thing *DAT){
    Node* P = new Node;
    if(P){
        P->Right = P->Left = nullptr;
        P->D = *DAT;
    }
    return P;
}
void Node::desmontaNode(Node *P, thing *DAT){
    if(P){
        *DAT = P->D;
        delete P;
    }
}

