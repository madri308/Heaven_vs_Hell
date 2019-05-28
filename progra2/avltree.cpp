#include "avltree.h"
#include "node.h"
AVLTree::AVLTree(string name)
{
    this->name = name;
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


Node *AVLTree::rightRotate(Node *root)
{
    Node *x = root->left;
    Node *T2 = x->right;

    //Hace la rotacion
    x->right = root;
    root->left = T2;

    //Actualiza las alturas
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    //Devuelve la nueva raiz
    return x;
}

Node *AVLTree::leftRotate(Node *root)
{
    Node *y = root->right;
    Node *T2 = y->left;

    //Hace la rotacion
    y->left = root;
    root->right = T2;

    //Actualizar alturas
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    y->height =max(getHeight(y->left), getHeight(root->right));

    //Devuelve la nueva raiz
    return y;
}

int AVLTree::getBalance(Node *node)
{
    if (node == nullptr){
        return 0;
    }
    else {
        return getHeight(node->left) - getHeight(node->right);
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
        root->left = insert(root->left,data);
    }
    else if(data->id >= root->data->id)
    {
        root->right = insert(root->right, data);
    }

    //2. Actualizar la altura del nodo ancestro
    root->height = 1 + getHeight(root->left) - getHeight(root->right);

    //Chequear si el nodo se volvio inbalanceado
    int balance = getBalance(root);

    //Si esta inbalanceado hay 4 casos

    //Left Left
    if (balance > 1 && data->id < root->left->data->id)
    {
        return leftRotate(root);
    }

    //Right Right
    if (balance < -1 && data->id > root->right->data->id)
    {
        return rightRotate(root);
    }

    //Left Right
    if (balance > 1 && data->id > root->left->data->id)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    //Right Left
    if (balance < -1 && data->id < root->right->data->id)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
void AVLTree::insert(Human *d)
{
    this->count++;
    root = insert(root,d);
}
int AVLTree::nodeCounter(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    else {
        return 1+nodeCounter(root->next)+nodeCounter(root->prev);

Human *AVLTree::getRandom()
{
    Node *toReturn = this->root;
    if(toReturn == nullptr){
        return toReturn->data;
    }
    for(int n = 0; n<this->count ; n++){
        if(toReturn->left == nullptr && toReturn->right == nullptr){
            return toReturn->data;
        }
        int dir = rand() % 2;
        if(dir == 1){
            if(toReturn->right == nullptr){
                toReturn = toReturn->left;
            }else{
                toReturn = toReturn->right;
            }
        }else{
            if(toReturn->left == nullptr){
                toReturn = toReturn->right;
            }else{
                toReturn = toReturn->left;
            }
        }
    }
}
