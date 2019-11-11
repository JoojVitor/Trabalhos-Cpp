#ifndef MAPAVL_H
#define MAPAVL_H
#include "node.h"

class MapAVL
{
    Node* root;
public:
    MapAVL();
    MapAVL(Node *root1);

    Node* Minimo(Node* R);

    //rotações
    static void RSD(Node **R);
    static void RSE(Node **R);

    static void RDD(Node **R);
    static void RDE(Node **R);


    //inserção
    static bool Insert(Node** R, Node *P);

    //remoção
    static bool Remove(Node **R,int k, thing *DAT);
};

#endif // MAPAVL_H
