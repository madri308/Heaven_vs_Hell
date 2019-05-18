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


bool DoubleList::isEmpty()
{
    if (first == nullptr)
    {
        return true;
    }
    else{
        return false;
    }
}

bool DoubleList::exist(int id)
{
    Node *temp = first;
    while(temp){
        if(temp->data->id == id){
            return true;
        }else{
            temp = temp->next;
        }
    }
    return false;
}


