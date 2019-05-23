#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "string.h"

struct BinarySearchTree
{
    BinarySearchTree();
    Node *root;

    void insert(Node *d);
    Node * insert(Human *d,Node *node);
    int nodeCounter(Node *node);
    int getHeight(Node *node);
    int getMax(int a, int b);
    Node *greater(Node* tree);
    Node *removeElement(Human *human);
    Node *removeElement(Human *human, Node* tree);
};

