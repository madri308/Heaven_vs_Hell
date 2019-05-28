#ifndef AVLTREE_H
#define AVLTREE_H
#include "node.h"

struct AVLTree
{
public:
    AVLTree(string name);
    Node *root;

    string name;

    int max(int a,int b);
    int getHeight(Node *node);
    Node *newNode(Human *human);
    Node *rightRotate(Node *root);
    Node *leftRotate(Node *root);
    int getBalance(Node *node);
    void insert(Human *d);
    Node *insert(Node *root, Human *data);
    Human* getRandom();
    int sins = 0;
    int count = 0;
};

#endif // AVLTREE_H
