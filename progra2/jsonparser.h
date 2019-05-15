#ifndef JSONPARSER_H
#define JSONPARSER_H
#include <json.hpp>
#include "string.h"

using json = nlohmann::json;
using namespace std;


struct JsonParser
{
    JsonParser(string names[], string lastNames[],string jobs[],string religions[],string countries[]);
    json file;
};

#endif // JSONPARSER_H
