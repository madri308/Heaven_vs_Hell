#ifndef DEMON_H
#define DEMON_H
#include "string"
#include "node.h"
#include "doublelist.h"

using namespace std;

struct Demon
{
public:
    Demon(string name,string sin);
    Demon();
    void condemn(DoubleList people);

    string name;
    string sin;

};

#endif // DEMON_H
