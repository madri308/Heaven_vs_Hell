#ifndef HUMAN_H
#define HUMAN_H
#include "string"
#include "QDateTime"
#include "binarysearchtree.h"
#include "vector"

struct Human
{
    int id;
    std::string name;
    std::string surname;
    std::string country;
    std::string religion;
    std::string job;
    BinarySearchTree *family = nullptr;

    std::string sins[7][2] = {{"Lujuria","0"},{"Gula","0"},{"Avaricia","0"},{"Pereza","0"},{"Ira","0"},{"Envidia","0"},{"Soberbia","0"}};
    std::string goodDeeds[7][2] = {{"Castidad","0"},{"Ayuno","0"},{"Donacion","0"},{"Diligencia","0"},{"Calma","0"},{"Solidaridad","0"},{"Humildad","0"}};
    std::vector<Human> childrens;
    char *birth;
    Human(int id, std::string name, std::string surname, std::string country, std::string religion, std::string job, size_t childrens,char* dt);
    void showInfo();
    Human();
};

#endif // HUMAN_H
