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
        while (i != 0 && harr[parent(i)] > harr[i])
        {
           swap(harr[i], harr[parent(i)]);
           i = parent(i);
        }
}

AVLTree* MinHeap::getMin() {
    return harr[0];
}

void MinHeap::insertKey(AVLTree *tree)
{
    if (heapSize == capacity){
        std::cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    heapSize++;
    int pos = heapSize - 1;
    harr[pos] = tree;

    // Fix the min heap property if it is violated
    while (pos != 0 && harr[parent(pos)] > harr[pos])
    {
       swap(harr[pos], harr[parent(pos)]);
       pos = parent(pos);
    }
}
void MinHeap::swap(AVLTree *x, AVLTree *y)
{
    AVLTree temp = *x;
    *x = *y;
    *y = temp;
}
