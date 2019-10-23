#include <iostream>
#include "stack.h"
#include "node.cpp"

void stack::printAll(){
    Node *AUX = TOP;
    while(AUX){
        std::cout<< AUX->D;
        AUX = AUX->next;
    }
    std::cout<< std::endl;
}

bool stack::Push(int *DAT){
    Node *P = Node::montaNode(DAT);
    if(!P)
        return false;
    P->next = TOP;
    TOP = P;
    //COMANDO PARA TESTE!!
    //printAll();
    return true;
}

bool stack::Pop(int *DAT){
    if(!TOP)
        return false;
    Node *P = TOP;
    TOP = P->next;
    Node::desmontaNode(P,DAT);
    return true;
}
