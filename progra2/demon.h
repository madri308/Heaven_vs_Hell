#ifndef DEMON_H
#define DEMON_H
#include "string"

struct Demon
{
public:
    Demon(std::string name,std::string sin);
    Demon();
    void condemn();

    std::string name;
    std::string sin;
};

#endif // DEMON_H
