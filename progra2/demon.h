#ifndef DEMON_H
#define DEMON_H
#include "string"
#include "node.h"
#include "doublelist.h"
#include "minheap.h"
#include "limits.h"
#include <QFile>

using namespace std;
struct World;

struct Demon
{
    Demon(QString name,QString sin,QString desc,QString image,int n);
    Demon();
    void condemn(World world);
    void insertToHeap(AVLTree *tree);
    void writeToFile();

    QString name;
    QString sin;
    QString image;
    QString desc;
    int n = 0;      //Se utiliza para saber la posicion de su pecado.
    MinHeap *heap = new MinHeap();
    int count = 0;


};

#endif // DEMON_H
