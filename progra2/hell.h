#ifndef HELL_H
#define HELL_H
#include "demon.h"

struct Hell
{
public:
    Hell();
    Demon *demons[7];

    void heapify(int arr[], int n, int i);
    void heapSort(int arr[], int n);
    void printArray(int arr[], int n);
};

#endif // HELL_H
