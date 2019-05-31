#include "heaventree.h"

HeavenTree::HeavenTree()
{
    root = new HeavenNode("Dios");
    root->leftChild = new HeavenNode("Serafines");
    root->middleChild = new HeavenNode("Querubines");
    root->rightChild = new HeavenNode("Tronos");
}
