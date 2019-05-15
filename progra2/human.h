#ifndef HUMAN_H
#define HUMAN_H
#include <string>
#include <QDateTime>

using namespace std;

struct Human
{
    int id;
    string name;
    string surname;
    string country;
    string religion;
    string email;
    string job;
    QString birth;
    string sins[3][7];
    string goodDeeds[3][7];

    Human(int id, string name, string surname, string country, string religion, string job, string email,int childrens,string sins[3][7],string goodDeeds[3][7]);
};

#endif // HUMAN_H
