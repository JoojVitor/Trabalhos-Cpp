#ifndef MAPAVL_H
#define MAPAVL_H
#include "node.h"

template <class thing>
class MapAVL
{
private:
    Node<thing>* Minimo(Node<thing> *R);
    Node<thing>* Max(Node<thing> *R);
    static bool Insert(Node<thing> **R, Node<thing> *P);
    static void RSD(Node<thing> **R);
    static void RSE(Node<thing> **R);
    static void RDD(Node<thing> **R);
    static void RDE(Node<thing> **R);

public:
    Node<thing> *root;
    MapAVL();
    MapAVL(Node<thing> *root1);

    bool Push(Thing<thing> *DAT);
    static bool Remove(Node<thing> **R,int k, thing *DAT);
};

#endif // MAPAVL_H
