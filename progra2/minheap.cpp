#include "minheap.h"
#include "limits.h"
#include "iostream"
#include "avltree.h"

MinHeap::MinHeap(){
    heapSize = 0;
    capacity = 10000000;
}
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heapSize && harr[l] < harr[i])
        smallest = l;
    if (r < heapSize && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}

int MinHeap::parent(int i) {
    return (i-1)/2;
}
int MinHeap::right(int i) {
    return (2*i + 2);
}
int MinHeap::left(int i){
    return (2*i + 1);
}
AVLTree* MinHeap::extractMin()
{
    if (heapSize == 1)
    {
        heapSize--;
        return harr[0];
    }

    // Store the minimum value, and remove it from heap
    AVLTree* root = harr[0];
    harr[0] = harr[heapSize-1];
    heapSize--;
    MinHeapify(0);

    return root;
}

void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i]->sins = new_val;
    while (i != 0 && harr[parent(i)]->sins > harr[i]->sins)
    {
       swap(harr[i], harr[parent(i)]);
       i = parent(i);
    }
}

AVLTree* MinHeap::getMin() {
    return harr[0];
}

void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}

void MinHeap::insertKey(AVLTree *tree)
{
    if (heapSize == capacity)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    // First insert the new key at the end
    heapSize++;
    int i = heapSize - 1;
    harr[i] = tree;

    // Fix the min heap property if it is violated
    while (i != 0 && harr[parent(i)]->sins > harr[i]->sins)
    {
       swap(harr[i], harr[parent(i)]);
       i = parent(i);
    }
}
void MinHeap::swap(AVLTree *x, AVLTree *y)
{
    AVLTree temp = *x;
    *x = *y;
    *y = temp;
}

AVLTree *MinHeap::search(Human *human)
{
    for(AVLTree *fam:this->harr){
        if(human->family->name == fam->name){
            return fam;
        }
    }
    return nullptr;
}
