#ifndef ANGEL_H
#define ANGEL_H
#include "iostream"
#include "human.h"
using namespace std;

struct WorldWindow;
struct Angel
{
    Angel(string name, int ver, int gen, string type);
    string name;    //es uno de los nomres de la lista de ángeles
    int ver;        //es el número de ese angel en esa generación
    int gen;        //es el nivel del árbol
    Human human;	//es un puntero al humano que fue salvado por el ángel.
    string type;

    Angel *leftChild = nullptr;
    Angel *middleChild = nullptr;
    Angel *rightChild = nullptr;

    void save(WorldWindow *world);
};

#endif // ANGEL_H
