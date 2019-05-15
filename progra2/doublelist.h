#ifndef DOUBLELIST_H
#define DOUBLELIST_H
#include "human.h"
#include "node.h"

struct DoubleList
{

    DoubleList();
    void add(Human *human);

    bool isFull();
    bool isEmpty();
    void remove(int id);

    Node *first = nullptr;
    int quantity = 0;
};

#endif // DOUBLELIST_H
