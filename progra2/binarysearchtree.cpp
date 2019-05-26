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
        node->next = insert(human,node->next);
    }
    else if(node->data->id >= human->id)
    {
        node->prev = insert(human, node->prev);
    }

    return node;
}

Node *BinarySearchTree::search(int id, Node *root)
{
    // cuando el nodo es nulo, quiere decir que all� debe
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
            return search(id, root->next);
         }
         // en caso contrario, va al lado izquierdo
         else //(nodo.dato >= valor)
         {
            return search(id, root->prev);
         }
}

int BinarySearchTree::nodeCounter(Node *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    else {
        return 1+nodeCounter(node->next)+nodeCounter(node->prev);
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

        r_leftS = node->prev;
        r_rightS = node->next;

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
    else if (tree->next == nullptr)
    {
        return tree;
    }
    else {
        return greater(tree->next);
    }
}

Node *BinarySearchTree::removeElement(Human *human)
{
    root = removeElement(human, root);
    return root;
}

Node *BinarySearchTree::removeElement(Human *human, Node *tree)
{
    if (tree == nullptr)
    {
        return nullptr;
    }
    else if (human->id < tree->data->id)
    {
        tree->prev = removeElement(human, tree->prev);
    }
    else if (human->id > tree->data->id)
    {
        tree->next = removeElement(human, tree->next);
    }
    else if (tree->next == nullptr && tree->prev == nullptr)
    {
        tree = nullptr;
    }
    else if (tree->prev == nullptr)
    {
        tree = tree->next;
    }
    else if (tree->next == nullptr)
    {
        tree = tree->prev;
    }
    else {
        Node *max = greater(tree->prev); //mayor de los menores
        tree->prev = removeElement(max->data, tree->prev);
        tree->data = max->data;
    }
    return tree;
}
