#ifndef MINHEAP_H
#define MINHEAP_H


struct MinHeap
{
public:

    MinHeap(int capacity);
    MinHeap();
    int *harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int heapSize; // Current number of elements in min heap

    void MinHeapify(int );
    int parent(int i);
    int left(int i);
    int right(int i);
    int extractMin(); //SACA ROOT
    void decreaseKey(int i, int new_val);// Decreases key value of key at index i to new_val
    int getMin();    // Returns the minimum key (key at root) from min heap
    void deleteKey(int i);
    void insertKey(int k);
    void swap(int *x, int *y);
};

#endif // MINHEAP_H
