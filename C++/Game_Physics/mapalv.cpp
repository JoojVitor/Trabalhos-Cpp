#include <iostream>
#include "mapavl.h"

template <class thing>
MapAVL<thing>::MapAVL()
{
    root = nullptr;
}

template <class thing>
MapAVL<thing>::MapAVL(Node<thing> *root1)
{
    root = root1;
}

template <class thing>
Node<thing> *MapAVL<thing>::Minimo(Node<thing> *R){
    while(R and R->Left){
        R = R->Left;
    }
    return R;
}

template <class thing>
Node<thing> *MapAVL<thing>::Max(Node<thing> *R){
    if(!(R->Right))
        return R;
    Max(R->Right);
}

template <class thing>
void MapAVL<thing>::RSD(Node<thing> **R){
    Node<thing> *A,*B;

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

template <class thing>
void MapAVL<thing>::RSE(Node<thing> **R){
    Node<thing> *A,*B;

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

template <class thing>
void MapAVL<thing>::RDD(Node<thing> **R){
    Node<thing> *a = *R;
    Node<thing> *b = a->Left;
    Node<thing> *c = b->Right;

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

template <class thing>
void MapAVL<thing>::RDE(Node<thing> **R){
    Node<thing> *a = *R;
    Node<thing> *b = a->Right;
    Node<thing> *c = b->Left;

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

template <class thing>
bool MapAVL<thing>::Insert(Node<thing> **R, Node<thing> *P){
    if(!(*R)){
        // ta na folha -> insere
        *R = P;
        P->FB = 0;
        return true;
    }
    if(P->D.key < (*R)->D.key){
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

template <class thing>
bool MapAVL<thing>::Push(Thing<thing> *DAT){
    Node<thing> *P = Node<thing>::montaNode(DAT);
    if(P){
        return Insert(&root,P);
    }
    return false;
}

template <class thing>
bool MapAVL<thing>::Remove(Node<thing> **R, int k, thing *DAT){
    if(!(*R)){
        return false;
    }
    if(k == (*R)->D.key){
        *DAT = (*R)->D;
        std::cout<< DAT->key <<std::endl;
        Node<thing>::desmontaNode(*R,DAT);
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
