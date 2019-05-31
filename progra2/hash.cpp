#include "hash.h"
#include "iostream"

int Hash::hashFunction(int id)
{
    return (id % hashSize);
}

Hash::Hash()
{
    for (int i = 0; i < hashSize; i++)
    {
        hashTable[i] = new AVLTree();
    }
}

void Hash::insert(Human *person)
{
    int index = hashFunction(person->id);

    hashTable[index]->insert(person);
}


