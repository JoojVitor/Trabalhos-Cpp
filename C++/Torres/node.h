//esse mesmo v.02
#ifndef NODE_H
#define NODE_H
#include "ficha.h"

class Node
{
public:
    ficha D;
    Node *Next;
    static Node* MontaNode(ficha *DAT);
    static void DesmontaNode(Node *P, ficha *DAT);
};

#endif // NODE_H
