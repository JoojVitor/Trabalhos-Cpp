#include "list.h"

template<class thing>
List<thing>::List()
{
    Head = Tail = nullptr;
}

template<class thing>
bool List<thing>::Push(thing *DAT){
    Node<thing> *P = Node<thing>::montaNode(DAT);
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

template<class thing>
bool List<thing>::Pop(int K, thing *DAT){
    Node<thing> *P = Head;
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
    Node<thing>::desmontaNode(P,DAT);
    return true;
}

template<class thing>
bool List<thing>::search(int k, thing *DAT)
{
    Node<thing> *P = Head;
    while(P && (P->D) != k){
        P = P->next;
    }
    if(P){
        *DAT = P->D;
        return true;
    }
    return false;
}
