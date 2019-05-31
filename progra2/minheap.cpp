#include "minheap.h"
#include "limits.h"
#include "iostream"
#include "avltree.h"

MinHeap::MinHeap(int cap){
    heapSize = 0;
    capacity = cap;
    AVLTree *harr[cap];
}

MinHeap::MinHeap(){}
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
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

int MinHeap::parent(int i) {
    return (i-1)/2;
}
int MinHeap::right(int i) {
    return (2*i + 2);
}
int MinHeap::extractMin()
{
    if (heapSize <= 0)
        return INT_MAX;
    if (heapSize == 1)
    {
        heapSize--;
        return harr[0];
    }

    // Store the minimum value, and remove it from heap
    int root = harr[0];
    harr[0] = harr[heapSize-1];
    heapSize--;
    MinHeapify(0);

    return root;
}

void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i] = new_val;
        while (i != 0 && harr[parent(i)] > harr[i])
        {
           swap(&harr[i], &harr[parent(i)]);
           i = parent(i);
        }
}

int MinHeap::getMin() {
    return harr[0];
}

void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}

void MinHeap::insertKey(int k)
{
    if (heapSize == capacity){
        std::cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    heapSize++;
    int pos = heapSize - 1;
    harr[pos] = k;

    // Fix the min heap property if it is violated
    while (pos != 0 && harr[parent(pos)] > harr[pos])
    {
       swap(&harr[pos], &harr[parent(pos)]);
       pos = parent(pos);
    }
}
void MinHeap::swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
