#ifndef BSTNODE_H
#define BSTNODE_H
#include "human.h"

using namespace std;

struct BSTNode
{
public:
    BSTNode(Human*data);
    Human *data;
    BSTNode *leftSon;
    BSTNode *rightSon;

};

#endif // BSTNODE_H
