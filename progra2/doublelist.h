#ifndef DOUBLELIST_H
#define DOUBLELIST_H
#include "human.h"
#include "node.h"

struct DoubleList
{

    DoubleList();
    void add(Human *human);
<<<<<<< HEAD
    Node *get(int id);
=======
    Node* get(int id);
    Node* getBySurnameAndCountrie(string surname,string country);
    bool exist(int id);
>>>>>>> d9690e9c466c477d42d494068c6e165a53e6e53b

    bool isFull();
    bool isEmpty();
    void remove(int id);

    Node *first = nullptr;
    int quantity = 0;
};

#endif // DOUBLELIST_H
