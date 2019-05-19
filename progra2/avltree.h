#ifndef AVLTREE_H
#define AVLTREE_H

#include "human.h"
struct AVLTree
{
public:
    AVLTree();
    void add(Human *human);
    Human getRandom();
};

#endif // AVLTREE_H
