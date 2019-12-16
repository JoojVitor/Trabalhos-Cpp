#ifndef NODE_H
#define NODE_H

template <class thing>
class Thing{
public:
    thing key;
};

template <class thing>
class Node
{
public:
    Node *Right;
    Node *Left;
    Thing<thing> D;
    int FB;

    static Node *montaNode(Thing<thing> *DAT){
        Node* P = new Node;
        if(P){
            P->Right = P->Left = nullptr;
            P->D = *DAT;
        }
        return P;
    }

    static void desmontaNode(Node *P, Thing<thing> *DAT){
        if(P){
            *DAT = P->D;
            delete P;
        }
    }
};

#endif
