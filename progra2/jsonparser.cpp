#include "jsonparser.h"
#include "iostream"
#include "string.h"
#include <fstream>
#include <json.hpp>


using json = nlohmann::json;
using namespace std;

jsonParser::jsonParser(){
    std::ifstream i("C:/Users/Esteban Madrigal/Documents/GitHub/Heaven_vs_Hell/progra2/data.json");
    i >> file;
}
