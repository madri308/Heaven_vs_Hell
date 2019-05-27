#include "binarysearchtree.h"
#include "human.h"

BinarySearchTree::BinarySearchTree()
{
    root = nullptr;
}

void BinarySearchTree::insert(Human *d)
{
    root = insert(d,root);
}

Node* BinarySearchTree::insert(Human *human, Node *node)
{
    if (node == nullptr)
    {
        return new Node(human);
    }
    else if (node->data->id < human->id)
    {
        node->right = insert(human,node->right);
    }
    else if(node->data->id >= human->id)
    {
        node->left = insert(human, node->left);
    }

    return node;
}

Node *BinarySearchTree::search(int id, Node *root)
{
    // cuando el nodo es nulo, quiere decir que alli debe
         // ubicar el valor, en un nuevo nodo
         if (root == nullptr)
         {
             return nullptr;
         }
         else if (root->data->id == id)
         {
            return root;
         }
         // si el valor es mayor, llama recursivamente a insertar en el hijo
         // derecho
         else if (root->data->id < id)
         {
            return search(id, root->right);
         }
         // en caso contrario, va al lado izquierdo
         else //(nodo.dato >= valor)
         {
            return search(id, root->left);
         }
}

int BinarySearchTree::nodeCounter(Node *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    else {
        return 1+nodeCounter(node->right)+nodeCounter(node->left);
    }
}

int BinarySearchTree::getHeight(Node *node)
{
    //este es el resultado
    int height = 0;

    //referencias a los hijos
    Node *r_leftS;
    Node *r_rightS;

    //resultado de las alturas de los hijos
    int left_height = 0;
    int right_height = 0;

    if (node != nullptr)
    {
        //inicia en 1 para contar la raiz
        height = 1;

        r_leftS = node->left;
        r_rightS = node->right;

        //si ninguno de los hijos es nulo
        if (r_leftS != nullptr && r_rightS != nullptr)
        {
            //obtiene la altura de los hijos
            left_height = getHeight(r_leftS);
            right_height = getHeight(r_rightS);

            //suma la mayor altura entre las 2 para determinar el mayor nivel
            if (left_height >= right_height)
            {
                height += left_height;
            }
            else {
                height += right_height;
            }
        }
        //si el hijo derecho es nulo solo suma la altura del hijo derecho
        else if (r_leftS != nullptr && r_rightS == nullptr)
        {
            height += getHeight(r_leftS);
        }

        //si el hijo izquierdo es nulo solo suma la altura del hijo derecho
        else if (r_leftS == nullptr && r_rightS != nullptr)
        {
            height += getHeight(r_rightS);
        }
        //cuando los 2 son nulos se resta el 1 con el que empezo
        else if (r_leftS == nullptr && r_rightS == nullptr)
        {
            height -= 1;
        }
    }
    //retorna el resultado
    return height;
}

int BinarySearchTree::getMax(int a, int b)
{
    if (a>b)
    {
        return a;
    }
    else {
        return b;
    }
}

//Chequea cual es mayor
Node *BinarySearchTree::greater(Node *tree)
{
    if (tree == nullptr)
    {
        return nullptr;
    }
    else if (tree->right == nullptr)
    {
        return tree;
    }
    else {
        return greater(tree->right);
    }
}

Node *BinarySearchTree::removeElement(int id)
{
    root = removeElement(id, root);
    return root;
}

Node *BinarySearchTree::removeElement(int id, Node *tree)
{
    if (tree == nullptr)
    {
        return nullptr;
    }
    else if (id < tree->data->id)
    {
        tree->left = removeElement(id, tree->left);
    }
    else if (id > tree->data->id)
    {
        tree->right = removeElement(id, tree->right);
    }
    else if (tree->right == nullptr && tree->left == nullptr)
    {
        tree = nullptr;
    }
    else if (tree->left == nullptr)
    {
        tree = tree->right;
    }
    else if (tree->right == nullptr)
    {
        tree = tree->left;
    }
    else {
        Node *max = greater(tree->left); //mayor de los menores
        tree->left = removeElement(max->data->id, tree->left);
        tree->data = max->data;
    }
    return tree;
}
