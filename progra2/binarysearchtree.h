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
    Node *search(int id, Node* root);
    int nodeCounter(Node *node);
    int getHeight(Node *node);
    int getMax(int a, int b);
    Node *greater(Node* tree);
    Node *removeElement(int id);
    Node *removeElement(int id, Node* tree);
};

