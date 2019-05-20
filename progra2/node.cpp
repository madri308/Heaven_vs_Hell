#include "node.h"

Node::Node(Human *human)
{
    this->data = human;
    next = prev = nullptr;
    height = 1;
}

