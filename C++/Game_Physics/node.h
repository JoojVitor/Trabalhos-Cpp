#ifndef NODE_H
#define NODE_H
#include "entity.h"
#include <iostream>
using namespace std;

class Node
{
public:
    Node *Right;
    Node *Left;
    pair<ID,entity> D;
    int FB;

    static Node *montaNode(pair<ID,entity> *DAT){
        Node* P = new Node;
        if(P){
            P->Right = P->Left = nullptr;
            P->D = *DAT;
        }
        return P;
    }

    static void desmontaNode(Node *P, pair<ID,entity> *DAT){
        if(P){
            *DAT = P->D;
            delete P;
        }
    }
};

#endif
