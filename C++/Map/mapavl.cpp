#include <iostream>
#include "mapavl.h"

MapAVL::MapAVL()
{
    root = nullptr;
}

MapAVL::MapAVL(Node *root1)
{
    root = root1;
}

Node *MapAVL::Minimo(Node *R){
    while(R and R->Left){
        R = R->Left;
    }
    return R;
}

Node *MapAVL::Max(Node *R){
    if(!(R->Right))
        return R;
    Max(R->Right);
}

void MapAVL::RSD(Node **R){
    Node *A,*B;

    A = *R;
    B = A->Left;
    A->Left = B->Right;
    B->Right = A;

    if(B->FB == -1){
        A->FB = B->FB = 0;
    }else{
        A->FB = -1;
        B->FB = +1;
    }
}

void MapAVL::RSE(Node **R){
    Node *A,*B;

    A = *R;
    B = A->Right;
    A->Right = B->Left;
    B->Left = A;

    if(B->FB == +1){
        A->FB = B->FB = 0;
    }else{
        A->FB = +1;
        B->FB = -1;
    }
}

void MapAVL::RDD(Node **R){
    Node *a = *R;
    Node *b = a->Left;
    Node *c = b->Right;

    b->Right = c->Left;
    a->Left = c->Right;
    c->Left = b;
    c->Right = a;
    *R=c;

    if(c->FB == -1){
        a->FB = +1;
        b->FB = 0;
    }else{
        if(c->FB == +1){
            a->FB = 0;
            b->FB = -1;
        }else{
            a->FB = b->FB = 0;
        }
    }
    c->FB = 0;
}

void MapAVL::RDE(Node **R){
    Node *a = *R;
    Node *b = a->Right;
    Node *c = b->Left;

    a->Right = c->Left;
    b->Left = c->Right;
    c->Left = a;
    c->Right = b;
    *R=c;

    if(c->FB == +1){
        a->FB = -1;
        b->FB = c->FB = 0;
    }else{
        if(c->FB == -1){
            a->FB = c->FB = 0;
            b->FB = +1;
        }else{
            a->FB = b->FB = 0;
        }
    }
}

bool MapAVL::Insert(Node **R, Node *P){
    if(!(*R)){
        // ta na folha -> insere
        *R = P;
        P->FB = 0;
        return true;
    }
    if(P->D.key < (*R)->D.key)
    {
        // inserir na sub da esquerda
        if(MapAVL::Insert(&(*R)->Left,P)){
            if((*P).FB == 0){
                (*R)->FB = -1;
                return true;
            }
            if((*R)->FB == +1){
                (*R)->FB = 0;
                return false;
            }
            // vai ter rotação, qual?
            if((*R)->Left->FB == -1){
                // RSD
                RSD(R);
                std::cout<< "RSD\n";
                return false;
            }
            // fb do filho a esquerda +1
            // RDD
            RDD(R);
            std::cout<< "RDD\n";
            return false;
        }
        return false;
    }
    //inserir a direita
    if(MapAVL::Insert(&(*R)->Right,P)){
        // inseriu e  cresceu
        if((*R)->FB == 0){
            (*R)->FB = +1;
            return true;
        }
        if((*R)->FB == -1){
            (*R)->FB = 0;
            return false;
        }
        // vai ter rotação, qual?
        if((*R)->Right->FB == +1){
            // RSE
            RSE(R);
            std::cout<< "RSE\n";
            return false;
        }

        // RDE
        RDE(R);
        std::cout<< "RDE\n";
        return false;
    }
    return false;
}

bool MapAVL::Push(thing *DAT){
    Node *P = Node::montaNode(DAT);
    if(P){
        return Insert(&root,P);
    }
    return false;
}

bool MapAVL::Remove(Node **R, int k, thing *DAT){
    if(!(*R)){
        return false;
    }
    if(k == (*R)->D.key){
        *DAT = (*R)->D;
        std::cout<< DAT->key <<std::endl;
        Node::desmontaNode(*R,DAT);
        return true;
    }
    // vamos para esquerda
    if(k < (*R)->D.key){
        // procurar na sub da esquerda
        if(MapAVL::Remove(&(*R)->Left,k,DAT)){
            if((*R)->FB == 0){
                (*R)->FB = -1;
                return true;
            }
            if((*R)->FB == +1){
                (*R)->FB = 0;
                return false;
            }
            // vai ter rotação, qual?
            if((*R)->Left->FB == -1){
                // RSD
                RSD(R);
                return false;
            }
            // fb do filho a esquerda +1
            // RDD
            RDD(R);
            return false;
        }
        return false;
    }
    if(MapAVL::Remove(&(*R)->Right,k,DAT)){
        if((*R)->FB == 0){
            (*R)->FB = +1;
            return true;
        }
        if((*R)->FB == -1){
            (*R)->FB = 0;
            return false;
        }
        if((*R)->Right->FB == +1){
            RSE(R);
            return false;
        }
        RDE(R);
        return false;
    }
    return false;
}
