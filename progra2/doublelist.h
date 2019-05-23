#ifndef DOUBLELIST_H
#define DOUBLELIST_H
#include "human.h"
#include "node.h"

struct DoubleList
{

    DoubleList();
    void add(Human *human);
    Node* get(int id);
    Node* getBySurnameAndCountrie(string surname,string country);
    bool exist(int id);

    bool isFull();
    bool isEmpty();
    void remove(int id);

    Node *first = nullptr;
    int quantity = 0;
};

#endif // DOUBLELIST_H
