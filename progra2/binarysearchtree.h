// C program to demonstrate insert operation in binary search tree
#include<stdio.h>
#include<stdlib.h>
#include "node.h"

struct BinarySearchTree
{
    BinarySearchTree();
    Node *root;

    void insert(Human *d);
    Node * insert(Human *d,Node *node);

};
