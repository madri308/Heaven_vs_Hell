#ifndef HEAVENNODE_H
#define HEAVENNODE_H
#include "string"
using namespace std;

struct HeavenNode
{
    HeavenNode(string type);
    string type;
    HeavenNode *leftChild;
    HeavenNode *middleChild;
    HeavenNode *rightChild;
    int height;
};

#endif // HEAVENNODE_H
