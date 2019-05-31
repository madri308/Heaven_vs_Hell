#ifndef NODOCIELO_H
#define NODOCIELO_H
#include "string"
using namespace std;

struct NodoCielo
{
    NodoCielo(string type);
    string type;
    NodoCielo *leftChild;
    NodoCielo *middleChild;
    NodoCielo *rightChild;
    int height;
};

#endif // NODOCIELO_H
