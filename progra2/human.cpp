#include "human.h"

Human::Human(int i, string n, string s, string c, string r, string e, string j)
{
    id = i;
    name = n;
    surname = s;
    country = c;
    religion = r;
    email = e;
    job = j;
    QDateTime t = QDateTime::currentDateTime ();
    QString b = t.toString("yyyy-MM-dd  HH:mm:ss");
    birth = b;
    sins = new string[3][7];


}
