#include "human.h"

Human::Human(int id, string name, string surname, string country, string religion, string job, string email,int childrens,string sins[3][7],string goodDeeds[3][7])
{
    this->id = id;
    this->name = name;
    this->surname = surname;
    this->country = country;
    this->religion = religion;
    this->email = email;
    this->job = job;
    QDateTime t = QDateTime::currentDateTime ();
    QString b = t.toString("yyyy-MM-dd  HH:mm:ss");
    this->birth = b;
    //this->sins = sins[3][7];
}
