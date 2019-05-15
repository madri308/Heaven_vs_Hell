#ifndef NODE_H
#define NODE_H
#include "human.h"


struct Node
{
public:
    Node(Human *data);
    Node *next;
    Node *prev;
    Human *data;
};

#endif // NODE_H
