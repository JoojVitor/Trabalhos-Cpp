#ifndef MAPAVL_H
#define MAPAVL_H
#include "node.h"

class MapAVL
{
private:
    Node* Minimo(Node* R);
    Node* Max(Node* R);
    static bool Insert(Node** R, Node *P);
    static void RSD(Node **R);
    static void RSE(Node **R);
    static void RDD(Node **R);
    static void RDE(Node **R);

public:
    Node *root;
    MapAVL();
    MapAVL(Node *root1);

    bool Push(thing *DAT);
    static bool Remove(Node **R,int k, thing *DAT);
};

#endif // MAPAVL_H
