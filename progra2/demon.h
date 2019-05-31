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
public:
    Demon(QString name,QString sin,QString desc,QString image,int n);
    Demon();
    void condemn(DoubleList people);
    void insertToHeap();

    MinHeap heap(INT_MAX);
    QString name;
    QString sin;
    QString image;
    QString desc;
    int n = 0;      //Se utiliza para saber la posicion de su pecado.

};

#endif // DEMON_H
