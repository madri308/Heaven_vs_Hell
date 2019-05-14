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
    string sins[];
    string goodDeeds[];

    Human(int i, string n, string s, string c, string r, string e, string j);
};

#endif // HUMAN_H
