#include "heaventree.h"
#include "angel.h"
#include <ctime>
#include <chrono>
#include "famsinswindow.h"

HeavenTree::HeavenTree()
{
    root = new Angel("Dios",0,0,"middle");

    root->leftChild = new Angel("Serafines",0,1,"left");
    root->middleChild = new Angel("Querubines",1,1,"middle");
    root->rightChild = new Angel("Tronos",2,1,"right");

    Angel *used = root->leftChild;
    srand(time(NULL));
    for(int a = 0 ; a < 3 ; a++){
        if(a == 1){
            used = root->middleChild;
        }else if(a == 2){
            used = root->rightChild;
        }
        int pName1 = rand() % 10;
        int pName2 = rand() % 10;
        int pName3 = rand() % 10;

        Angel *leftChild = new Angel(this->angels[pName1],ver,2,"left");
        Angel *middleChild = new Angel(this->angels[pName2],ver+1,2,"middle");
        Angel *rightChild = new Angel(this->angels[pName3],ver+2,2,"right");
        ver = ver+3;
        used->leftChild = leftChild;
        used->middleChild = middleChild;
        used->rightChild = rightChild;
    }
}

void HeavenTree::generateAngels()
{
    this->ver = 0;
    generateAngels(this->root,0);
    this->level = this->level+1;
}

void HeavenTree::generateAngels(Angel *root,int ver)
{
    if(root != nullptr){
        if(root->gen == this->level){
            int pName1 = rand() % 10;
            int pName2 = rand() % 10;
            int pName3 = rand() % 10;

            Angel *leftChild = new Angel(this->angels[pName1],this->ver,this->level+1,"left");
            Angel *middleChild = new Angel(this->angels[pName2],this->ver+1,this->level+1,"middle");
            Angel *rightChild = new Angel(this->angels[pName3],this->ver+2,this->level+1,"right");

            this->quant = this->quant+3;
            this->ver = this->ver+3;

            root->leftChild = leftChild;
            root->middleChild = middleChild;
            root->rightChild = rightChild;
        }
        generateAngels(root->leftChild,ver);
        generateAngels(root->middleChild,ver);
        generateAngels(root->rightChild,ver);
    }
}

void HeavenTree::showAngels()
{
    FamSinsWindow *w = new FamSinsWindow(nullptr);
    int c = 0;
    showAngels(this->root, w,c);
    w->setWindowTitle(QString::fromStdString("Angels" + to_string(this->quant)));
    w->show();
}

void HeavenTree::showAngels(Angel *root,FamSinsWindow *w, int c)
{
    if(root != nullptr){
        w->list->addItem(QString::fromStdString("Nombre: "+root->name));
        w->list->addItem(QString::fromStdString("Generacion: "+to_string(root->gen)));
        w->list->addItem(QString::fromStdString("Version: "+to_string(root->ver)));
        w->list->addItem("___________________");
        c = c+1;
        showAngels(root->leftChild,w,c);
        showAngels(root->middleChild,w,c);
        showAngels(root->rightChild,w,c);
    }
}
