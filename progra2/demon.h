#ifndef DEMON_H
#define DEMON_H
#include "string"
#include "node.h"
#include "doublelist.h"

using namespace std;

struct Demon
{
public:
    Demon(QString name,QString sin,QString desc,QString image);
    Demon();
    void condemn(DoubleList people);
    void heapify(vector<Node*>arr, int n, int i);
    void heapSort(vector<Node*>arr, int n);

    vector<Node*>heap;
    QString name;
    QString sin;
    QString image;
    QString desc;

};

#endif // DEMON_H
