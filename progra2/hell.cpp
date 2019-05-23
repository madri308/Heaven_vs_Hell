#include "hell.h"
#include "string"
#include "iostream"
#include "demon.h"
Hell::Hell()
{
    string demonInfo[7][2] = {
        {"Lucifer","Orgullo"},
        {"Belcebú","Envidia"},
        {"Satán","Ira"},
        {"Abadón","Pereza"},
        {"Mammón","Codicia"},
        {"Belfegor","Glotoneria"},
        {"Asmodeo","Lujuria"}};

    for(int d = 0 ; d < 7 ; d++){
        Demon *newDemon = new Demon(demonInfo[d][0],demonInfo[d][1]);
        this->demons[d] = newDemon;
    }
}
