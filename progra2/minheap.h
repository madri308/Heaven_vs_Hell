#ifndef MINHEAP_H
#define MINHEAP_H
#include "avltree.h"

struct MinHeap
{
    MinHeap();
    int capacity; // maximum possible size of min heap
    int heapSize; // Current number of elements in min heap

    void MinHeapify(int m);
    int parent(int i);
    int left(int i);
    int right(int i);
    AVLTree* extractMin(); //SACA ROOT
    void decreaseKey(int i, int new_val);// Decreases key value of key at index i to new_val
    AVLTree* getMin();    // Returns the minimum key (key at root) from min heap
    void deleteKey(int i);
    void insertKey(AVLTree *k);
    void swap(AVLTree *x, AVLTree *y);
    AVLTree *harr[1000000]; // pointer to array of elements in heap
};

#endif // MINHEAP_H
