#ifndef NODE_H
#define NODE_H

class Node{
public:
    int D;
    Node *next;

    static Node *montaNode(int *DAT);
    static void desmontaNode(Node *P, int *DAT);
};

#endif // NODE_H
