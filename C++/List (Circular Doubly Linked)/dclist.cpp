#include "dclist.h"

template <class thing>
DCList<thing>::DCList()
{
    head = nullptr;
    size = 0;
}

template <class thing>
bool DCList<thing>::Push(thing *DAT){
    Node<thing> *P = Node<thing>::montaNode(DAT);
    if(!P)
        return false;
    if(!head){
        head = P->next = P->prev = P;
    }else{
        P->next = head;
        P->prev = head->prev;
        (P->prev)->next = P;
        head->prev = P;
        head = P;
    }
    return true;
}

template <class thing>
bool DCList<thing>::Search(thing *DAT, int K){
    if(!head) return false;
        Node<thing>* P = head;
    while(P->next!=head and (P->D) != K){
        P = P->next;
    }
    if((P->D)==K){
        *DAT = P->D;
        return true;
    }
    return false;
}

template <class thing>
bool DCList<thing>::Pop(thing *DAT, int K){
    if(!head)
        return false;
    Node <thing> *P = head;

    while(P->next!=head and P->D!=K){
        P = P->next;
    }
    if(P->D == K){
        if(P->next == (P->next)->prev){
            head = nullptr;
        }else{
            (P->prev)->next = P->next;
            (P->next)->prev = P->prev;
            if(head == P){
                head = P->next;
            }
        }
        Node<thing>::desmontaNode(P,DAT);
        return true;
    }
    return false;
}
