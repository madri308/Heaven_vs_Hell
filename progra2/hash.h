#ifndef HASH_H
#define HASH_H
#include <list>
#include "avltree.h"

using namespace std;

struct Hash
{
    static const int hashSize = 1000;
    AVLTree * hashTable[hashSize]; //Puntero a un array de buckets
    int hashFunction(int id);
    Hash();
    void insert(Human *person);

};

#endif // HASH_H
