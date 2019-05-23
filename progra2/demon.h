#ifndef DEMON_H
#define DEMON_H
#include "string"
using namespace std;

struct Demon
{
public:
    Demon(string name,string sin);
    Demon();
    void condemn();

    string name;
    string sin;
};

#endif // DEMON_H
