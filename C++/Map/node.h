#ifndef NODE_H
#define NODE_H

class thing{
public:
    int key;
};

class Node
{
public:
    Node* Right;
    Node* Left;
    thing D;
    int FB;

    static Node* montaNode(thing* DAT);
    static void desmontaNode(Node* P, thing* DAT);
};

#endif // NODE_H
