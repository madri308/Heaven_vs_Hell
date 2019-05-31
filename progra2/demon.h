#ifndef DEMON_H
#define DEMON_H
#include "string"
#include "node.h"
#include "doublelist.h"
#include "minheap.h"
#include "limits.h"

using namespace std;

struct Demon
{
    Demon(QString name,QString sin,QString desc,QString image,int n);
    Demon();
    void condemn(DoubleList people);
    void insertToHeap(AVLTree *tree);

    QString name;
    QString sin;
    QString image;
    QString desc;
    int n = 0;      //Se utiliza para saber la posicion de su pecado.
    MinHeap *heap = new MinHeap();

};

#endif // DEMON_H
