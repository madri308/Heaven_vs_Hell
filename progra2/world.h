#ifndef WORLD_H
#define WORLD_H
#include "string.h"
#include "doublelist.h"
#include "hell.h"
#include "binarysearchtree.h"

using namespace std;


struct World
{
    World();
    void generatePeople(int peopleQuan);
    string* top10SinList();
    string *top5list();
    //Datos para generar personas.
    string names[1000];
    string lastnames[1000];
    string religions[10];
    string countries[100][3];
    string jobs[50];

    DoubleList peolpe;

    BinarySearchTree *peopleTree;
};

#endif // WORLD_H
