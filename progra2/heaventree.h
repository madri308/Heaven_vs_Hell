#ifndef HEAVENTREE_H
#define HEAVENTREE_H
#include "angel.h"
#include "famsinswindow.h"

using namespace std;

struct HeavenTree
{
    HeavenTree();
    Angel *root;
    string angels[10] = {"Miguel", "Nuriel", "Aniel", "Rafael","Gabriel","Shamsiel","Raguel","Uriel","Azrael","Sasiel"};
    int level = 2;
    void generateAngels();
    void generateAngels(Angel* root,int ver);
    void showAngels();
    void showAngels(Angel* root,FamSinsWindow *w,int c);
    int quant = 13;
    int ver = 0;
};

#endif // HEAVENTREE_H
