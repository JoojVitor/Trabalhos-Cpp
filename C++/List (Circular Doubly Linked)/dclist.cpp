#include "dclist.h"

template <class thing>
DCList<thing>::DCList()
{
    head = nullptr;
    size = 0;
}

template <class thing>
bool DCList<thing>::Push(thing *DAT){
    Node<thing>* P= Node<thing>::montaNode(DAT);
    if(P){
        if(!head){
            head = P->next = P->prev = P;
         }else{
            P->next = head;
            P->prev = head->prev;
            head->prev = P;
            head = P;
         }
         size++;
         return true;
    }
    return false;
}

template <class thing>
bool DCList<thing>::Pop(thing *DAT, int K){
    if(!head) return false;
            Node<thing>* P = head;
            while(P->next!=head and (P->D) != K)
            {
                P = P->next;
            }
            if((P->D)==K)
            {
                if(P->next==P->prev)
                {
                    head = nullptr;
                }
                else
                {
                    (P->next)->prev=(P->prev);
                    (P->prev)->next=(P->next);
                    if(head == P)
                    {
                        head = P->next;
                    }
                }
                Node<thing>::desmontaNode(P,DAT);
                size--;
                return true;
            }
            return false;
        }
