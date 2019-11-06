#include "list.h"

List::List()
{
    Head = Tail = nullptr;
}

bool List::Push(int *DAT){
    Node *P = Node::montaNode(DAT);
    if(!P)
        return false;
    P->next = Head;
    P->Prev = nullptr;
    if(!Head){
        Tail = P;
    }else{
        Head->Prev = P;
    }
    Head = P;
    return true;
}

bool List::Pop(int K, int *DAT){
    Node *P = Head;
    while(P and (P->D) != K){
        P = P->next;
    }
    if(!P)
        return false;
    if(P->Prev){
        (P->Prev)->next = P->next;
    }else{
        Head = P->next;
    }
    if(P->next){
        (P->next)->Prev = P->Prev;
    }else{
        Tail = P->Prev;
    }
    Node::desmontaNode(P,DAT);
    return true;
}

bool List::search(int k, int *DAT)
{
    Node *P = Head;

    while(P && (P->D) != k){
        P = P->next;
    }

    if(P){
        *DAT = P->D;
        return true;
    }

    return false;
}
