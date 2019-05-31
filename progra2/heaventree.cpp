#include "heaventree.h"

HeavenTree::HeavenTree()
{
    root = new NodoCielo("Dios");
    root->leftChild = new NodoCielo("Serafines");
    root->middleChild = new NodoCielo("Querubines");
    root->rightChild = new NodoCielo("Tronos");
}
