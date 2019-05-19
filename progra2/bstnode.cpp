#include "bstnode.h"
#include "human.h"

using namespace std;

BSTNode::BSTNode(Human *data)
{
    this->data = data;
    leftSon = rightSon = nullptr;
}
