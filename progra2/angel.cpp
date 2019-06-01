#include "angel.h"
#include "heaven.h"
#include "worldwindow.h"

Angel::Angel(string name, int ver, int gen,string type)
{
    this->name = name;
    this->ver = ver;
    this->gen = gen;
}
Node* getDiference(Node *root){
    if(root){
        int dif = root->data->totalGD - root->data->totalSins;
        if (dif<0){
            return root;
        }
        getDiference(root->left);
        getDiference(root->right);
    }
    return nullptr;
}
void Angel::save(WorldWindow *world)
{
    for(Demon *demon:world->hell->demons){
        for(int fam = 0 ; fam < demon->heap->heapSize ; fam++){
            AVLTree *family = demon->heap->harr[fam];
            Node *toSave = getDiference(family->root);
            if(toSave){
                family->removeElement(toSave->data->id);
                world->heaven->heavenTable->insert(toSave->data);
            }
        }
    }
}

