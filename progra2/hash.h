#ifndef HASH_H
#define HASH_H
#include <list>
#include "avltree.h"

using namespace std;

struct Hash
{
    static const int SIZE = 1000;    // No. of buckets
    AVLTree * hashTable[SIZE]; //Puntero a un array de buckets
    public:
        Hash(int V);  // Constructor
        void insertItem(Human *x);
        void deleteItem(int key);
        int hashFunction(Human *x) {
            return (x->id % SIZE);
        }
        void displayHash();
};

#endif // HASH_H
