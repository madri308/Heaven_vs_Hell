#ifndef HEAVEN_H
#define HEAVEN_H
#include "hash.h"
#include "heaventree.h"

using namespace std;
struct WorldWindow;
struct Heaven
{
    Heaven();
    Hash *heavenTable = new Hash();
    HeavenTree *angels = new HeavenTree();
    WorldWindow *world;
};

#endif // HEAVEN_H
