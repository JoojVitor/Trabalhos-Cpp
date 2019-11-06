#ifndef NODE_H
#define NODE_H

template<class thing>
class Node{
public:
    thing D;
    Node *next;
    Node *prev;

    static Node *montaNode(thing *DAT){
        Node *AUX = new Node;
        if(AUX){
            AUX->D = *DAT;
            AUX->next = nullptr;
            AUX->prev = nullptr;
        }
        return AUX;
    }
    static void desmontaNode(Node *P, thing *DAT){
        if(P){
            *DAT = P->D;
            delete P;
        }
    }
};

#endif // NODE_H
