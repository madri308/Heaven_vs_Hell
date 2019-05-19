#include<stdio.h>
#include<stdlib.h>
#include "node.h"
#include "string.h"
struct BinarySearchTree
{
    BinarySearchTree();
    Node *root;

    void insert(Human *d);
    Node * insert(Human *d,Node *node);
    int nodeCounter(Node *node);
    int getHeight(Node *node);

};
