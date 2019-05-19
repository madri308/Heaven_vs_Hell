#include "human.h"
#include "iostream"



using namespace std;
Human::Human(int id, string name, string surname, string country, string religion, string job,size_t childrens,char* dt)
{
    this->id = id;
    this->name = name;
    this->surname = surname;
    this->country = country;
    this->religion = religion;
    this->job = job;
    this->childrens.resize(childrens);
    this->birth = dt;
}

void Human::showInfo()
{
    cout<<this->id<<endl;
    cout<<""<<endl;
    cout<<this->name<<endl;
    cout<<this->surname<<endl;
    cout<<this->country<<endl;
    cout<<this->religion<<endl;
    cout<<this->job<<endl;
    cout<<""<<endl;
    for(int x = 0; x < 7 ; x++){
        cout<<this->sins[x][0]+":"+sins[x][1]+" ";
    }
    cout<<""<<endl;
    for(int x = 0; x < 7 ; x++){
        cout<<this->goodDeeds[x][0]+":"+goodDeeds[x][1]+" ";
    }
    cout<<""<<endl;
    cout<<"hijos: "+to_string(this->childrens.size())<<endl;
    cout<<this->birth;
}
