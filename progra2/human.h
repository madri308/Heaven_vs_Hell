#ifndef HUMAN_H
#define HUMAN_H
#include "string"
#include "QDateTime"
#include "vector"
#include "array"
using namespace std;
struct AVLTree;
struct Human
{
    int id;
    string name;
    string surname;
    string country;
    string continent;
    string religion;
    string job;
    int childCount;
    int totalSins = 0;
    int totalGD = 0;
    AVLTree *family = nullptr;
    Human *parent = nullptr;

    string sins[7][2] = {{"Lujuria","0"},{"Glotoneria","0"},{"Codicia","0"},{"Pereza","0"},{"Ira","0"},{"Envidia","0"},{"Orgullo","0"}};
    string goodDeeds[7][2] = {{"Castidad","0"},{"Ayuno","0"},{"Donacion","0"},{"Diligencia","0"},{"Calma","0"},{"Solidaridad","0"},{"Humildad","0"}};
    Human *child[8] = {nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr};
    char *birth;
    Human(int id, string name, string surname, string country, string religion, string job, int childrens,char* dt, string continent);
    void showInfo();
    Human();
};

#endif // HUMAN_H
