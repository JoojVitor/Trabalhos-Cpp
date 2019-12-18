#ifndef MAPAVL_H
#define MAPAVL_H
#include "node.h"

class MapAVL
{
private:
    Node* Minimo(Node *R);
    Node* Max(Node *R);
    static bool Insert(Node **R, Node *P);
    static bool Remove(Node **R, ID k, pair<ID, entity> *DAT);
    static bool Search(Node **R, ID k, pair<ID, entity> *DAT);
    static void RSD(Node **R);
    static void RSE(Node **R);
    static void RDD(Node **R);
    static void RDE(Node **R);

public:
    Node *root;
    MapAVL();
    MapAVL(Node *root1);

    bool Push(pair<ID, entity> *DAT);
    bool Pop(ID k, pair<ID,entity> *DAT);
    bool search(ID k, pair<ID,entity> *DAT);
};

#endif // MAPAVL_H
