#include "human.h"
#include "iostream"



using namespace std;
Human::Human(int id, string name, string surname, string country, string religion, string job,int childrens,char* dt)
{
    this->id = id;
    this->name = name;
    this->surname = surname;
    this->country = country;
    this->religion = religion;
    this->job = job;
    this->childCount = childrens;
    this->birth = dt;
}



Human::Human(){}

