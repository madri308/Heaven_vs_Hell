#include "hash.h"
#include "iostream"

Hash::Hash(int b)
{
    this->SIZE = b;
    table = new list<AVLTree *>[SIZE];
}

void Hash::insertItem(Human *key)
{
    int index = hashFunction(key);
    table[index].push_back();
}

void Hash::deleteItem(int key)
{
    // get the hash index of key
    int index = hashFunction(key);

    // find the key in (inex)th list
    list <int> :: iterator i;
    for (i = table[index].begin();
        i != table[index].end(); i++) {
      if (*i == key)
        break;
    }

    // if key is found in hash table, remove it
    if (i != table[index].end())
        table[index].erase(i);
}

void Hash::displayHash()
{
    for (int i = 0; i < BUCKET; i++) {
        cout << i;
        for (auto x : table[i])
          cout << " --> " << x;
        cout << endl;
      }
}

