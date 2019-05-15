#include "doublelist.h"
#include "node.h"

DoubleList::DoubleList()
{

}

void DoubleList::add(Human *human)
{
    Node *node = new Node(human);
    if(first == nullptr){
        first = node;
    }else{
        Node *temp = first;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = node;
        node->prev = temp;
    }
    this->quantity++;
}
