#include "avltree.h"
#include "node.h"
AVLTree::AVLTree()
{
    root = nullptr;
}

int AVLTree::max(int a, int b)
{
    return (a>b)? a:b;
}

int AVLTree::getHeight(Node *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    else {
        return node->height;
    }
}

Node *AVLTree::newNode(Human *human)
{

}

Node *AVLTree::rightRotate(Node *root)
{
    Node *x = root->prev;
    Node *T2 = x->next;

    //Hace la rotacion
    x->next = root;
    root->prev = T2;

    //Actualiza las alturas
    root->height = max(getHeight(root->prev), getHeight(root->next)) + 1;
    x->height = max(getHeight(x->prev), getHeight(x->next)) + 1;

    //Devuelve la nueva raiz
    return x;
}

Node *AVLTree::leftRotate(Node *root)
{
    Node *y = root->next;
    Node *T2 = y->prev;

    //Hace la rotacion
    y->prev = root;
    root->next = T2;

    //Actualizar alturas
    root->height = max(getHeight(root->prev), getHeight(root->next)) + 1;
    y->height =max(getHeight(y->prev), getHeight(root->next));

    //Devuelve la nueva raiz
    return y;
}

int AVLTree::getBalance(Node *node)
{
    if (node == nullptr){
        return 0;
    }
    else {
        return getHeight(node->prev) - getHeight(node->next);
    }
}


Node * AVLTree::insert(Node *root, Human *data)
{
    //1. Se hace la insercion normal de un BST
    if (root == nullptr)
    {
        return new Node(data);
    }
    else if (data->id < root->data->id)
    {
        root->prev = insert(root->prev,data);
    }
    else if(data->id >= root->data->id)
    {
        root->next = insert(root->next, data);
    }

    //2. Actualizar la altura del nodo ancestro
    root->height = 1 + getHeight(root->prev) - getHeight(root->next);

    //Chequear si el nodo se volvio inbalanceado
    int balance = getBalance(root);

    //Si esta inbalanceado hay 4 casos

    //Left Left
    if (balance > 1 && data->id < root->prev->data->id)
    {
        return leftRotate(root);
    }

    //Right Right
    if (balance < -1 && data->id > root->next->data->id)
    {
        return rightRotate(root);
    }

    //Left Right
    if (balance > 1 && data->id > root->prev->data->id)
    {
        root->prev = leftRotate(root->prev);
        return rightRotate(root);
    }

    //Right Left
    if (balance < -1 && data->id < root->next->data->id)
    {
        root->next = rightRotate(root->next);
        return leftRotate(root);
    }

    return root;
}
void AVLTree::insert(Human *d)
{
    root = insert(root,d);
}
Human *AVLTree::getRandom()
{
}

int AVLTree::nodeCounter(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    else {
        return 1+nodeCounter(root->next)+nodeCounter(root->prev);
    }
}
