#ifndef HUMAN_H
#define HUMAN_H
#include "string"
#include "QDateTime"
#include "vector"
#include "array"
struct BinarySearchTree;
using namespace std;

struct Human
{
    int id;
    string name;
    string surname;
    string country;
    string religion;
    string job;
    BinarySearchTree *family = nullptr;

    string sins[7][2] = {{"Lujuria","0"},{"Gula","0"},{"Avaricia","0"},{"Pereza","0"},{"Ira","0"},{"Envidia","0"},{"Soberbia","0"}};
    string goodDeeds[7][2] = {{"Castidad","0"},{"Ayuno","0"},{"Donacion","0"},{"Diligencia","0"},{"Calma","0"},{"Solidaridad","0"},{"Humildad","0"}};
    vector<Human> childrens;
    char *birth;
    Human(int id, string name, string surname, string country, string religion, string job, size_t childrens,char* dt);
    void showInfo();
};

#endif // HUMAN_H
