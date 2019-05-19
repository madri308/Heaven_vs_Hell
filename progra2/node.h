#ifndef NODE_H
#define NODE_H
#include "human.h"


struct Node
{
public:
    Node(Human *data);
    Node *next = nullptr;
    Node *prev = nullptr;
    Human *data;
    int height;
};

#endif // NODE_H
