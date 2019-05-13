#ifndef JSONPARSER_H
#define JSONPARSER_H
#include <json.hpp>

using json = nlohmann::json;

class jsonParser
{
public:
    jsonParser();
    json file;
};

#endif // JSONPARSER_H
