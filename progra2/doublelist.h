#ifndef DOUBLELIST_H
#define DOUBLELIST_H
#include "node.h"
#include "string"

struct DoubleList
{

    DoubleList();
    void add(Node *human);
    Node* get(int id);
    Node* getBySurnameAndCountrie(std::string surname,std::string country);
    bool exist(int id);

    bool isFull();
    bool isEmpty();
    void remove(int id);

    Node *first = nullptr;
    int quantity = 0;
};

#endif // DOUBLELIST_H
