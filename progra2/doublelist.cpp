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
Node* DoubleList::get(int id)
{
    Node *temp = first;
    while(temp){
        if(temp->data->id == id){
            return temp;
        }else{
            temp = temp->next;
        }
    }
    return nullptr;
}
void DoubleList::remove(int id)
{
    Node *toRemove = get(id);

    if (first == toRemove)
    {
        first = first->next;
        first->prev->next = nullptr;
        first->prev = nullptr;
    }
    else if(toRemove->next == nullptr)
    {
        toRemove->prev->next = nullptr;
        toRemove->prev = nullptr;
    }
    else
    {
        Node *tmp = toRemove->prev;
        tmp->next = toRemove->next;
        toRemove->next = nullptr;
        tmp->next->prev = toRemove->prev;
        toRemove->prev = nullptr;
    }
  }
