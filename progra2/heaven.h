#ifndef HEAVEN_H
#define HEAVEN_H
#include "hash.h"
#include "heaventree.h"

using namespace std;

struct Heaven
{
    Heaven();
    Hash heavenTable;
    HeavenTree *angels = new HeavenTree();
};

#endif // HEAVEN_H
