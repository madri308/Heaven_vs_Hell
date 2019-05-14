#ifndef JSONPARSER_H
#define JSONPARSER_H
#include <json.hpp>
#include "string.h"

using json = nlohmann::json;
using namespace std;


class jsonParser
{
public:
    jsonParser();
    json file;
};

#endif // JSONPARSER_H
